#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *front = NULL; // Front = Tail;
node *rear = NULL;  // Rear = Head;

node *createNode(int val) {
    node *n = (node*)malloc(sizeof(node));
    n->data = val;
    n->next= NULL;
    return n;
}

void enqueue(int val){
    node *newNode = createNode(val);
    if(newNode==NULL){
        printf("\nThe QUEUE is full.\n");
    }
    else{
        if(front==NULL && rear == NULL){
            front= newNode;
            rear= newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }
}



int dequeue(){
    if(front==NULL){
        printf("\nThe QUEUE is empty\n");
        return -1;
    }
    else{
        int val = front->data;
        node *prev = front;
        front = front->next;
        free(prev);
        return val;
    }
}

// Display front ---> rear
void display(){
    node *n;
    if(front==NULL){
        printf("\nThe QUEUE is empty\n");
    }
    else{
        n = front;
        while(n!=NULL){
            printf("%d\t",n->data);
            n= n->next;
        }
    }
}

int peek(){
    node *n;
    if(front==NULL){
        printf("\nThe QUEUE is empty\n");
    }
    else{
        return rear->data;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    display();
    return 0;
}