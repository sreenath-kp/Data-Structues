/* K P SREENATH
    S3 B2 34
    EX13  stack using Linked list
*/
#include <stdio.h>
#include <stdlib.h>

struct linkedlist
{
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

void push(node *head)
{
    int item;
    printf("Enter element: ");
    scanf("%d",&item);

    if (head == NULL){
        node* ptr = getNode();
        head -> link = ptr;
        ptr -> data = item;
    }

    else{

        node *ptr = getNode();
        ptr -> link = head -> link;
        head -> link = ptr;
        ptr -> data = item;
    }

}

void pop(node *head){
    int item;
    if(head == NULL || head->link== NULL)
    {
        printf("Stack underflow ! \n");
    }
    else
    {
        node * ptr = head -> link;
        item=ptr->data;
        head -> link = ptr -> link;
        free(ptr);
        printf("popped--%d\n",item);
    }
}

void printstack(node *head){
    if (head == NULL|| head->link== NULL){
        printf("Stack is empty !\n");
    }
    else 
    {
        node *ptr = head -> link;
        printf("---- Stack: ");
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
    printf("Operations:\n1.PUSH\n2.POP\n3.STOP\n-:");
    scanf("%d",&choice);
    if(choice==1)
    {
        push(head);
        printstack(head);
    }
    else if(choice==2)
    {
        pop(head);
        printstack(head);

    }
    else if(choice==3)
    {
        printf("program terminated..\n");
        return ;
    }
    else{
        printf("Invalid option..\n");
        return ;
    }
    }while(1);
}
    
