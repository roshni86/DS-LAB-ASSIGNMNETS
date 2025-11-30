#include <stdio.h>

#define MAX 20

int parent[MAX];

int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int cost[MAX][MAX];
    int n, i, j, edges = 0, min, a, b, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &cost[i][j]);

    for(i=0;i<n;i++)
        parent[i] = i;

    int totalCost = 0;

    printf("Edges in MST:\n");

    while(edges < n-1) {
        min = 9999;

        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                if(find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        unionSet(u, v);
        printf("%d - %d : %d\n", a, b, min);
        totalCost += min;
        edges++;
    }

    printf("Total cost = %d\n", totalCost);

    return 0;
}