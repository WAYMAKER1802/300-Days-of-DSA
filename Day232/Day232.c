//Question: Find the shortest distance from a given source vertex to all other vertices in a weighted,
// undirected graph using Dijkstra's Algorithm.

#include <stdio.h>
#define INF 99999
#define V 5

int main() {
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int dist[V], visited[V] = {0};
    int src = 0, min, u;

    for(int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    for(int i = 0; i < V-1; i++) {
        min = INF;
        u = -1;

        for(int j = 0; j < V; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        for(int v = 0; v < V; v++) {
            if(!visited[v] && graph[u][v] &&
               dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from source %d:\n", src);

    for(int i = 0; i < V; i++)
        printf("To vertex %d = %d\n", i, dist[i]);

    return 0;
}
