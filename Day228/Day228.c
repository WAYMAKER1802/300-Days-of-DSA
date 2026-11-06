//Question: Given an m x n grid of characters and a string word, return true if the word exists in the grid.
//The word can be constructed from letters of sequentially adjacent cells (horizontally or vertically).
//- The same cell cannot be used more than once in a word.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char board[10][10];
char word[100];
int m, n;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool backtrack(int x, int y, int index) {
    if (word[index] == '\0')
        return true;

    if (x < 0 || y < 0 || x >= m || y >= n)
        return false;

    if (board[x][y] != word[index])
        return false;

    char temp = board[x][y];
    board[x][y] = '#';

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (backtrack(nx, ny, index + 1)) {
            board[x][y] = temp;
            return true;
        }
    }

    board[x][y] = temp;
    return false;
}

int main() {
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter board characters:\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &board[i][j]);
        }
    }

    printf("Enter word: ");
    scanf("%99s", word);

    bool found = false;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (backtrack(i, j, 0)) {
                found = true;
                break;
            }
        }

        if (found)
            break;
    }

    if (found)
        printf("Word exists\n");
    else
        printf("Word does not exist\n");

    return 0;
}
