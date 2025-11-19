#include <stdio.h>

int binom(int n, int k) {
    int C[n+1][k+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {

            if (j == 0 || j == i)
                C[i][j] = 1;

            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C[n][k];
}

int main() {
    printf("%d\n", binom(5,2));  // Output: 10
    return 0;
}
