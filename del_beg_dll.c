#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
    printf("The first node has been deleted.\n");
}

int main() {
    // Create a sample doubly linked list
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

    // Print the original list
    struct Node* current = head;
    printf("Original list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Delete the first node
    deleteFirstNode(&head);

    // Print the updated list
    current = head;
    printf("Updated list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}
