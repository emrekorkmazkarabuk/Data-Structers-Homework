#include <stdio.h>

int G[5][5] = {{0,1,0,0,0}, {1,0,0,0,0}, {0,0,0,1,1}, {0,0,1,0,1}, {0,0,1,1,0}};
int visited[5] = {0}, n = 5;

void DFS(int u) {
    visited[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < n; v++) if (G[u][v] && !visited[v]) DFS(v);
}

int main() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("Cluster: ");
            DFS(i);
            printf("\n");
        }
    }
    return 0;
}
