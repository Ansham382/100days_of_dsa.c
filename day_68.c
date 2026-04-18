/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

sample input- 
Enter number of vertices: 6
Enter number of edges: 6
Enter edges (u v):
5 2
5 0
4 0
4 1
2 3
3 1
Topological sorting is:
4 5 2 0 3 1
*/

#include <stdio.h>

int main() {
    int n, e;
    int adj[50][50];
    int indegree[50];
    int queue[50];
    int front = 0, rear = 0;
    int topo[50];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(int i = 0; i < n; i++) {
        indegree[i] = 0;
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear] = i;
            rear++;
        }
    }

    int k = 0;

    while(front < rear) {
        int node = queue[front];
        front++;

        topo[k] = node;
        k++;

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[rear] = i;
                    rear++;
                }
            }
        }
    }

    if(k != n) {
        printf("Cycle detected\n");
    } else {
        printf("Topological sorting is:\n");
        for(int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}
