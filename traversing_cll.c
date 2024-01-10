#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and print the circular linked list
void traverseCircularLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node* current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    // Create a circular linked list
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = head;

    // Traverse and print the circular linked list
    traverseCircularLinkedList(head);

    return 0;
}
