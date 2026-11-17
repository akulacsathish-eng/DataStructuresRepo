#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int recursiveCalls = 0;

int recursiveRoute(const int grid[][MAX_SIZE], int rows, int cols,
                   int row, int col) {
    ++recursiveCalls;

    if (row == rows - 1 && col == cols - 1) {
        return grid[row][col];
    }

    if (row == rows - 1) {
        return grid[row][col] + recursiveRoute(grid, rows, cols, row, col + 1);
    }

    if (col == cols - 1) {
        return grid[row][col] + recursiveRoute(grid, rows, cols, row + 1, col);
    }

    int rightCost = recursiveRoute(grid, rows, cols, row, col + 1);
    int downCost = recursiveRoute(grid, rows, cols, row + 1, col);

    return grid[row][col] + min(rightCost, downCost);
}

int main() {
    int rows = 2;
    int cols = 2;

    int grid[MAX_SIZE][MAX_SIZE] = {
        {1, 2},
        {3, 4}
    };

    int cost = recursiveRoute(grid, rows, cols, 0, 0);

    cout << "Minimum cost: " << cost << endl;
    cout << "Recursive calls: " << recursiveCalls << endl;

    return 0;
}
