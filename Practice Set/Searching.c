#include <stdio.h>

int linearSearch(int arr[], int n, int num) {
    int idx = -1;

    for(int i=0; i<n; i++) {
        if (num == arr[i]) {
            idx = i;
        }
    }
    return idx;
}

int binarySearch(int arr[], int n, int num) {
    int idx = -1;
    int beg=0, mid, end=n-1;

    while(beg <= end) {
        mid = (beg + end) / 2;

        if(num < arr[mid]) {
            end = mid - 1;
        } else if (arr[mid] < num) {
            beg = mid + 1;
        } else {
            idx = mid;
            break;
        }
    }
    return idx;
}

void bubbleSort(int arr[], int n) {
    int temp;

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {1,12,34,72,19,10};
    int num, idx, opt, n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    
    printf("\n---- Searching Menu ----\n");
    printf("1 for Linear Search\n");
    printf("2 for Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &opt);

    printf("\nEnter the number to search: ");
    scanf("%d", &num);

    switch(opt) {
        case 1:
            idx = linearSearch(arr, n, num);
            break;
        case 2:
            bubbleSort(arr, n);
            idx = binarySearch(arr, n, num);
            break;
        default:
            printf("Invalid option");
    }

    if(idx != -1) 
        printf("\nThe element %d is found on the index %d", num, idx);
    else
        printf("\nThe element %d is not found in the array.", num);
    
    return 0;
}