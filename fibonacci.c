#include <stdlib.h>
#include <stdio.h>

int fib(int terms)
{
    if (terms == 1 || terms == 2)
    {
        return (1);
    }
    else
    {
        return (fib(terms - 1) + fib(terms - 2));
    }
}
int main()
{
    int terms = 5;
    for (int i = 1; i <= terms; i++)
    {
        printf("%d ", fib(i));
    }
    return (0);
}