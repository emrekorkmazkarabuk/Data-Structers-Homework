#include <stdio.h>
#define SIZE 100

int tree[SIZE] = {0};

void insert(int val) {
    int i = 0;
    while (i < SIZE && tree[i] != 0) {
        if (val < tree[i]) i = 2 * i + 1;
        else i = 2 * i + 2;
    }
    if (i < SIZE) tree[i] = val;
}

int search(int val) {
    int i = 0;
    while (i < SIZE && tree[i] != 0) {
        if (tree[i] == val) return 1;
        else if (val < tree[i]) i = 2 * i + 1;
        else i = 2 * i + 2;
    }
    return 0;
}

void preorder(int i) {
    if (i >= SIZE || tree[i] == 0) return;
    printf("%d ", tree[i]);
    preorder(2 * i + 1);
    preorder(2 * i + 2);
}

void inorder(int i) {
    if (i >= SIZE || tree[i] == 0) return;
    inorder(2 * i + 1);
    printf("%d ", tree[i]);
    inorder(2 * i + 2);
}

void postorder(int i) {
    if (i >= SIZE || tree[i] == 0) return;
    postorder(2 * i + 1);
    postorder(2 * i + 2);
    printf("%d ", tree[i]);
}

int main() {
    insert(50); insert(30); insert(20); insert(40); insert(70); insert(60); insert(80);
    printf("Preorder : "); preorder(0); printf("\n");
    printf("Inorder  : "); inorder(0); printf("\n");
    printf("Postorder: "); postorder(0); printf("\n");
    printf("Search 60: %s\n", search(60) ? "Found" : "Not Found");
    printf("Search 99: %s\n", search(99) ? "Found" : "Not Found");
    return 0;
}
