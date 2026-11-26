//Question- A salesperson has to visit n cities exactly once and return to the starting city.
//You are given a cost matrix where cost[i][j] represents the travelling cost from city i to city j.
//Using the Branch and Bound technique, find the minimum cost tour that visits every city exactly once and returns to the
// starting city.

#include <stdio.h>

#define MAX 10
#define INF 999999

int n;
int cost[MAX][MAX];
int visited[MAX];
int path[MAX], bestPath[MAX];
int minCost = INF;

int calculateBound(int current, int level, int currentCost) {
    int bound = currentCost;

    for (int i = 0; i < n; i++) {
        if (!visited[i] || i == 0) {
            int minEdge = INF;

            for (int j = 0; j < n; j++) {
                if (i != j && (!visited[j] || j == 0)) {
                    if (cost[i][j] < minEdge)
                        minEdge = cost[i][j];
                }
            }

            if (minEdge != INF)
                bound += minEdge;
        }
    }

    return bound;
}

void tsp(int current, int level, int currentCost) {

    if (level == n) {
        int total = currentCost + cost[current][0];

        if (total < minCost) {
            minCost = total;

            for (int i = 0; i < n; i++)
                bestPath[i] = path[i];
        }
        return;
    }

    int bound = calculateBound(current, level, currentCost);

    if (bound >= minCost)
        return;

    for (int i = 1; i < n; i++) {

        if (!visited[i]) {

            int newCost = currentCost + cost[current][i];

            if (newCost >= minCost)
                continue;

            visited[i] = 1;
            path[level] = i;

            tsp(i, level + 1, newCost);

            visited[i] = 0;
        }
    }
}

int main() {

    printf("Enter number of cities: ");
    scanf("%d", &n);

    if (n < 2 || n > MAX) {
        printf("Invalid number of cities\n");
        return 0;
    }

    printf("Enter cost matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    visited[0] = 1;
    path[0] = 0;

    tsp(0, 1, 0);

    if (minCost == INF) {
        printf("No valid tour found\n");
        return 0;
    }

    printf("\nMinimum travelling cost = %d\n", minCost);

    printf("Optimal path = ");

    for (int i = 0; i < n; i++)
        printf("%d -> ", bestPath[i]);

    printf("0\n");

    return 0;
}
