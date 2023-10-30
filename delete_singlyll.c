#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete a node with a given value from the list
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (previous == NULL) {
                // If the node to delete is the head node
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Node with value %d not found in the list.\n", value);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int numNodes, data, deleteValue;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        appendNode(&head, data);
    }

    printf("Linked list created:\n");
    printList(head);

    printf("Enter the value to delete: ");
    scanf("%d", &deleteValue);
    deleteNode(&head, deleteValue);

    printf("Linked list after deletion:\n");
    printList(head);

    return 0;
}
