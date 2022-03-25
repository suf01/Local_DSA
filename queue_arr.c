#include<stdio.h>
#include<stdlib.h>

struct queue{
    int f;
    int r;
    int size;
    int *arr;
};

int isFull(struct queue *q){
    if(q->r == q->size-1){
        return(1);
    }
    else
    {
        return(0);
    }
    
}
int isEmpty(struct queue *q){
    if(q->r == q->f){
        return(1);
    }
    else
    {
        return(0);
    }
    
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
    
}

int dequeue(struct queue *q){
    int val = -1;

    if(isEmpty(q)){
        printf("Queue is full\n");
    }
    else
    {
        q->f++;
        val = q->arr[q->f];
    }
   
   return(val); 
}
int main(){
    struct queue *q;
    
    q->f = q->r = -1;
    q->size = 100;
    q->arr = (int*)malloc((q->size)*(sizeof(int)));

    printf("Before enqueue:\n");
    
    if(isEmpty(q)){
        printf("Queue is empty \n");
    }

    if(isFull(q)){
        printf("Queue is full \n");
    }

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("After enqueue:\n");
    
    if(isEmpty(q)){
        printf("Queue is empty \n");
    }

    if(isFull(q)){
        printf("Queue is full \n");
    }

    printf("dequeue element: %d\n", dequeue(q));
    printf("dequeue element: %d\n", dequeue(q));
    printf("dequeue element: %d\n", dequeue(q));

     if(isEmpty(q)){
        printf("Queue is empty \n");
    }
}