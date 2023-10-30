#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *link;
};
int main(){
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));

    head -> value = 45;
    head -> link = NULL;

    printf("Data = %d", head ->  value);
    return 0;
}
