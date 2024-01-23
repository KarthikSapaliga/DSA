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
        q->front++;
        printf("%d is deleted from the queue.\n",q->arr[q->front]);
        return q->arr[q->front];
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
        for(int i=q.front+1; i<=q.rear; i++){
            printf("%d ",q.arr[i]);
        }
        printf("\n");
    }
}

int main(){
    Queue queue;
    int choice,element;
    size_t queue_size;
    
    init(&queue);
    menu();
    do{
        printf("Please enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 0: menu();
                    break;
            case 1: printf("Enter the element to insert onto the queue : ");
                    scanf("%d",&element);
                    enqueue(&queue, element);
                    break;
            case 2: dequeue(&queue);
                    break;
            case 3: front(queue);
                    break;
            case 4: rear(queue);
                    break;
            case 5: if(isEmpty(queue)){
                        printf("The queue is currently empty.\n");
                    }else{
                        printf("The queue is not empty.\n");
                    }break;
            case 6: if(isFull(queue)){
                        printf("The queue is currently full.\n");
                    }else{
                        printf("The queue is not full.\n");
                    }break;
            case 7: queue_size=size(queue);
                    printf("The queue size is : %d\n",queue_size);
                    break;
            case 8: printf("The elements in the queue are:\n");
                    display(queue);
                    break;
            case -1:printf("Exiting the program...\n");
                    break;
            default:printf("Invalid choice! Please choose a valid option.\n");
        }
    }while(choice != -1);
    return 0;
}