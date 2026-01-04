#include <stdio.h>

void insert(int arr[], int *n, int pos, int val) {
    for (int i = *n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    (*n)++;
}

void delete(int arr[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++) arr[i] = arr[i + 1];
    (*n)--;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50}, n = 5;
    insert(arr, &n, 2, 99); 
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    delete(arr, &n, 1); 
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
