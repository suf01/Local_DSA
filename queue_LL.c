#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void display(struct node *front){
    printf("running display\n");
    while (front!=NULL)
    {
        printf("Element is: %d\n", front->data);
        front = front->next;
    }
    
}

void enqueue(int val){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    printf("running enqueue\n");

    if(n == NULL){
        printf("Queue is full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        
        if(front == NULL){
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
        
    }
    
}

int dequeue(){
    struct node *n = front;
    int val = -1;
    
    if(front == NULL){
        printf("Queue is empty\n");
    }
    else
    {
        val = front->data;
        front = front->next;
        free(n);
    }
    return(val);
}

int main(){
    dequeue();
    enqueue(12);
    enqueue(11);
    enqueue(15);
    enqueue(17);

    printf("dequeue element is: %d\n", dequeue());
    printf("dequeue element is: %d\n", dequeue());
    printf("dequeue element is: %d\n", dequeue());

    display(front);
}