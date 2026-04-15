/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
int size[MAX];
bool visited[MAX];
bool recStack[MAX];

bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor))
                return true;
        } else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        size[i] = 0;
        visited[i] = false;
        recStack[i] = false;
    }

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][size[u]++] = v;
    }

    bool cycle = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
