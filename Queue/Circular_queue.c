#include <stdio.h>
#include<stdlib.h>

struct Cqueue {
    int size;
    int front;
    int rear;
    int *arr;
};

//Inserting an element in a queue
void enqueue(struct Cqueue *q, int val) {
    if((q->rear+1) % q->size == q->front) {
        printf("Queue is Full.\n");
        return;
    } else if (q->front==-1 && q->rear==-1) {
        q->front=q->rear=0;
    } else {
        q->rear=(q->rear+1)%q->size;
    }
    q->arr[q->rear] = val;
}

//Deleting the first element from the queue and returning it back
int dequeue(struct Cqueue *q) {
    int val;
    if(q->front == -1) {
        printf("Queue is Empty.\n");
        val = -1;
    } else if (q->front == q->rear) {
        val = q->arr[q->front];
        q->front = q->rear = -1;
    } else {
        val = q->arr[q->front];
        q->front = (q->front+1) % q->size;
    }
    return val;
}

//Returning the first element of the queue without deleting it
int peek(struct Cqueue *q) {
    if(q->front == -1) {
        printf("Queue is Empty.\n");
        return -1;
    } else {
        return q->arr[q->front];
    }
}

//Desplaying the elements of the queue
void display(struct Cqueue *q) {
    if (q->front == -1) {
        printf("Queue is Empty.\n");
        return;
    } else {
        int i=q->front;

        printf("Queue elements are: ");
        while(i <= q->rear) {
            printf("%d, ", q->arr[i]);
            i = (i+1) % q->size;
        }
    }
}

int main() {
    struct Cqueue q;
    
    q.front=q.rear=-1;
    q.size=5;
    q.arr=(int *)malloc(q.size*sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 13);
    enqueue(&q, 15);
    enqueue(&q, 12);
    enqueue(&q, 13);
    printf("\nThe circular queue elements before operation: ");
    display(&q);

    int val = dequeue(&q);
    enqueue(&q, 155);
    printf("\nThe circular queue elements after operation: ");
    display(&q);

    free(q.arr);
    return 0;
}