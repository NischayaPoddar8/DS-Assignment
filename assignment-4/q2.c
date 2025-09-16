#include<stdio.h>
#define MAX 5

typedef struct{
    int front,rear;
    int element[MAX];
}circularQueue;

circularQueue init(){
    circularQueue q;
    q.front = q.rear = -1;  // empty circular queue is initialised
    return q;
}

int isEmpty(circularQueue q){
    if(q.front == q.rear && q.rear == -1){
        return 1;
    }
    else return 0;
}

int isFull(circularQueue q){
    if(q.front == (q.rear+1)%MAX) return 1;
    else return 0;
}

circularQueue enqueue(circularQueue q, int x){
    // check overflow
    if(isFull(q)) printf("OVERFLOW");
    else if(q.front==-1){
        q.front = 0;
        q.rear = (q.rear+1)%MAX;
        q.element[q.rear] = x;
    }
    else{
        q.rear = (q.rear+1)%MAX;
        q.element[q.rear] = x;
    }
    return q;
}

circularQueue dequeue(circularQueue q){
    // check for underflow
    if(isEmpty(q)) printf("UNDERFLOW");
    else if(q.front == q.rear){
        // last element remains
        q.front = q.rear = -1;  // queue is now empty
    }
    else{
        q.front = (q.front + 1) % MAX;
    }
    return q;
}

void print(circularQueue q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = q.front;
    while (1) {
        printf("%d ", q.element[i]);
        if (i == q.rear) break;              // stop when we’ve printed last element
        i = (i + 1) % MAX;                   // wrap-around
    }
    printf("\n");
}


int main(){

    circularQueue Q;
    Q = init();
    Q = enqueue(Q,3);
    Q = enqueue(Q,7);
    Q = enqueue(Q,54);
    Q = enqueue(Q,6);
    Q = enqueue(Q,9);
    print(Q);
    Q = dequeue(Q);
    Q = dequeue(Q);
    print(Q);
    return 0;
}