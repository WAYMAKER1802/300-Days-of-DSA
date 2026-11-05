//Question : Given an integer array nums, return the length of the longest strictly increasing subsequence.
//A subsequence is formed by deleting some or no elements without changing the order of the remaining elements.
int lengthOfLIS(int* nums, int numsSize) {
    int dp[numsSize];
    int maxLen = 1;

    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
    }

    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        if (dp[i] > maxLen) {
            maxLen = dp[i];
        }
    }

    return maxLen;
}