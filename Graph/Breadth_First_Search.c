#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueue(struct queue *ptr, int val) {
    if(ptr->rear == ptr->size - 1) {
        printf("Overflow\n");
        return;
    } else if(ptr->front == -1) {
        ptr->front = ptr->rear = 0;
    } else {
        ptr->rear += 1;
    }
    ptr->arr[ptr->rear] = val;
}

int dequeue(struct queue *ptr) {
    if(ptr->front == -1 && ptr->front > ptr->rear) {
        printf("Underflow\n");
        return -1;
    } else {
        ptr->front += 1;
        return ptr->arr[ptr->front-1];
    }
}

int main() {
    struct queue q;
    q.front = q.rear = -1;
    q.size = 10;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int vertex;
    int i=5;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,0,0,1,1,0,0},
        {1,1,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);

    while(q.front != -1 || q.front <= q.rear) {
        vertex = dequeue(&q);

        for(int j=0; j<7; j++) {
            if(a[vertex][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    return 0;
}