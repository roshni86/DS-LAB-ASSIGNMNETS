#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int n;
void createGraph() {
    int i, j, edges, u, v;
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
        adj[u][v] = 1;
        adj[v][u] = 1;    // remove this for directed graph
    }
}

// Print adjacent vertices
void printAdjVertices(int v) {
    printf("Adjacent vertices of %d: ", v);
    for(int i=0;i<n;i++)
        if(adj[v][i] == 1)
            printf("%d ", i);
    printf("\n");
}
void degree(int v) {
    int d = 0;
    for(int i=0;i<n;i++)
        if(adj[v][i] == 1) d++;
    printf("Degree of %d = %d\n", v, d);
}

int main() {
    createGraph();

    int v;
    printf("Enter vertex to get degree: ");
    scanf("%d", &v);
    degree(v);

    printf("Enter vertex to get adjacent vertices: ");
    scanf("%d", &v);
    printAdjVertices(v);

    return 0;
}
