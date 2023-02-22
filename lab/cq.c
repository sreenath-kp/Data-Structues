#include <stdio.h>
#define max 5
int cq[max];
int f=-1,r=-1;
void dequeue()
{   
    if(f==-1&&r==-1)
    {
       printf("empty\n");
        return;
    }
    else if (f==r)
    {
        f=r=-1;
    }
    else
    {
        f=(f+1)%max;
    }
    
}
void insert(int item)
{
    if((r+1)%max == f)
    {
        printf("Overflow\n");
        return;
    }
    else if(f==-1&&r==-1)
    {
        f++;
    }
    r=(r+1)%max;
    cq[r]=item;
}
void display()
{
    if (f==-1)
    {
        printf("Empty\n");
        return;
    }
    for (int i = f; i != r; i=(i+1)%max)
    {
        printf("%d ",cq[i]);
    }
    printf("%d",cq[r]);
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