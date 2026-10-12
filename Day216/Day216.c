//Question You are given n items, each with a weight and a value. A knapsack has a maximum capacity W.
//Find the maximum total value you can carry without exceeding the capacity. Each item can be selected at most once.

#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];

    printf("Enter weights: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter values: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &value[i]);

    printf("Enter capacity: ");
    scanf("%d", &W);

    int dp[n + 1][W + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else
                dp[i][w] = 0;
        }
    }

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {

            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Maximum value = %d\n", dp[n][W]);

    return 0;
}
