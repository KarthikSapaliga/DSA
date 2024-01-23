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
    printf("=============================================\n");
    printf("Queue Operations : \n");
    printf("---------------------------------------------\n");
    printf("1. enqueue()\n");
    printf("2. dequeue()\n");
    printf("3. front()\n");
    printf("4. rear()\n");
    printf("5. isEmpty()\n");
    printf("6. isFull()\n");
    printf("7. size()\n");
    printf("8. display()\n");
    printf("\n[0] MENU [-1] EXIT\n");
    printf("=============================================\n");
}

int isFull(Queue q){
    return q.rear == MAX_SIZE-1;
}

int isEmpty(Queue q){
    return q.rear == q.front;
}

void enqueue(Queue *q, int ele){
    if(isFull(*q)){
        printf("Error : <queue_overflow> cannot insert element.\n");
    }else{
        q->arr[++q->rear] = ele;
        printf("%d is inserted onto the queue.\n",ele);
    }
}

int dequeue(Queue *q){
    if(isEmpty(*q)){
        printf("Error : <queue_underflow> cannot delete element.\n");
    }else{
        printf("%d is deleted from the queue.\n",q->arr[q->front]);
        return q->arr[q->front++];
    }
}

int front(Queue q){
    if(isEmpty(q)){
        printf("Error : <empty_queue>\n");
    }else{
        printf("%d is the front element of the queue.\n",q.arr[q.front]);
        return q.arr[q.front];
    }
}

int rear(Queue q){
    if(isEmpty(q)){
        printf("Error : <empty_queue>\n");
    }else{
        printf("%d is the rear element of the queue.\n",q.arr[q.rear]);
        return q.arr[q.rear];
    }
}

int size(Queue q){
    return q.rear - q.front;
}

void display(Queue q){
    if(isEmpty(q)){
        printf("Error : <empty_queue>\n");
    }else{
        for(int i=q.front; i<=q.rear; i++){
            printf("%d ",q.arr[i]);
        }
    }
}

int main(){
    
    return 0;
}