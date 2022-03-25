#include <stdio.h>
#include <stdlib.h>

void printarray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void sort(int a[], int low, int mid, int high)
{
    int b[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }

        if (a[j] < a[i])
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergesort(int a[], int low, int high)
{

    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        sort(a, low, mid, high);
    }
}

int main()
{
    int a[] = {23, 34, 23, 23, 23, 23, 13};
    int size = sizeof(a) / sizeof(a[0]);
    int high = size - 1;
    printarray(a, size);
    mergesort(a, 0, high);
    printarray(a, size);

    return (0);
}