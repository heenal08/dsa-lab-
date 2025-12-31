#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

/* Enqueue */
void enqueue(int v) {
    queue[++rear] = v;
}

/* Dequeue */
int dequeue() {
    return queue[++front];
}

/* BFS function */
void bfs(int n, int start) {
    int i, v;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front != rear) {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(n, start);

    return 0;
}
