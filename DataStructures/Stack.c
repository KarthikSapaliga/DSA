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
    printf("=============================================\n");
    printf("Stack Operations : \n");
    printf("---------------------------------------------\n");
    printf("1. push()\n");
    printf("2. pop()\n");
    printf("3. peek()\n");
    printf("4. isEmpty()\n");
    printf("5. isFull()\n");
    printf("6. size()\n");
    printf("7. display()\n");
    printf("\n[0] MENU\t[-1] EXIT\n");
    printf("=============================================\n");
}

int isFull(Stack s){
    return s.top == MAX_SIZE-1; 
}

int isEmpty(Stack s){
    return s.top == -1;
}

void push(Stack *s, int ele){
    if(isFull(*s)){
        printf("Error : <stack_overflow> cannot push element.\n");
    }else{
        s->arr[++s->top] = ele;
        printf("%d is pushed onto the stack.\n",ele);
    }
}

int pop(Stack *s){
    if(isEmpty(*s)){
        printf("Error : <stack_underflow> cannot pop element.\n");
    }else{
        printf("%d is popped from the stack.\n",s->arr[s->top]);
        return s->arr[s->top--];
    }
}

int peek(Stack s){
    if(isEmpty(s)){
        printf("Error : <empty_stack>\n");
    }else{
        printf("%d is peeked from the stack.\n",s.arr[s.top]);
        return s.arr[s.top];
    }
}

int size(Stack s){
    return s.top+1;
}

void display(Stack s){
    if(isEmpty(s)){
        printf("Error : <empty_stack>\n");
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
    size_t stack_size;
    
    init(&stack);
    menu();
    do{
        printf("Please enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 0: menu();
                    break;
            case 1: printf("Enter the element to push onto the stack : ");
                    scanf("%d",&element);
                    push(&stack, element);
                    break;
            case 2: pop(&stack);
                    break;
            case 3: peek(stack);
                    break;
            case 4: if(isEmpty(stack)){
                        printf("The stack is currently empty.\n");
                    }else{
                        printf("The stack is not empty.\n");
                    }break;
            case 5: if(isFull(stack)){
                        printf("The stack is currently full.\n");
                    }else{
                        printf("The stack is not full.\n");
                    }break;
            case 6: stack_size=size(stack);
                    printf("The stack size is : %d\n",stack_size);
                    break;
            case 7: printf("The elements in the stack are:\n");
                    display(stack);
                    break;
            case -1:printf("Exiting the program...\n");
                    break;
            default:printf("Invalid choice! Please choose a valid option.\n");
        }
    }while(choice != -1);
    return 0;
}