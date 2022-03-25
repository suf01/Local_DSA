#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void IsEmpty(struct node *head){
    if(head==NULL){
        printf("Empty\n");
    }
    else{
        printf("Not empty\n");
    }
    
}
void IsFull(struct node *head){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    if(new==NULL){
        printf("Full\n");
    }
    else{
        printf("Not full");
    }
}

struct node* push(struct node *head, int data){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    if(new==NULL){
        printf("stack overflow\n");
    }
    else
    {
    struct node *top;
    new->data=data;
    new->next=head;
    top=new;
    return (top);
    }

}
struct node* pop(struct node *head){
    if(head==NULL){
        printf("Empty\n");
    }
    else{
        int temp;
        struct node *top = (struct node*)malloc(sizeof(struct node));
        temp = head->data;
        top=head->next;
        free(head);
        printf("Popped element : %d\n", temp);
        return(top);
    }
}
    
void stackTop(struct node *head){
    printf("stack top is : %d\n",head->data);
}

int stackBottom(struct node *head){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr=head;
    
    while (ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    printf("stack bottom is : %d\n", ptr->data);
    
}

int peek(struct node *head, int pos){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr=head;
    int i=1;
    while (i!=pos)
    {
        ptr=ptr->next;
        i++;
    }
    return(ptr->data);
}
int main()
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *two = (struct node*)malloc(sizeof(struct node));
    struct node *three = (struct node*)malloc(sizeof(struct node));
    struct node *four = (struct node*)malloc(sizeof(struct node));
    struct node *five = (struct node*)malloc(sizeof(struct node));

    head->data=55;
    head->next=two;

    two->data=42;
    two->next=three;
    
    three->data=35;
    three->next=four;

    four->data=23;
    four->next=five;

    five->data=13;
    five->next=NULL;

    //IsEmpty(head);
    //IsFull(head);

    /*
    head = push(head, 20);
    printf("New top is : %d\n", head->data);

    head = pop(head);
    printf("New top is : %d\n", head->data);
    */
    
     stackTop(head);
     stackBottom(head);
     printf("peeked element is : %d\n", peek(head, 2));

}