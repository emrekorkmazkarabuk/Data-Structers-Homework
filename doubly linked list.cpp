#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next, *prev; } Node;

Node* create(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data; newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertAfter(Node* prev, int data) {
    if (prev == NULL) return;
    Node* newNode = create(data);
    newNode->next = prev->next;
    prev->next = newNode;
    newNode->prev = prev;
    if (newNode->next != NULL) newNode->next->prev = newNode;
}

void deleteNode(Node** head, Node* del) {
    if (*head == NULL || del == NULL) return;
    if (*head == del) *head = del->next;
    if (del->next != NULL) del->next->prev = del->prev;
    if (del->prev != NULL) del->prev->next = del->next;
    free(del);
}

void printList(Node* node) {
    while (node != NULL) { printf("%d ", node->data); node = node->next; }
    printf("\n");
}

int main() {
    Node* head = create(10);
    insertAfter(head, 20);
    insertAfter(head->next, 30);
    printList(head);
    deleteNode(&head, head->next);
    printList(head);
    return 0;
}
