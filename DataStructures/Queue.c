#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct{
    int arr[MAX_SIZE];
    int front;
    int rear;
}Queue;

void init(Queue *q){
    q->front = -1;
    q->rear = -1;
}

void menu(){
    printf("===================\n");
    printf("Queue Operations : \n");
    printf("-------------------\n");
    printf("1. enqueue()\n");
    printf("2. dequeue()\n");
    printf("3. peek()\n");
    printf("4. display()\n");
    printf("\n[0] MENU [-1] EXIT\n");
    printf("===================\n");
}

int isFull(Queue q){
    return q.rear == MAX_SIZE-1;
}

int isEmpty(Queue q){
    return q.rear == q.front;
}

void enqueue(Queue *q, int ele){
    if(isFull(*q)){
        fprintf(stderr,"ERROR : Queue Overflow\n");
        exit(EXIT_FAILURE);
    }else{
        q->arr[++q->rear] = ele;
    }
}

int dequeue(Queue *q){
    if(isEmpty(*q)){
        fprintf(stderr,"ERROR : Queue Underflow\n");
        exit(EXIT_FAILURE);
    }else{
        return q->arr[q->front++];
    }
}

int peek(Queue q){
    if(isEmpty(q)){
        fprintf(stderr,"ERROR : Queue Underflow\n");
        exit(EXIT_FAILURE);
    }else{
        return q.arr[q.front];
    }
}

void display(Queue q){
    if(isEmpty(q)){
        fprintf(stderr,"ERROR : Queue Underflow\n");
        exit(EXIT_FAILURE);
    }else{
        for(int i=q.front; i<=q.rear; i++){
            printf("%d ",q.arr[i]);
        }
    }
}

int main(){
    
    return 0;
}