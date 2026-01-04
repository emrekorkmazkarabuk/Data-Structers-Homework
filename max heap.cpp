#include <stdio.h>

int heap[100], n = 0;

void swap(int *a, int *b) { int temp = *a; *a = *b; *b = temp; }

void insert(int val) {
    int i = n++;
    heap[i] = val;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteMax() {
    heap[0] = heap[--n];
    int i = 0, largest;
    while ((2 * i + 1) < n) {
        int left = 2 * i + 1, right = 2 * i + 2;
        largest = (right < n && heap[right] > heap[left]) ? right : left;
        if (heap[i] >= heap[largest]) break;
        swap(&heap[i], &heap[largest]);
        i = largest;
    }
}

int main() {
    insert(10); insert(20); insert(5); insert(30); deleteMax();
    for (int i = 0; i < n; i++) printf("%d ", heap[i]);
    return 0;
}
