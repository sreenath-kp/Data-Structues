#include <stdio.h>
#define max 20
int queue[20];
int f=-1,r=-1;
int stack[20];
int top = -1;
void push(int item)
{
    stack[++top] = item;
}
int pop()
{
    return stack[top--];
}
int dequeue()
{   
    int item;
    if(f==-1&&r==-1)
    {
       printf("queue empty\n");
        return -1;
    }
    else if (f==r)
    {
        item=queue[f];
        f=r=-1;
    }
    else
    {
        item=queue[f++];
    }
    return item;
    
}
void insert(int item)
{
    if(f==-1&&r==-1)
    {
        f++;
    }
    else if(r==max)
    {
        printf("Overflow\n");
        return;
    }
    queue[++r]=item;
}
void create()
{
    int op = 0,n;
    printf("Create queue\n");
    printf("1.Insert\n2.Delete\n3.Finish\n");
    do
    {
        printf("-: ");
        scanf("%d",&op);
        
        switch (op)
        {
        case 1:
            printf("Enter item: ");
            scanf("%d",&n);
            insert(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            return;
        default:
            break;
        }
    } while (1);
}
void display()
{
    if (f==-1)
    {
        printf("Empty\n");
        return;
    }
    for (int i = f; i <= r; i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
    
}
void reverse()
{
    printf("REVERSE\n");
    for(int i = f;i<=r;i++)
    {
        push(dequeue());
    }
    while (top != -1)
    {
        insert(pop());
    }
    display();
}
void main()
{
    create();
    display();
    reverse();
}