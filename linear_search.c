#include<stdio.h>
#include<stdlib.h>

int linearsearch(int arr[], int size, int ele){
    for (int  i = 0; i < size; i++)
    {
        if(arr[i] == ele){
            return(i);
        }
    }
    return(-1);
}

int main()
{
    int a[]={1, 2, 3};
    int n = sizeof(a)/sizeof(a[0]);
    int ele = 4;
    int result = linearsearch(a, n, ele);
    printf("Element found at index %d \n", result);

return(0);
}