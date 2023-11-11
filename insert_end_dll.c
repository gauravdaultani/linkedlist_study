#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};
void insertStart (struct Node **head, int data)
{

  // creating memory for newNode
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));

  // assigning newNode's next as the current head 
  // Assign data & and make newNode's prev as NULL
  newNode->data = data;
  newNode->next = *head;
  newNode->prev = NULL;

  // if list already had item(s)
  // We need to make current head previous node as this new node
  if (*head != NULL)
    (*head)->prev = newNode;

  // change head to this newNode
  *head = newNode;

}

void insertLast (struct Node **head, int data)
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));

  newNode->data = data;
  newNode->next = NULL;

  //need this if there is no node present in linked list at all
  if (*head == NULL)
    {
      *head = newNode;
      newNode->prev = NULL;
      return;
    }

  struct Node *temp = *head;

  // traverse till the last node
  while (temp->next != NULL)
    temp = temp->next;

  // assign last node's next to this new Node
  temp->next = newNode;
  // assign this new Node's previous to last node(temp)
  newNode->prev = temp;
}

void display (struct Node *node)
{
  struct Node *end;
  printf ("\nIn Forward Direction\n");
  while (node != NULL)
    {
      printf (" %d ", node->data);
      end = node;
      node = node->next;
    }

  printf ("\nIn Backward direction \n");
  while (end != NULL)
    {
      printf (" %d ", end->data);
      end = end->prev;
    }
}

int main ()
{
  struct Node *head = NULL;

  // Need '&' i.e. address as we need to change head
  insertStart (&head, 1);
  insertStart (&head, 2);
  insertStart (&head, 3);

  insertLast (&head, 10);
  insertLast (&head, 20);

  // no need for '&' as head need not be changed
  // only doing traversal
  display (head);

  return 0;
}