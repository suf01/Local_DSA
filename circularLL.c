#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertionatfirst(struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *q = (struct node *)malloc(sizeof(struct node));
}

void traversal(struct node *head){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr=head;
    /*
    printf("LL elements are :%d\n", ptr->data);
    ptr=ptr->next;
    while (ptr != head)
    {
        printf("LL elements are :%d\n", ptr->data);
        ptr = ptr->next;
    }
    */
   do{
       printf("LL elements are :%d\n", ptr->data);
       ptr=ptr->next;
   }
   while (ptr!=head);
}

void main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = head;

    printf("Before\n");
    traversal(head);
    //printf("After\n");
    //traversal(head);

}