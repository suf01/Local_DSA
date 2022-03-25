#include <stdio.h>
#include <stdlib.h>

int binsearch(int a[], int size, int ele)
{
    int high = size-1;
    int low = 0;
    

    while (high >= low)
    {
        int mid = (high + low) / 2;
        if (a[mid] == ele)
        {
            return(mid);
        }
        if (a[mid] > ele)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return(-1);

}

int main()
{
    int a[] = {13, 20, 32};
    int size = 3;
    int ele = 32;
    int pos = binsearch(a, size, ele);
    printf("Position %d", pos+1);
}