//Question - You are given n items, each with a weight and a value, and a knapsack with capacity W.
//Find the maximum total value you can carry without exceeding the knapsack's capacity.
//  Each item can be selected at most once.

#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];

    printf("Enter capacity: ");
    scanf("%d", &W);

    printf("Enter weights: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter values: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &value[i]);

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Maximum value = %d\n", dp[n][W]);

    return 0;
}
