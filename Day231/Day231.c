//Question: Shortest Path in a Weighted Graph
//You are given a weighted, undirected graph containing V vertices and E edges.
//Each edge connects two vertices and has a positive weight representing the distance between them.
//Write a C program to find the shortest distance from a given source vertex to every other vertex using Dijkstra's algorithm.
//If a vertex is unreachable, print INF.

#include <stdio.h>

#define INF 999999

int main() {
    int n, e;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &e);

    int graph[100][100] = {0};
    int dist[100], visited[100] = {0};

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[source] = 0;

    for (int i = 0; i < n; i++) {
        int min = INF, u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    printf("\nShortest distances from source %d:\n", source);

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("Vertex %d = INF\n", i);
        else
            printf("Vertex %d = %d\n", i, dist[i]);
    }

    return 0;
}
