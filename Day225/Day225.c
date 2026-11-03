//Question There are N workers and N jobs. Each worker must be assigned exactly one job, and each job must be assigned to
// exactly one worker.
//You are given a cost matrix where cost[i][j] represents the cost of assigning worker i to job j.
//Find the minimum total assignment cost using the Branch and Bound technique.

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int n;
int cost[10][10];
int minCost = INT_MAX;
bool used[10];

// Calculate lower bound
int bound(int level, int currentCost) {
    int lower = currentCost;

    for (int i = level; i < n; i++) {
        int minimum = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!used[j] && cost[i][j] < minimum) {
                minimum = cost[i][j];
            }
        }

        lower += minimum;
    }

    return lower;
}

// Branch and Bound
void assignment(int level, int currentCost) {
    if (level == n) {
        if (currentCost < minCost)
            minCost = currentCost;

        return;
    }

    if (bound(level, currentCost) >= minCost)
        return;

    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            used[j] = true;

            assignment(level + 1,
                       currentCost + cost[level][j]);

            used[j] = false;
        }
    }
}

int main() {
    printf("Enter number of workers: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    assignment(0, 0);

    printf("Minimum assignment cost = %d\n", minCost);

    return 0;
}
