#include <stdio.h>

int linear(int arr[], int n, int num) {

    for(int i=0; i<n; i++) {
        if(num == arr[i])
            return i;
    }
    return -1;
}
int main() {
    int arr[] = {3,4,13,5,67,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int num, idx;

    printf("\nThe elements are: ");
    for(int i=0; i<n; i++) 
        printf("%d, ", arr[i]);
    
    printf("\nEnter the number to find in the array: ");
    scanf("%d", &num);

    idx = linear(arr, n, num);

    if(idx != -1)
        printf("\n%d found at %d position", num, idx+1);
    else
        printf("\n%d is not found in the array", num);
    
    return 0;
}