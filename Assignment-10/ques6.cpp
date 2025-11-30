#include <stdio.h>

#define INF 9999
#define MAX 20

int main() {
    int cost[MAX][MAX], dist[MAX], visited[MAX];
    int n, i, j, start, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &cost[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for(i=0;i<n;i++) {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }

    visited[start] = 1;

    for(i=0;i<n-1;i++) {
        min = INF;

        for(j=0;j<n;j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(j=0;j<n;j++) {
            if(!visited[j] && dist[u] + cost[u][j] < dist[j])
                dist[j] = dist[u] + cost[u][j];
        }
    }

    printf("Shortest distances from %d:\n", start);
    for(i=0;i<n;i++)
        printf("%d -> %d : %d\n", start, i, dist[i]);

    return 0;
}