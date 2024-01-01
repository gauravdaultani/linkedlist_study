#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete a node from the doubly linked list
void deleteNode(struct Node** head, struct Node* delNode) {
    // If the node to be deleted is the head node
    if (*head == delNode) {
        *head = delNode->next;
    }

    // If the node to be deleted is not the last node
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }

    // If the node to be deleted is not the first node
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }

    // Free the memory occupied by the node
    free(delNode);
}

int main() {
    // Create a doubly linked list with three nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->prev = NULL;
    head->next = second;

    second->data = 2;
    second->prev = head;
    second->next = third;

    third->data = 3;
    third->prev = second;
    third->next = NULL;

    // Print the original doubly linked list
    struct Node* current = head;
    printf("Original Doubly Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Delete the second node from the doubly linked list
    deleteNode(&head, second);

    // Print the modified doubly linked list
    current = head;
    printf("Modified Doubly Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}
