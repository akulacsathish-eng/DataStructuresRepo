#include <stdio.h>

int memo[100][100];

int binom(int n, int k) {
    if (k == 0 || k == n) 
        return 1;

    if (memo[n][k] != -1)
        return memo[n][k];

    memo[n][k] = binom(n-1, k-1) + binom(n-1, k);
    return memo[n][k];
}

int main() {
    // initialize memo array
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            memo[i][j] = -1;

    int n = 5, k = 2;
    printf("C(%d, %d) = %d\n", n, k, binom(n, k));
    return 0;
}
