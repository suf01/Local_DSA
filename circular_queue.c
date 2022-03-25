#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

void enqueue(struct queue *q, int val){
    if((q->r+1)%q->size == q->f){
        printf("Queue overflow\n");
    }
    else
    {
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val; 
    }
    
}

int dequeue(struct queue *q){
    int val = -1;
    if((q->f == q->r)){
        printf("Queue is empty\n");
    }
    else
    {
        q->f = (q->f+1)%q->size;
        val = q->arr[q->f];
        return(val);
    }
    
}
int main(){
    struct queue *q;
    q->size = 100;
    q->f = q->r = 0;
    q->arr = (int*)malloc(q->size*(sizeof(int)));

    enqueue(q, 2);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 3);
    enqueue(q, 5);
    enqueue(q, 6);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

}
