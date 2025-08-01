#include <stdio.h>

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

int binary(int arr[], int st, int end, int num) {
    int mid;

    while (st <= end) {
        printf("%d %d %d\n", st, mid, end);
        mid = st + (end-st) / 2;

        if(arr[mid] < num) 
            st = mid + 1;
        else if(arr[mid] > num) 
            end = mid - 1;
        else 
            return mid;
    }
    return -1;
}

int main() {
    int arr[] = {3,4,13,5,67,19,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num, idx;
        
    bubbleSort(arr, n);
    printf("\nThe sorted elements are: ");
    for(int i=0; i<n; i++) 
        printf("%d, ", arr[i]);

    printf("\n\nEnter the number to find in the array: ");
    scanf("%d", &num);

    idx = binary(arr, 0, n-1, num);

    if(idx != -1)
        printf("\n%d found at %d position", num, idx+1);
    else
        printf("\n%d is not found in the array", num);
    
    return 0;
}