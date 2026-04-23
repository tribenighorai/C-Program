#include <stdio.h>
#define MAX 100

void dfs(int adj[MAX][MAX], int visited[MAX], int start, int n) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < n; i++) {
        if (adj[start][i] && !visited[i]) {
            dfs(adj, visited, i, n);
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

    printf("DFS Traversal:");
    dfs(adj, visited, start, n);
    return 0;
}
