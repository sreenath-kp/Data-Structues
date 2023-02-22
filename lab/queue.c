#include <stdio.h>
#define max 20
int queue[max];
int f=-1,r=-1;
void dequeue()
{   
    int item;
    if(f==-1&&r==-1)
    {
       printf("empty");
        return;
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
    
}
void insert(int item)
{
    if(f==-1&&r==-1)
    {
        f++;
    }
    else if(r==max)
    {
        printf("Overflow");
        return;
    }
    queue[++r]=item;
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
void main()
{
    int op = 0,item;
    printf("1.Insert\n2.Remove\n3.Display\n4.Exit\n");
    do
    {
        printf("-: ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("Item: ");
            scanf("%d",&item);
            insert(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display(); 
            break; 
        case 4:
            return;          
        default:
            printf("Invalid\n");
            break;
        }
    } while (1);
    
}