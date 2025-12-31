#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;

/* DFS function */
void dfs(int v) {
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    /* Initialize visited array */
    for (i = 0; i < n; i++)
        visited[i] = 0;

    /* Start DFS from vertex 0 */
    dfs(0);

    /* Check if all vertices are visited */
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            printf("Graph is NOT connected.\n");
            return 0;
        }
    }

    printf("Graph is connected.\n");
    return 0;
}

