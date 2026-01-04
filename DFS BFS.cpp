#include <stdio.h>

int G[5][5] = {{0,1,1,0,0}, {1,0,0,1,1}, {1,0,0,0,0}, {0,1,0,0,0}, {0,1,0,0,0}};
int visited[5], n = 5, q[20], f = 0, r = -1;

void DFS(int u) {
    visited[u] = 1; printf("%d ", u);
    for (int v = 0; v < n; v++) if (G[u][v] && !visited[v]) DFS(v);
}

void BFS(int s) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    q[++r] = s; visited[s] = 1;
    while (f <= r) {
        int u = q[f++]; printf("%d ", u);
        for (int v = 0; v < n; v++) if (G[u][v] && !visited[v]) { q[++r] = v; visited[v] = 1; }
    }
}

int main() {
    printf("DFS: "); DFS(0);
    printf("\nBFS: "); BFS(0);
    return 0;
}
