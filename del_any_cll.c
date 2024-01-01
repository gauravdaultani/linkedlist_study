#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* curr = *head;
    struct Node* prev = NULL;

    while (curr->data != key) {
        if (curr->next == *head) {
            printf("Node with key %d not found.\n", key);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    if (curr->next == *head && prev == NULL) {
        *head = NULL;
        free(curr);
        return;
    }

    if (curr == *head) {
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = (*head)->next;
        prev->next = *head;
        free(curr);
    }

    else {
        prev->next = curr->next;
        free(curr);
    }

    printf("Node with key %d deleted successfully.\n", key);
}

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

    printf("Original list: ");
    printList(head);

    deleteNode(&head, 2);

    printf("Updated list: ");
    printList(head);

    return 0;
}
