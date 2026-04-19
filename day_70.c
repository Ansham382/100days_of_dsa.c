/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/

#include <stdio.h>

#define MAX 100
#define INF 1000000000

int main() {
    int n, m, i, j, u, v, w, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int edge[MAX][3];

    printf("Enter edges (u v w):\n");
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &edge[i][0], &edge[i][1], &edge[i][2]);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    int dist[MAX];

    for(i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    for(i = 1; i <= n - 1; i++) {
        for(j = 0; j < m; j++) {
            u = edge[j][0];
            v = edge[j][1];
            w = edge[j][2];

            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for(j = 0; j < m; j++) {
        u = edge[j][0];
        v = edge[j][1];
        w = edge[j][2];

        if(dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for(i = 0; i < n; i++) {
        if(dist[i] == INF)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }

    return 0;
}
