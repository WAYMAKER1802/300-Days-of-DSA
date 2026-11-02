//Question:Given an array of distinct integers nums, return all the possible permutations. You can return the answer in any order.
//A permutation is an arrangement of all the elements of an array.

#include <stdio.h>
#include <stdbool.h>

int nums[100], path[100];
bool used[100];
int result[1000][100];
int count = 0, n;

void backtrack(int depth) {
    if (depth == n) {
        for (int i = 0; i < n; i++)
            result[count][i] = path[i];

        count++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            path[depth] = nums[i];
            used[i] = true;

            backtrack(depth + 1);

            used[i] = false;
        }
    }
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        used[i] = false;
    }

    backtrack(0);

    printf("\nAll permutations:\n");

    for (int i = 0; i < count; i++) {
        printf("[");
        for (int j = 0; j < n; j++) {
            printf("%d", result[i][j]);
            if (j < n - 1)
                printf(", ");
        }
        printf("]\n");
    }

    return 0;
}
