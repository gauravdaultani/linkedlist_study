#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of a circular linked list
void insertAtBeginning(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    // If the list is empty, make the new node the head and point its next to itself
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        // Find the last node in the list
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        // Make the new node the new head and update the next pointers
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
    }
}

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
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
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Print the list
    printf("Circular Linked List: ");
    printList(head);

    return 0;
}
