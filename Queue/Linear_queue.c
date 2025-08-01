#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *arr;
};

//Inserting an element in a queue
void enqueue(struct Queue *q, int val) {
    if(q->rear==q->size-1) {
        printf("Overflow");
        return;
    } else if(q->rear == -1 && q->front == -1) {
        q->front=q->rear=0;
    } else {
        q->rear++;
    }
    q->arr[q->rear]=val;
}

//Deleting the first element from the queue and returning it back
int dequeue(struct Queue *q) {
    if(q->front > q->rear || q->front == -1) {
        printf("Underflow");
        return -1;
    }

    q->front++;
    return q->arr[q->front-1];
}

//Returning the first element of the queue without deleting it
int peek(struct Queue *q) {
    if(q->front >= q-> rear || q->front == -1) {
        printf("Underflow");
        return -1;
    } else {
        return q->arr[q->front];
    }
}

//Desplaying the elements of the queue
void display(struct Queue *q) {
    int i = q->front;

    while(i<=q->rear) {
        printf("%d, ", q->arr[i]);
        i++;
    }
}

int main() {
    // int n, val;
    struct Queue q;

    // printf("\nEnter the size of the queue: ");
    // scanf("%d", &n);

    q.front=q.rear=-1;
    q.size=10;
    q.arr=(int *)malloc(q.size*sizeof(int));

    // printf("Enter the elements: ");
    // for(int i=0; i<n; i++) {
    //     scanf("%d", &val);
    //     enqueue(&q, val);
    // }

    enqueue(&q, 12);
    enqueue(&q, 13);
    enqueue(&q, 15);
    printf("\nElements before operation: ");
    display(&q);

    // enqueue(&q, 89);
    // printf("\nThe deleted element is %d", dequeue(&q));
    printf("\nThe first element is %d", peek(&q));
    printf("\nElements after operation: ");
    display(&q);
    
    return 0;
}