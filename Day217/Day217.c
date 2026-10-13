//Question - You are climbing a staircase with n steps. You can climb either 1 step or 2 steps at a time.
//Find the total number of distinct ways to reach the top.

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of stairs: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of ways = 0\n");
        return 0;
    }

    int dp[n + 1];

    dp[1] = 1;

    if (n >= 2)
        dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    printf("Number of ways = %d\n", dp[n]);

    return 0;
}
