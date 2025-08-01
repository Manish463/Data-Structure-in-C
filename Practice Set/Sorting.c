#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void selectionSort(int arr[], int n) {
    int smallIdx;

    for(int i=0; i<n-1; i++) {
        smallIdx = i;
        for(int j=i+1; j<n; j++) {
            if(arr[smallIdx] > arr[j]) 
                smallIdx = j;
        }
        swap(&arr[smallIdx], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    int curr, prev;

    for(int i=1; i<n; i++) {
        curr = arr[i];
        prev = i-1;

        while(prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

int main() {
    int arr[] = {1,23,13,54,72,15,10};
    int opt, n = sizeof(arr)/sizeof(arr[0]);
    
    printf("\n\n---- Sorting Menu ----\n\n");
    printf("1 for Bubble Sort\n");
    printf("2 for Selection Sort\n");
    printf("3 for Insertion Sort\n");

    printf("\nEnter your choice: ");
    scanf("%d", &opt);
    
    printf("\nThe elements before sorting: ");
    for(int i=0; i<n; i++)
    printf("%d, ", arr[i]);

    switch (opt)
    {
    case 1:
        bubbleSort(arr, n);
        break;
    case 2:
        selectionSort(arr, n);
        break;
    case 3:
        insertionSort(arr, n);
        break;
    default:
        printf("Invalid Input");
        break;
    }
    
    insertionSort(arr, n);
    printf("\nThe elements after sorting: ");
    for(int i=0; i<n; i++)
        printf("%d, ", arr[i]);

    return 0;
}