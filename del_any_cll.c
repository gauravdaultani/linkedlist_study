#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to delete a node from the circular linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* curr = *head;
    struct Node* prev = NULL;

    // Find the node to be deleted
    while (curr->data != key) {
        if (curr->next == *head) {
            printf("Node with key %d not found.\n", key);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    // If the node to be deleted is the only node in the list
    if (curr->next == *head && prev == NULL) {
        *head = NULL;
        free(curr);
        return;
    }

    // If the node to be deleted is the first node
    if (curr == *head) {
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = (*head)->next;
        prev->next = *head;
        free(curr);
    }

    // If the node to be deleted is not the first node
    else {
        prev->next = curr->next;
        free(curr);
    }

    printf("Node with key %d deleted successfully.\n", key);
}

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
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

    // Print the original list
    printf("Original list: ");
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 2);

    // Print the updated list
    printf("Updated list: ");
    printList(head);

    return 0;
}
