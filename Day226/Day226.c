//Question : You are given an integer array coins representing different denominations of coins and an integer amount 
//representing a total amount of money.
//Return the fewest number of coins needed to make up that amount.
//If the amount cannot be made using any combination of the coins, return -1.
//You may use each coin denomination unlimited times.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int coinChange(int coins[], int n, int amount) {
    int *dp = malloc((amount + 1) * sizeof(int));

    for (int i = 0; i <= amount; i++)
        dp[i] = INT_MAX;

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    int ans = (dp[amount] == INT_MAX) ? -1 : dp[amount];

    free(dp);
    return ans;
}

int main() {
    int n, amount;

    printf("Enter number of coin types: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter coin denominations: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter amount: ");
    scanf("%d", &amount);

    printf("Minimum coins required = %d\n",
           coinChange(coins, n, amount));

    return 0;
}
