#include <stdio.h>

#define MAX 20

int adj[MAX][MAX], visited[MAX], n;

void bfs(int start) {
    int q[MAX], front = 0, rear = 0;
    int i;

    printf("BFS Traversal: ");

    visited[start] = 1;
    q[rear++] = start;

    while(front < rear) {
        int v = q[front++];
        printf("%d ", v);

        for(i=0;i<n;i++) {
            if(adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }
}

int main() {
    int edges, u, v, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for(i=0;i<edges;i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    for(i=0;i<n;i++) visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}