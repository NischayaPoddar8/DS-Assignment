#include<stdio.h>

typedef struct {
    int front,rear;
    int element[5];
}queue;

queue init(){
    queue q;
    q.front = q.rear = -1;
    return q;
}

int isEmpty(queue q){
    if(q.front>q.rear||q.front==-1) return 1;
    else return 0;
}

int isFull(queue q){
    if(q.rear == 4) return 1;
    else return 0;
}

int front(queue q){   // to get front element
    if(isEmpty(q)) printf("Empty");
    else return q.element[q.front];
} 

queue enqueue(queue q, int x){  // insert element at end
    if(isFull(q)) printf("OVERFLOW");
    else if(isEmpty(q)){
        q.rear = q.front = 0;  // first element inside queue
        q.element[q.rear] = x;
    }
    else{
        ++q.rear;
        q.element[q.rear] = x;
    }
    return q;
}

queue dequeue(queue q){
    if(isEmpty(q)) printf("UNDERFLOW");
    else{
        ++q.front;
    }
    return q;
}

void print(queue q){
    if(isEmpty(q)) printf("Queue is empty");
    else{
        for(int i=q.front;i<=q.rear;i++){
            printf("%d\n",q.element[i]);
        }
    }
}

int main(){
    queue Q;
    Q = init();  // queue is initialised
    Q = enqueue(Q,3);
    Q = enqueue(Q,2);
    Q = enqueue(Q,1);
    Q = enqueue(Q,6);
    Q = enqueue(Q,7);
    print(Q);
    Q = dequeue(Q);
    Q = dequeue(Q);
    print(Q);
    printf("front element is %d\n",front(Q));
}