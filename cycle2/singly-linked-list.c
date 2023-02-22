#include <stdio.h>
#include <stdlib.h>

struct linkedlist{
    int data;
    struct linkedlist *link;
};

typedef struct linkedlist node;

node* getNode(){
    node* ptr = (node *)malloc(sizeof(node));
    ptr -> link = NULL;
    return ptr;
}

node *head = NULL;

void printLinkedList(){
    if (head == NULL|| head->link== NULL){
        printf("the linked list is empty !\n");
    }
    else {
        node *ptr = head -> link;
        printf("----Linked List: ");
        while(ptr -> link  != NULL){
            printf("%d ", ptr -> data);
            ptr = ptr -> link;
        }
        printf("%d \n", ptr -> data) ;
    }
}

void insertAtBegin(int val){
    if (head == NULL){
        head = getNode();
        node* ptr = getNode();
        head -> link = ptr;
        ptr -> data = val;
    }

    else{
        node *ptr = getNode();
        ptr -> link = head -> link;
        head -> link = ptr;
        ptr -> data = val;
    }
}

void insertAtEnd(int val){
    if (head == NULL){
        head = getNode();
        node* ptr = getNode();
        head -> link = ptr;
        ptr -> data = val;
    }

    else {
        node* ptr = head;
        while (ptr -> link != NULL){
            ptr = ptr -> link;
        }
        node* ptrend = getNode();
        ptr -> link = ptrend;
        ptrend -> data = val;
    }
}

void insertAtPosition(int val, int key){
    if (head == NULL){
        printf("empty linked list !\n");
    }
    else{
        node* ptr = head;
        int found = 0;
        while(ptr -> link != NULL){
            if(ptr -> data == key){
                node * ptrpos = getNode();
                ptrpos -> link = ptr -> link;
                ptr -> link = ptrpos;
                ptrpos -> data = val;
                found = 1;
                break;
            }
            ptr = ptr -> link;
        }
        if(!found){
            printf("no such position \n");
        }
    }
}

void deleteAtFront(){
    if(head == NULL || head->link== NULL)
        printf("the linked list is empty ! \n");
    else {
        node * ptr = head -> link;
        head -> link = ptr -> link;
        free(ptr);
    }
}

void deleteAtEnd(){
    if(head == NULL || head->link== NULL){
        printf("the linked list is empty ! \n");
    }
    else {
        node * ptr = head;
        while(ptr -> link -> link != NULL){
            ptr = ptr -> link;
        }
        free(ptr -> link);
        ptr -> link = NULL;
    }
}

void deleteFromPosition(int key){
    int found = 0;
    if(head == NULL|| head->link== NULL)
        printf("empty linked list ! \n");
    else {
        node * ptr = head;
        node * ptrpos ;
        while (ptr -> link != NULL){
            if (ptr -> link -> data == key){
                ptrpos = ptr -> link -> link;
                // printf("%d", ptrpos -> data);
                free(ptr -> link);
                ptr -> link = ptrpos;
                found = 1;
                break;
            }
            ptr = ptr -> link;
        }
        if (!found){
            printf("no such position\n");
        }
    }
}

void main(){
    int choice, key, val, cont=1;
    printf("\n---Operations on linked list---\n1. Insert at Beginning\n2. Insert at End\n");
    printf("3. Insert at a specified Position\n4. Delete from a specified Position\n5. Delete from Beginning\n6. Delete from End\n7.print linked list \n8. stop\n");
    do{
        printf("Choice : ");scanf("%d", &choice);
        switch (choice)
        {
        case 1:{
            printf("Enter data :"); scanf("%d", &val);
            insertAtBegin(val);
            break;
        }
        case 2:{
            printf("Enter data : "); scanf("%d", &val);
            insertAtEnd(val);
            break;
        }
        case 3:{
            printf("Enter the postion : "); scanf("%d", &key);
            printf("Enter data : "); scanf("%d", &val);
            insertAtPosition(val, key);
            break;
        }
        case 4:{
            printf("Enter the postion : "); scanf("%d", &key);
            deleteFromPosition(key);
            break;
        }
        case 5:{
            deleteAtFront();
            break;
        }
        case 6: {
            deleteAtEnd();
            break;
        }
        case 7:{
            printLinkedList();
            break;
        }
        case 8: {
            cont = 0;
            break;
        }

        }
    }while (cont);
}