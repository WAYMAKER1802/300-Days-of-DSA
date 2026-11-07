//Question : Given an integer array nums, find the contiguous subarray with the largest sum and return its sum.
//A subarray must contain at least one element.

#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxCrossingSum(int arr[], int left, int mid, int right) {
    int sum = 0;
    int leftSum = -1000000000;

    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    int rightSum = -1000000000;

    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubArray(int arr[], int left, int right) {
    if (left == right)
        return arr[left];

    int mid = left + (right - left) / 2;

    int leftMax = maxSubArray(arr, left, mid);
    int rightMax = maxSubArray(arr, mid + 1, right);
    int crossMax = maxCrossingSum(arr, left, mid, right);

    return max(leftMax, max(rightMax, crossMax));
}

int main() {
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Maximum subarray sum = %d\n",
           maxSubArray(arr, 0, n - 1));

    return 0;
}
