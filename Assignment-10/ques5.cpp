#include <stdio.h>

#define INF 9999
#define MAX 20

int main() {
    int cost[MAX][MAX], visited[MAX];
    int n, i, j, edges = 0, min, a, b;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &cost[i][j]);

    for(i=0;i<n;i++)
        visited[i] = 0;

    visited[0] = 1;

    printf("Edges in MST:\n");

    while(edges < n-1) {
        min = INF;

        for(i=0;i<n;i++) {
            if(visited[i]) {
                for(j=0;j<n;j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        visited[b] = 1;
        printf("%d - %d : %d\n", a, b, min);
        totalCost += min;
        edges++;
    }

    printf("Total cost = %d\n", totalCost);

    return 0;
}