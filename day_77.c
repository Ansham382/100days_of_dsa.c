/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/

#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int* visited, int** graph, int* graphSize) {
    visited[node] = 1;

    for (int i = 0; i < graphSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph, graphSize);
        }
    }
}

int main() {
    int n, m;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // adjacency list
    int** graph = (int**)malloc((n + 1) * sizeof(int*));
    int* graphSize = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        graph[i] = (int*)malloc((n + 1) * sizeof(int)); // simple allocation
    }

    printf("Enter edges:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][graphSize[u]++] = v;
        graph[v][graphSize[v]++] = u;
    }

    int* visited = (int*)calloc(n + 1, sizeof(int));

    // start DFS from node 1
    dfs(1, visited, graph, graphSize);

    // check if all nodes visited
    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}
