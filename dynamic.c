#include <stdio.h>
#include <stdlib.h>
void main()
{

    int *ptr, i, n;
    printf("no of elements\n");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    printf("elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("elements are \n");
    for (i = 0; i<n; i++)
    {
        printf("%d \n", ptr[i]);
    }

    printf("new no of elements\n");
    scanf("%d", &n);
    ptr = (int *)realloc(ptr, n * sizeof(int));
    printf("elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("elements are \n");
    for (i = 0; i < n; i++)
    {
        printf("%d \n", ptr[i]);
    }
}
