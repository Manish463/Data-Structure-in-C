#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void aseBubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int isSwap = 0;
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                isSwap = 1;
            }
        }
        if(!isSwap) {
            printf("The given array is already in sorted order.");
            return;
        }
    }
    return;
}

void dseBubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int isSwap = 0;
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] < arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                isSwap = 1;
            }
        }
        if(!isSwap) {
            printf("The given array is already in sorted order.");
            return;
        }
    }
    return;
}

int main() {
    int arr[] = {4, 15, 58, 1, 23, 14};
    int n = sizeof(arr)/sizeof(arr[0]);

    dseBubbleSort(arr, n);
    for(int i=0; i<n; i++)
        printf("%d, ", arr[i]);

    return 0;
}