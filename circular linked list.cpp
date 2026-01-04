#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

Node* create(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data; n->next = n;
    return n;
}

void insertAfter(Node* prev, int data) {
    if (!prev) return;
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data; n->next = prev->next;
    prev->next = n;
}

void deleteNode(Node** head, int key) {
    if (!*head) return;
    Node *curr = *head, *prev = NULL;
    while (curr->data != key) {
        if (curr->next == *head) return;
        prev = curr; curr = curr->next;
    }
    if (curr->next == *head && prev == NULL) { *head = NULL; free(curr); return; }
    if (curr == *head) {
        prev = *head; while (prev->next != *head) prev = prev->next;
        *head = curr->next; prev->next = *head;
    } else prev->next = curr->next;
    free(curr);
}

void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do { printf("%d ", temp->data); temp = temp->next; } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = create(10);
    insertAfter(head, 20);
    insertAfter(head->next, 30);
    printList(head);
    deleteNode(&head, 10);
    printList(head);
    return 0;
}
