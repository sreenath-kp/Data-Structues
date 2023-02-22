
#include <stdio.h>
#include <stdlib.h>
struct linkedlist
{
    int data;
    struct linkedlist *link;
};
typedef struct linkedlist node;

node* getnode();
void printlist(node* head);
node *head=NULL,*ptr,*ptr2;

void main()
{
    int choice=0,item,key,flag=0;
    do{
    printf("---operations on linked list---\n1. Insert at Beginning\n2. Insert at End\n3. Insert at a specified Position\n4. Delete from a specified Position\n5. Delete from Beginning\n6. Delete from End\n7.stop\nchoice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        if(head==NULL)
        {
            head=getnode();
            printf("Enter data\n");
            scanf("%d",&item);
            head->data=item;
        }
        else{
            ptr=head;
            head=getnode();
            head->link=ptr;
            printf("Enter data\n");
            scanf("%d",&item);
            head->data=item;
        }
    printlist(head);
        break;
    case 2:
        if(head==NULL)
        {
            head=getnode();
            printf("Enter data\n");
            scanf("%d",&item);
            head->data=item;
        }
        else
        {  
            ptr=head;
            while(ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            ptr->link=getnode();
            ptr=ptr->link;
            printf("Enter data\n");
            scanf("%d",&item);
            ptr->data=item;
        }
    printlist(head);

        break;
    case 3:
    if(head==NULL)
    {
    printf("Empty list");
    break;
    }
    printf("Enter key:\n");
    scanf("%d",&key);
    ptr=head;
    while(ptr->link!=NULL)
        {
        if(ptr->data==key)
        {
        flag=1;
        break;
        }
            ptr=ptr->link;
}
if(flag==0)
{
printf("notfound\n");
}
else
{
ptr2=ptr->link;
ptr->link=getnode();
ptr=ptr->link;
printf("Enter data\n");
            scanf("%d",&item);
ptr->data=item;
ptr->link=ptr2;
}
printlist(head);
        break;
    case 4:
    if(head==NULL)
    {
    printf("Empty list");
    break;
    }
    printf("Enter key:\n");
    scanf("%d",&key);
    ptr=head;
    while(ptr->data!=key)
        {
        ptr2=ptr;
            ptr=ptr->link;
}
if(ptr->link==NULL)
{
printf("notfound\n");
}
else
{
ptr2->link=ptr->link;
free(ptr);
}
printlist(head);
break;
case 5:
if(head==NULL)
        {
            printf("Empty list\n");
        }
        else
        {
ptr=head;
head=ptr->link;
free(ptr);
printlist(head);
}
break;
case 6:
if(head==NULL)
        {
            printf("Empty list\n");
        }
        else
        {  
            ptr=head;
            while(ptr->link!=NULL)
            {
            ptr2=ptr;
                ptr=ptr->link;
            }
            ptr2->link=NULL;
            free(ptr);
            printlist(head);
        }
    break;
    case 7:
    return;
    }
}while(1);
   
}
node* getnode()
{
    node* ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->link = NULL;
    return ptr;
}
void printlist(node* head)
{
    printf("list\n");
if(head==NULL)
    {
        printf("Empty");
        return;
    }
    ptr=head;
    while(ptr->link!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("%d ",ptr->data);
    printf("\n");

}