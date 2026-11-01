//Question: You are a professional robber planning to rob houses along a street. Each house has a certain amount of money.
//The only restriction is that you cannot rob two adjacent houses because the security system will alert the police.
//Given an integer array nums, return the maximum amount of money you can rob without robbing adjacent houses.

#include <stdio.h>

int rob(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;

    if (numsSize == 1)
        return nums[0];

    int prev2 = nums[0];
    int prev1 = (nums[0] > nums[1]) ? nums[0] : nums[1];

    for (int i = 2; i < numsSize; i++) {
        int current = prev1;
        
        if (prev2 + nums[i] > current)
            current = prev2 + nums[i];

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
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
