#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct{
    int arr[MAX_SIZE];
    int top;
}Stack;

void init(Stack *s){
    s->top = -1;
}

void menu(){
    printf("===================\n");
    printf("Stack Operations : \n");
    printf("-------------------\n");
    printf("1. push()\n");
    printf("2. pop()\n");
    printf("3. peek()\n");
    printf("4. display()\n");
    printf("\n[0] MENU [-1] EXIT\n");
    printf("===================\n");
}

int isFull(Stack s){
    return s.top == MAX_SIZE-1; 
}

int isEmpty(Stack s){
    return s.top == -1;
}

void push(Stack *s, int ele){
    if(isFull(*s)){
        fprintf(stderr,"ERROR : Stack Overflow\n");
        exit(EXIT_FAILURE);
    }else{
        s->arr[++s->top] = ele;
    }
}

int pop(Stack *s){
    if(isEmpty(*s)){
        fprintf(stderr,"ERROR : Stack Underflow\n");
        exit(EXIT_FAILURE);
    }else{
        return s->arr[s->top--];
    }
}

int peek(Stack *s){
    if(isEmpty(*s)){
        fprintf(stderr,"ERROR : Stack Underflow\n");
        exit(EXIT_FAILURE);
    }else{
        return s->arr[s->top];
    }
}

void display(Stack s){
    if(isEmpty(s)){
        fprintf(stderr,"ERROR : Stack Underflow");
    }else{
        for(int i=0; i<=s.top; i++){
            printf("%d ",s.arr[i]);
        }
        printf("\n");
    }
}

int main(){
    Stack stack;
    int choice,element;

    init(&stack);
    menu();
    do{
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 0: menu();
                    break;
            case 1: printf("Enter the element : ");
                    scanf("%d",&element);
                    push(&stack, element);
                    break;
            case 2: element = pop(&stack);
                    printf("Popped element : %d\n",element);
                    break;
            case 3: element = pop(&stack);
                    printf("Peeked element : %d\n",element);
                    break;
            case 4: printf("Stack elements are :\n");
                    display(stack);
                    break;
            case -1:printf("Exiting ...");
                    break;
            default:printf("Invalid Choice!\n");
        }
    }while(choice != -1);
    return 0;
}