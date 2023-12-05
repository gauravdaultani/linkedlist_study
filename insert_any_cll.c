#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int position, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        return;
    }

    struct Node* current = *head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

  
    newNode->next = current->next;
    current->next = newNode;
}

void displayList(struct Node* head) {
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

    insertNode(&head, 0, 1); // Insert at the beginning
    insertNode(&head, 1, 2); // Insert at position 1
    insertNode(&head, 2, 3); // Insert at position 2
    insertNode(&head, 3, 4); // Insert at the end

    displayList(head);

    return 0;
}
