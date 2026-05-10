#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*link;
};

int main()
{
    struct node *head = malloc(sizeof(struct node));

    head -> data= 45;
    head -> link = NULL;

    struct node* current = malloc(sizeof(struct node));
    current -> data = 98;
    current -> link = NULL;

    head -> link = current;

    printf("%d -> %d\n", head->data, head->link->data);



    free(head);
    free(current);  

    return 0;
   //
}