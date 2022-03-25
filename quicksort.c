#include<stdio.h>
#include<stdlib.h>

void printarray(int a[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high){
    int pivot;
    pivot=a[low];

    int i = low + 1;
    int j = high;

    do{
    while (a[i]<=pivot)
    {
        i++;
    }

    while (a[j]>pivot)
    {
        j--;
    }
    
    if(i<j){
        int temp = a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    }while(i<j);

    int temp2 = a[low];
    a[low] = a[j];
    a[j] = temp2;
 
 return(j);
}


void quicksort(int a[], int low, int high){
    int partitionindex;

    if(low<high){
    partitionindex = partition(a, low, high);
    quicksort(a, low, partitionindex-1);
    quicksort(a, partitionindex+1, high);
    }

}
int main(){
    int a[] = {1, 3, 2, 4, 6, 8};
    int size = sizeof(a)/sizeof(a[0]);
    printarray(a, size);
    quicksort(a, 0, size);
    printarray(a, size);
}