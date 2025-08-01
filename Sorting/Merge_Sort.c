#include<stdio.h>

void mergeArr(int arr[], int st, int mid, int end) {
    int i=st, j=mid+1, k=0, temp[end+1];

    while(i<=mid && j<=end) {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i<=mid) {
        temp[k++] = arr[i++];
    }
    while(j<=end) {
        temp[k++] = arr[j++];
    }
    for(int idx=0; idx<k; idx++) {
        arr[idx+st] = temp[idx];
    }
}

void mergeSort(int arr[], int st, int end) {
    if(st >= end) return;

    int mid = st + (end-st)/2;
    mergeSort(arr, st, mid);
    mergeSort(arr, mid+1, end);

    mergeArr(arr, st, mid, end);
}

int main() {
    int arr[] = {4, 15, 58, 1, 23, 14};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n-1);

    printf("\nThe sorted array is: ");
    for(int i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }
    
    return 0;
}