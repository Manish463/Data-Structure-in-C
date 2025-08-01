#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void ascSelectionSort(int arr[], int n) {
    for(int i=0; i<n; i++){
        int smallInd = i;
        for(int j=i+1; j<n; j++) {
            if(arr[smallInd] > arr[j]) {
                smallInd = j;
            }
        }
        swap(&arr[i], &arr[smallInd]);
    }
}

void desSelectionSort(int arr[], int n) {
    for(int i=0; i<n; i++){
        int smallInd = i;
        for(int j=i+1; j<n; j++) {
            if(arr[smallInd] < arr[j]) {
                smallInd = j;
            }
        }
        swap(&arr[i], &arr[smallInd]);
    }
}

int main() {
    int arr[] = {31, 40, 180, 10, 16};
    int n = sizeof(arr)/sizeof(arr[0]);

    desSelectionSort(arr, n);
    for(int i=0; i<n; i++)
        printf("%d, ", arr[i]);

    return 0;
}