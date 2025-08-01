#include<stdio.h>

void ascInsertionSort(int arr[], int n) {
    int curr, prev;
    for(int i=1; i<n; i++) {
        curr = arr[i];
        prev = i-1;
        while(prev >= 0 && arr[prev] > curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
    return;
}

void desInsertionSort(int arr[], int n) {
    int curr, prev;
    for(int i=1; i<n; i++) {
        curr = arr[i];
        prev = i-1;
        while(prev >= 0 && arr[prev] < curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
    return;
}

int main() {
    int arr[] = {4, 15, 58, 1, 23, 14};
    int n = sizeof(arr)/sizeof(arr[0]);

    desInsertionSort(arr, n);
    for(int i=0; i<n; i++)
        printf("%d, ", arr[i]);

    return 0;
}