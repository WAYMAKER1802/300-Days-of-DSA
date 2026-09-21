//Question - Given a positive integer array nums and k, you can remove a prefix and/or suffix, leaving any non-empty contiguous subarray.
//For every possible remaining subarray, calculate its product % k.
//Return result[x] = number of subarrays whose product leaves remainder x.
#include <stdio.h>
#include <stdlib.h>

long long* resultArray(int nums[], int n, int k) {

    long long* result = calloc(k, sizeof(long long));
    long long* dp = calloc(k, sizeof(long long));
    long long* newdp = calloc(k, sizeof(long long));

    for (int i = 0; i < n; i++) {

        // Reset
        for (int j = 0; j < k; j++) {
            newdp[j] = 0;
        }

        int value = nums[i] % k;

        // Subarray containing only nums[i]
        newdp[value]++;

        // Extend previous subarrays
        for (int r = 0; r < k; r++) {

            if (dp[r] > 0) {

                int newRemainder = (r * value) % k;

                newdp[newRemainder] += dp[r];
            }
        }

        // Add to final answer
        for (int r = 0; r < k; r++) {
            result[r] += newdp[r];
        }

        // Copy newdp to dp
        for (int r = 0; r < k; r++) {
            dp[r] = newdp[r];
        }
    }

    free(dp);
    free(newdp);

    return result;
}

int main() {

    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    long long* result = resultArray(nums, n, k);

    printf("Result: [");

    for (int i = 0; i < k; i++) {
        printf("%lld", result[i]);

        if (i < k - 1)
            printf(", ");
    }

    printf("]\n");

    free(result);

    return 0;
}