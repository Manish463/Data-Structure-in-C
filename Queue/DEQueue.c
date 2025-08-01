#include <stdio.h>
#include <stdlib.h>

struct DEq {
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueueF(struct DEq *q, int val) {
    if (q->front == 0) {
        printf("The queue has no space to insert element to front side");
        return;
    } else if (q->front == -1) {
        q->front = q->rear = 0;
    } else {
        q->front--;
    }
    q->arr[q->front] = val;
}

void enqueueR(struct DEq *q, int val) {
    if (q->rear == q->size-1) {
        printf("The queue has no space to insert element to rear side");
        return;
    } else if (q->front == -1) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear] = val;
}

int dequeueF(struct DEq *q) {
    int val;

    if (q->front == -1) {
        printf("The queue is empty.");
        val = -1;
    } else if (q->front == q->rear) {
        val = q->arr[q->front];
        q->front = q->rear = -1;
    } else {
        val = q->arr[q->front];
        q->front++;
    }

    return val;
}

int dequeueR(struct DEq *q) {
    int val;

    if (q->rear == -1) {
        printf("The queue is empty.");
        val = -1;
    } else if (q->front == q->rear) {
        val = q->arr[q->rear];
        q->front = q->rear = -1;
    } else {
        val = q->arr[q->rear];
        q->rear--;
    }

    return val;
}

void printQueue(struct DEq *q) {
    if (q->front == -1) {
        printf("Queue is empty");
        return;
    }

    printf("The queue elements are: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d, ", q->arr[i]);
    }
}

int main() {
    struct DEq q;

    q.front=q.rear=-1;
    q.size=5;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueueR(&q, 23);
    enqueueR(&q, 24);
    enqueueR(&q, 25);
    enqueueR(&q, 26);
    enqueueR(&q, 27);
    dequeueF(&q);
    dequeueR(&q);
    dequeueF(&q);
    dequeueR(&q);
    enqueueF(&q, 100);
    enqueueF(&q, 101);
    enqueueR(&q, 100);
    enqueueR(&q, 101);
    printQueue(&q);
    
    return 0;
}