/* K P SREENATH
    S3 B2 34
    EX14  Queue using Linked list
*/
#include <stdio.h>
#include <stdlib.h>

struct linkedlist{
    int data;
    struct linkedlist *link;
};

typedef struct linkedlist node;

node* getNode()
{
    node* ptr;
    ptr = (node*)malloc(sizeof(node));
    if(ptr==NULL){
        printf("Insufficient memory");
    }
    ptr->link = NULL;
    return ptr;
}

void delete(node *head){
    int item;
    if(head == NULL || head->link== NULL)
    {
        return;
    }
    else
    {
        node * ptr = head -> link;
        item=ptr->data;
        head -> link = ptr -> link;
        free(ptr);
        printf("Deleted--%d\n",item);
    }
}

void insert(node *head){
    int item;
    printf("Enter element:");
    scanf("%d",&item);

    if (head == NULL){
        node* ptr = getNode();
        head -> link = ptr;
        ptr -> data = item;
    }

    else {
        node* ptr = head;
        while (ptr -> link != NULL){
            ptr = ptr -> link;
        }
        node* ptrend = getNode();
        ptr -> link = ptrend;
        ptrend -> data = item;
    }
}

void printque(node *head){
    if (head == NULL|| head->link== NULL){
        printf("Queue is empty !\n");
    }
    else 
    {
        node *ptr = head -> link;
        printf("---- Queue: ");
        while(ptr -> link  != NULL){
            printf("%d ", ptr -> data);
            ptr = ptr -> link;
        }
        printf("%d \n", ptr -> data) ;
    }
}

void main()
{
    node *head=getNode();
    int choice;
    do{
        printf("Operations:\n1.Insert\n2.Delete\n3.Terminate\n-: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                insert(head);
                printque(head);
                break;
            case 2:
                delete(head);
                printque(head);
                break;
            case 3:
                return;
            default:
                return;
       }
    }while(1);
}  