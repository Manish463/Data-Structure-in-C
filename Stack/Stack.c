#include <stdio.h>

// to insert an element at the top of the stack
void push(int arr[], int *top, int max, int val) {
    
    if(*top == max-1) {
        printf("Stack is full");
        return;
    }
    *top += 1;
    arr[*top] = val;
}

// to remove the top element of stack
int pop(int arr[], int *top) {
    int val;

    if(*top == -1) {
        printf("Stack is empty");
        return -1;
    }
    val = arr[*top];
    *top -= 1;
    return val;
}

// to see the top element without deleting it
int peek(int arr[], int top) {

    if(top == -1) {
        printf("The stack is empty");
        return -1;
    }
    return arr[top];
}

// to display the elements of the stack
void display(int arr[], int top) {

    printf("\nThe elements are: ");
    for(int i=0; i<=top; i++) {
        printf("%d, ", arr[i]);
    }
}

int main() {
    int arr[10];
    int n=sizeof(arr)/sizeof(arr[0]), top=-1, val, opt;

    printf("\n****MENU****\n");
    printf("\n1. PUSH");
    printf("\n2. POP");
    printf("\n3. PEEK");
    printf("\n4. DISPLAY");
    printf("\n5. Exit");

    do{
        printf("\n\nEnter your potion: ");
        scanf("%d", &opt);

        switch(opt) {
            case 1:
                printf("\nEnter the elements to insert: ");
                scanf("%d", &val);
                push(arr, &top, n, val);
                break;
            
            case 2:
                val = pop(arr, &top);
                if(val != -1)
                    printf("\nThe deleted value is %d", val);
                break;
            
            case 3:
                val = peek(arr, top);
                if(val != -1)
                    printf("\nThe top element of the stack is %d", val);
                break;
            
            case 4:
                display(arr, top);
                break;
        }
    } while(opt != 5);

    return 0;
}