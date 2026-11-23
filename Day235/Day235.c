//Question: Given an integer array nums and an integer k, return the kth largest element in the array.
//Note that it is the kth largest element in sorted order, not the kth distinct element.
//You must solve it without sorting the entire array.

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int nums[], int low, int high) {
    int pivot = nums[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (nums[j] > pivot) {
            swap(&nums[i], &nums[j]);
            i++;
        }
    }

    swap(&nums[i], &nums[high]);

    return i;
}

int quickSelect(int nums[], int low, int high, int k) {
    int pos = partition(nums, low, high);

    if (pos == k)
        return nums[pos];

    if (pos > k)
        return quickSelect(nums, low, pos - 1, k);

    return quickSelect(nums, pos + 1, high, k);
}

int findKthLargest(int nums[], int numsSize, int k) {
    return quickSelect(nums, 0, numsSize - 1, k - 1);
}

int main() {
    int n, k;

    printf("Enter array size: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("Invalid k value\n");
        return 0;
    }

    printf("Kth largest element = %d\n",
           findKthLargest(nums, n, k));

    return 0;
}
