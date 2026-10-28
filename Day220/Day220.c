//Question- Place N queens on an N × N chessboard so that no two queens attack each other. No two queens can share the same row, 
//column, or diagonal.
//Write a C program to find and print one valid arrangement of the queens.

#include <stdio.h>
#include <stdlib.h>

int board[20][20];

int isSafe(int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return 0;
    }

    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

int solve(int row, int n) {
    if (row == n)
        return 1;

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 1;

            if (solve(row + 1, n))
                return 1;

            board[row][col] = 0;  // Backtrack
        }
    }

    return 0;
}

int main() {
    int n;

    printf("Enter N (1-20): ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Invalid N\n");
        return 0;
    }

    if (solve(0, n)) {
        printf("One valid arrangement:\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }
    } else {
        printf("No solution exists\n");
    }

    return 0;
}
