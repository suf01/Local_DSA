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

int main()
{
    /*
    struct stack s;
    s.size = 10;
    s.top = -1;
    s.arr[] = (int*)malloc(s.size * sizeof(int));
    */
    struct stack *s;
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    
    /*
    s->arr[0]=11;
    s->top++;
    s->arr[1]=22;
    s->top++;
    s->arr[2]=33;
    s->top++;

    printf("Elements at 1 : %d\n", s->arr[0]);
    printf("Elements at 2 : %d\n", s->arr[1]);
    printf("Elements at 3 : %d\n", s->arr[2]);
    */


    /*
    if(IsEmpty(s))
    {
        printf("Empty\n");
    }
    else
    {
        printf("Not empty\n");
    }
    */
    if (IsFull(s))
    {
        printf("Full\n");
    }
    else
    {
        printf("Not full\n");
    }

    return (0);
}