#include <stdio.h>
#include <stdlib.h>
typedef struct linkedlist
{
    int data;
    struct linkedlist *link;
} node;
node *head = NULL;
void push(int item)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = item;
    new->link = NULL;
    node *ptr = head;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = new;
    }
}
void pop()
{
    node* ptr = head;
    if(head==NULL)
    {
        printf("Empty\n");
        return;
    }
    else if(head->link == NULL)
    {
        head = NULL;
    }
    else
    {
        while (ptr->link->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link = NULL;
        
    }
    
}
void display()
{
    node * ptr = head;
    if (ptr==NULL)
    {
        printf("Empty\n");
        return;
    }
    
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}
void main()
{
    int item, op = 0;
    printf("1.Push\n2.Pop\n3.Display\n");
    do
    {
        printf("-: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter item:");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        default:
            printf("INVALID");
            break;
        }
    } while (1);
}