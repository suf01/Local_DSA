#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

//void traversal(struct node *ptr);

/*struct node *insertionatfirst(struct node *head, int data){
    struct node * ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    
    return(ptr);
}
*/
/*struct node *insertionafternode(struct node *head, struct node *nod, int data){

    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = nod->next;
    ptr->data = data;
    nod->next = ptr;
    return(head);

}
*/
/*struct node * insertionatlast(struct node *head, int data){
    struct node *ptr, *p;
    
    p = (struct node *)malloc(sizeof(struct node));
    ptr = (struct node *)malloc(sizeof(struct node));
    p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->data=data;
    ptr->next=NULL;
    return(head);

}
*/


/* struct node *insertionafterelement(struct node *head, int data, int ele){
     struct node *ptr=(struct node*)malloc(sizeof(struct node));
     struct node *p=(struct node*)malloc(sizeof(struct node));
     //struct node *temp=(struct node*)malloc(sizeof(struct node));
     p=head;
     while(p->data!=ele){
         p=p->next;
     }
     //temp=p; 

     ptr->next=p->next;
     ptr->data=data;
     p->next=ptr;
     return(head);

 }
*/
 
struct node *insertionatindex(struct node*head, int data, int index){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p=head;
    int i=0;
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    ptr->data=data;
    p->next=ptr;
    return(head);
}


void traversal(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("Linked list elements : %d\n", ptr->data);
        ptr = ptr->next;
    }
 }

void main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = NULL;
    
 /*   struct node *ptr;
    ptr= head;
    while(ptr!=NULL){
        printf("%d \n", ptr->data);
        ptr=ptr->next;
    }
*/
    printf("Before\n");
    traversal(head);
    //head = insertionatfirst(head, 50);
    //head=insertionafternode(head, second, 10);
    //head=insertionatlast(head, 10);
    //head = insertionafterelement(head, 1, 22);
    head=insertionatindex(head, 2, 1);
    printf("After\n");
    traversal(head);
    
}


 