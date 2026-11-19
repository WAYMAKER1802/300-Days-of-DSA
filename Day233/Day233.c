//Question-You are given an m x n grid filled with non-negative numbers. Find a path from the top-left corner to the
//bottom-right corner that minimizes the sum of all numbers along its path.
//You can only move right or down at any point. Return the minimum path sum.

#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minPathSum(int grid[100][100], int m, int n) {
    int dp[100][100];

    dp[0][0] = grid[0][0];

    // Initialize first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Initialize first column
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill remaining DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] +
                       min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int m, n;
    int grid[100][100];

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter grid elements:\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Minimum Path Sum = %d\n",
           minPathSum(grid, m, n));

    return 0;
}
