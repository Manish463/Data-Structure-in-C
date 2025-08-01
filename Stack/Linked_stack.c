#include <stdio.h>
#include <stdlib.h>

// Stack node structure
typedef struct Node {
    int data;
    struct Node *next;
} node;

// Function to create a new node
node *createNode(int val) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
        return NULL;
    
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Push operation
node *push(node *top, int val) {
    node *newNode = createNode(val);
    if (!newNode) {
        printf("Stack Overflow!\n");
        return top;
    }

    newNode->next = top;
    top = newNode;
    printf("Element %d pushed to stack.\n", val);
    return top;
}

// Pop operation
node *pop(node *top) {
    if (!top) {
        printf("Stack Underflow! Stack is empty.\n");
        return top;
    }

    node *ptr = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(ptr);
    return top;
}

// Peek operation
int peek(node *top) {
    if (!top) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

// Display stack elements
void display(node *top) {
    if (!top) {
        printf("Stack is empty.\n");
        return;
    }

    node *ptr = top;
    printf("Stack elements (Top to Bottom): ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Main function with menu
int main() {
    node *top = NULL;
    int choice, val;

    do {
        printf("\n======= Stack Menu =======\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                top = push(top, val);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                val = peek(top);
                if (val != -1)
                    printf("Top element: %d\n", val);
                break;
            case 4:
                display(top);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
