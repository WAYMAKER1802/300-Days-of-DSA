//Question- You are a professional robber planning to rob houses arranged in a circle. Each house contains some money.
//The first and last houses are adjacent. You cannot rob two adjacent houses because the security system will alert the police.
//Given an integer array nums, return the maximum amount of money you can rob without alerting the police.

#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Normal House Robber for a given range
int robRange(int nums[], int start, int end) {
    int prev2 = 0;
    int prev1 = 0;

    for (int i = start; i <= end; i++) {
        int current = max(prev1, prev2 + nums[i]);

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int rob(int nums[], int numsSize) {
    if (numsSize == 1)
        return nums[0];

    // Case 1: Exclude last house
    int case1 = robRange(nums, 0, numsSize - 2);

    // Case 2: Exclude first house
    int case2 = robRange(nums, 1, numsSize - 1);

    return max(case1, case2);
}

int main() {
    int n;

    printf("Enter number of houses: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter money in each house: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Maximum money = %d\n", rob(nums, n));

    return 0;
}
