//Question : Given an array nums of length n, an element at 1-based index i is special if n % i == 0.
// Return the sum of squares of all special elements.
#include <stdio.h>

int sumOfSquares(int nums[], int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++) {

        // Check if index i divides n
        if (n % i == 0) {
            sum += nums[i - 1] * nums[i - 1];
        }
    }

    return sum;
}

int main() {
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Sum of squares = %d\n", sumOfSquares(nums, n));

    return 0;
}