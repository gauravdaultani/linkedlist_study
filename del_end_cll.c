#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to delete a node from the end of the circular linked list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from end.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    // Traverse to the last node
    while (current->next != *head) {
        prev = current;
        current = current->next;
    }

    // If there is only one node in the list
    if (current == *head) {
        *head = NULL;
    } else {
        // Remove the last node from the list
        prev->next = current->next;
    }

    free(current);
}

int main() {
    // Create a circular linked list with three nodes
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
    struct Node* current = head;
    printf("Original List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");

    // Delete a node from the end
    deleteFromEnd(&head);

    // Print the updated list
    current = head;
    printf("Updated List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");

    return 0;
}
