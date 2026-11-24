//Question: Subsets (LeetCode 78)
//Given an integer array nums containing unique elements, return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. You may return the solution in any order.

#include <stdio.h>

int nums[100];
int subset[100];
int n;

void backtrack(int index, int size) {

    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");

    for (int i = index; i < n; i++) {

        // Choose an element
        subset[size] = nums[i];

        // Explore further
        backtrack(i + 1, size + 1);

        // Backtrack
        // The next iteration overwrites this position
    }
}

int main() {

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("\nAll possible subsets:\n");

    backtrack(0, 0);

    return 0;
}
