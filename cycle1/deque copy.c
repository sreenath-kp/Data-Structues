/*
    K P SREENATH
    Roll no: 34
    Cycle 2 EX06
    Deque implementation using array
*/
#include <stdio.h>
void display();
void insertfront();
void deletefront();
void insertrear();
void deleterear();

int dq[50],max,front=-1,rear=-1;
void main()
{
    int choice;
    printf("Enter the max size of deque : ");
    scanf("%d",&max);
    do{
    printf("\n---Operations---\n1.Insert at front\n2.Insert at rear\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Stop\nEnter choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
        {
            
            insertfront();
            break;
        }
        case 2:
        {
           
            insertrear();
            break;
        }
        
        case 3:
        {
            deletefront();
            break;
        }
        case 4:
        {
            deleterear();
            break;
        }
        case 5:
        {
            display();
            break;
        }
        case 6:
        {
            printf("--Terminated--\n");
            return;
        }
    }
    }while(1);
}
void insertfront()
{
    int item;
    if((front==0&&rear==max-1)||(rear+1==front))
    {
        printf("Overflow---\n");
        return;
    }
    else if(front==-1&&rear==-1)
    {
        front++;
        rear++;
    }
    else if(front==0)
    {
        front=max-1;
    }
    else
    {
        front--;
    }
    printf("Enter item: ");
    scanf("%d",&item);
    dq[front]=item;
    


}
void deletefront()
{
    int c = dq[front];
    if(front==-1&&rear==-1)
    {
        printf("Underflow---\n");
        return;
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else 
    {
        front=(front+1)%max;
    }
    printf("%d deleted---\n",c);
   
}
void insertrear()
{
    int item;
    if((front==0&&rear==max-1)||(rear+1==front))
    {
        printf("Overflow---\n");
        return;
    }
    else if(front==-1&&rear==-1)
    {
        front++;
        rear++;
    }
    else if(rear==max-1)
    {
        rear=0;
    }
    else
    {
        rear=(rear+1)%max;
    }
     printf("Enter item\n");
    scanf("%d",&item);
    dq[rear]=item;
    
}
void deleterear()
{
    int c = dq[rear];
    if(front==-1&&rear==-1)
    {
        printf("Underflow---\n");
        return;
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else 
    {
        rear=(rear-1)%max;
    }
    printf("%d deleted---\n",c);
    
}
void display()
{
    printf("Deque: ");
    for(int i=front;i!=rear;i=(i+1)%max)
    {
        printf("%d ",dq[i]);
        
    }
    if(rear!=-1&&front!=-1)
        printf("%d ",dq[rear]);
    else 
        printf("Empty");    
    printf("\n________________\n");

}