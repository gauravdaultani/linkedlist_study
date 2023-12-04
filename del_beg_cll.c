#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

void deleteNodeAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return;
    }

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    struct Node* temp = *head;
    *head = (*head)->next;

    last->next = *head;
free(temp);
}

int main() {
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = head;

    printf("Original List: ");
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
    deleteNodeAtBeginning(&head);

    printf("Updated List: ");
    current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");

    return 0;
}
