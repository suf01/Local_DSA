#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

/*struct node* deletionatfirst(struct node *head){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    head = head->next;
    free(ptr);
    return(head);
    
}
*/

struct node *deletionatlast(struct node *head){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    struct node *q=(struct node*)malloc(sizeof(struct node));
    p=head;
    q=head->next;
    while (q->next!=NULL )
    {
        q=q->next;
        p=p->next;
        
    }
    free(p->next);
    p->next=NULL;
    return(head);
}

/*
struct node *deletionatmid(struct node *head, int index){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    struct node *q=(struct node*)malloc(sizeof(struct node));
    int i=0;
    p=head;
    q=head->next;
    while (i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return(head);
}
*/
void traversal(struct node *ptr){
    
    while (ptr != NULL)
    {
        printf("LL elements are :%d\n", ptr->data);
        ptr = ptr->next;
    }
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
    third->next = NULL;

    printf("Before\n");
    traversal(head);
    //head=deletionatmid(head,1);
    head=deletionatlast(head);
    head=deletionatlast(head);
    //head = deletionatfirst(head);
    printf("After\n");
    traversal(head);

}