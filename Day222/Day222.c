//Question: Maximum Profit in a Knapsack
//You are given n items. Each item has a weight and a profit. A bag has a maximum weight capacity W.
//Select items to maximize total profit without exceeding the bag's capacity.
//Each item can either be selected completely or not selected at all.
//Use Backtracking with a Bounding Function (Branch and Bound) to find the maximum profit
#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int profit;
    double ratio;
};

struct Item items[100];
int n, W;
int maxProfit = 0;

// Sort items by profit/weight ratio
void sortItems() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Calculate upper bound
double bound(int level, int weight, int profit) {
    if (weight >= W)
        return profit;

    double result = profit;
    int totalWeight = weight;

    for (int i = level; i < n; i++) {
        if (totalWeight + items[i].weight <= W) {
            totalWeight += items[i].weight;
            result += items[i].profit;
        }
        else {
            int remaining = W - totalWeight;
            result += remaining * items[i].ratio;
            break;
        }
    }

    return result;
}

// Backtracking with bounding
void knapsack(int level, int weight, int profit) {
    if (weight <= W && profit > maxProfit)
        maxProfit = profit;

    if (level == n)
        return;

    if (bound(level, weight, profit) <= maxProfit)
        return;

    // Include current item
    if (weight + items[level].weight <= W) {
        knapsack(level + 1,
                 weight + items[level].weight,
                 profit + items[level].profit);
    }

    // Exclude current item
    knapsack(level + 1, weight, profit);
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    printf("Enter weight and profit of each item:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight,
                       &items[i].profit);

        items[i].ratio =
            (double)items[i].profit / items[i].weight;
    }

    sortItems();

    knapsack(0, 0, 0);

    printf("Maximum profit = %d\n", maxProfit);

    return 0;
}