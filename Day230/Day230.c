//Question: There is a bidirectional graph with n vertices numbered from 0 to n-1.
//You are given an array edges, where each edges[i] = [u, v] represents an edge between vertices u and v.
//You are also given two vertices, source and destination.
//Return true if a valid path exists between the source and destination; otherwise, return false.

#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, e;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    int graph[100][100] = {0};
    int visited[100] = {0};
    int queue[100];

    printf("Enter edges:\n");

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int source, destination;

    printf("Enter source and destination: ");
    scanf("%d %d", &source, &destination);

    int front = 0, rear = 0;
    queue[rear++] = source;
    visited[source] = 1;

    while (front < rear) {
        int current = queue[front++];

        if (current == destination) {
            printf("Path exists\n");
            return 0;
        }

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("Path does not exist\n");

    return 0;
}
