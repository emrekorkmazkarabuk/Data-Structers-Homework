#include <stdio.h>

int main() {
    int r = 4, c = 5, k = 1, size = 0;
    int mat[4][5] = {{0, 0, 3, 0, 4}, {0, 0, 5, 7, 0}, {0, 0, 0, 0, 0}, {0, 2, 6, 0, 0}};
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) if(mat[i][j] != 0) size++;
    int sparse[size + 1][3];
    sparse[0][0] = r; sparse[0][1] = c; sparse[0][2] = size;
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) if(mat[i][j] != 0) {
        sparse[k][0] = i; sparse[k][1] = j; sparse[k++][2] = mat[i][j];
    }
    for(int i = 0; i <= size; i++) printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    return 0;
}
