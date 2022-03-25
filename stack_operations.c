#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int IsEmpty(struct stack *ptr)
{

    if (ptr->top == -1)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int IsFull(struct stack *ptr)
{

    if (ptr->top == ptr->size - 1)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void push(struct stack *ptr, int val)
{
    if (IsFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    int temp;
    if (IsEmpty(ptr))
    {
        printf("Empty\n");
    }
    else
    {
        temp = ptr->arr[ptr->top];
        ptr->top--;
        return (temp);
    }
}

int peek(struct stack *s, int i){
    int position = s->top-i+1;
    if(position < 0){
        printf("Not a valid position");
        return(-1);
    }
    else
    {
        return(s->arr[position]);
    }
    
}

void stackTop(struct stack *s){
    printf("stacktop : %d\n", s->arr[s->top]);
}

void stackBottom(struct stack *s){
    printf("stackBottom : %d", s->arr[0]);
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    //push(s, 6); overflow

    //printf("poped element = %d\n", pop(s));

    /*
    if (IsFull(s))
    {
        printf("Full\n");
    }
    else
    {
        printf("Not full\n");
    }
    */
    
    /*
    printf("peeked at 1, element is %d\n", peek(s,1));
    printf("peeked at 2, element is %d\n", peek(s,2));
    printf("peeked at 3, element is %d\n", peek(s,3));
    printf("peeked at 4, element is %d\n", peek(s,4));
    printf("peeked at 5, element is %d\n", peek(s,5));
    */
    stackTop(s);
    stackBottom(s);

    return (0);
}