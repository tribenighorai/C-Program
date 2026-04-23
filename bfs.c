#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}
void bfs(int adj[MAX][MAX], int visited[MAX], int start, int n) {
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}
int main() {
    int n;
    printf("Enter number of vertices:");
    scanf("%d", &n);

    int adj[MAX][MAX], visited[MAX] = {0};
    printf("Enter adjacency matrix:");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int start;
    printf("Enter starting vertex:");
    scanf("%d", &start);

    printf("BFS Traversal:");
    bfs(adj, visited, start, n);
    return 0;
}
