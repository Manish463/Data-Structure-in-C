#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int partition(int arr[], int st, int end) {
    int pivot = arr[end], idx=st-1;

    for(int i=st; i<end; i++) {
        if(arr[i] < pivot) {
            swap(&arr[++idx], &arr[i]);
        }
    }
    swap(&arr[++idx], &arr[end]);
    return idx;
}

void quickSort(int arr[], int st, int end) {
    if(st >= end) return;

    int pivIdx = partition(arr, st, end);
    quickSort(arr, st, pivIdx-1);
    quickSort(arr, pivIdx+1, end);
}

int main() {
    int arr[] = {4, 15, 58, 1, 123, 14};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);
    printf("The sorted array is:\t");
    for(int i=0; i<n; i++)
        printf("%d, ", arr[i]);

    return 0;
}