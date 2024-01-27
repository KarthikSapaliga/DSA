#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void menu(){
    printf("=============================================\n");
    printf("Linkedlist Operations : \n");
    printf("---------------------------------------------\n");
    printf("1. insertAtBegining()\n");
    printf("2. insertAtEnd()\n");
    printf("3. insertAtPosition(loc)\n");
    printf("4. deleteAtBegining()\n");
    printf("5. deleteAtEnd()\n");
    printf("6. deleteAtLocation(loc)\n");
    printf("7. size()\n");
    printf("8. display()\n");
    printf("\n[0] MENU\t[-1] EXIT\n");
    printf("=============================================\n");
}

node *getNode(int data){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

int isEmpty(node *head){
    return head == NULL;
}

node *insertAtBegining(node *head, int data){
    node *new = getNode(data);
    new->next = head;
    head = new;
    return head;
}

node *insertAtEnd(node *head, int data){
    node *new = getNode(data);
    if(isEmpty(head)){
        head = new;
    }else{
        node *last = head;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = new;
    }
    return head;
}

node *insertAtPosition(node *head, int data, int pos){
    if(pos < 1){
        printf("error : <invalid_position>\n");
    }else{
        node *new = getNode(data);
        if(pos == 1){
            head = insertAtBegining(head,data);
        }else{
            node *ptr = head;
            for(int i=1; i<pos-1 && ptr != NULL; i++){
                ptr = ptr->next;
            }
            if(ptr == NULL){
                printf("error : <invalid_position>\n");
            }else{
                new->next = ptr->next;
                ptr->next = new;
            }
        }
    }
    return head;
}

node *deleteAtBegining(node *head){
    if(isEmpty(head)){
        printf("error : <empty_list>\n");
    }else{
        node *ptr = head;
        head = head->next;
        free(ptr);
    }
    return head;
}

node *deleteAtEnd(node *head){
    if(isEmpty(head)){
        printf("error : <empty_list>\n");
    }else if(head->next == NULL){
        free(head);
        head = NULL;
    }else{
        node *last = head;
        while(last->next->next != NULL){
            last = last->next;
        }
        free(last->next);
        last->next = NULL;
    }
    return head;
}

node *deleteAtPosition(node *head, int pos){
    if(pos < 1){
        printf("error : <invalid_position>\n");
    }else if(pos == 1){
        head = deleteAtBegining(head);
    }else{
        node *ptr = head;
        for(int i=1; i<pos-1 && ptr != NULL &&ptr->next != NULL; i++){
            ptr = ptr->next;
        }
        if(ptr == NULL || ptr->next == NULL){
            printf("error : <invalid_position>\n");
        }else{
            node *temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
        }
    }
    return head;
}

int size(node *head){
    int count = 0;
    node *ptr = head;
    while(ptr != NULL){
        ptr = ptr->next;
        count++;
    }
    return count;
}

void display(node *head){
    node *ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    node *head = NULL;
    int choice,element,pos;
    size_t list_size;
    menu();
    do{
        printf("Please enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 0: menu();
                    break;
            case 1: printf("Enter the element to insert onto the list : ");
                    scanf("%d",&element);
                    head = insertAtBegining(head,element);
                    break;
            case 2: printf("Enter the element to insert onto the list : ");
                    scanf("%d",&element);
                    head = insertAtEnd(head,element);
                    break;
            case 3: printf("Enter the element to insert onto the list : ");
                    scanf("%d",&element);
                    printf("Enter the position : ");
                    scanf("%d",&pos);
                    head = insertAtPosition(head,element,pos);
                    break;
            case 4: head = deleteAtBegining(head);
                    break;
            case 5: head = deleteAtEnd(head);
                    break;
            case 6: printf("Enter the position : ");
                    scanf("%d",&pos);
                    head = deleteAtPosition(head,pos);
                    break;
            case 7: list_size = size(head);
                    printf("The list size is : %d\n",list_size);
                    break;
            case 8: if(isEmpty(head)){
                        printf("error : <empty_list>\n");
                    }else{
                        printf("Elements in the list are : ");
                        display(head);
                    }
                    break;
            case -1:printf("Exiting the program...\n");
                    break;
            default:printf("Invalid choice! Please choose a valid option.\n");
            
        }
    }while(choice != -1);
    return 0;
}