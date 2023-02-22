/*
    K P SREEENATH
    rollno:34
*/
#include <stdio.h>
void display();
void delete();
void insert();

 int que[50], size, choice, front=-1, rear=-1, i=1;
void main(){
   
    printf("Enter the size of Cqueue: ");
    scanf("%d", &size);

    while(i){
        printf("--- Operations:\n");
        printf("1 : Insert\n");
        printf("2 : Delete\n");
        printf("3 : Terminate\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        insert();
            printf("Cqueue: \n");
            display();
            break;
        case 2:
            delete();
            printf("Cqueue: ");
            display();
            break;
        case 3:
            i--;
            break;
       
        default:
            break;
        }
}
}
void display()
{
    for(int i=front;i!=rear;i=(i+1)%size)
        printf("%d ",que[i]);
    if(rear!=-1&&front!=-1)
        printf("%d \n",que[rear]);
    else 
        printf("Empty\n");    

}
void insert()
{
    if ((rear == size-1 && front==0)||(rear+1==front)){
                printf("Overflow...\n");
               
            }
            else if(front==-1 && rear == -1){
                printf("Enter element:\n");
                front++;
                scanf("%d", &que[++rear]);
            }
            else
            {
                printf("Enter element:\n");
                rear=(rear+1)%size;
                scanf("%d", &que[rear]);
            }
}
void delete()
{
    int c;
if (front==-1)
    {
        printf("underflow...\n");
               
    }
       
    else if(front==rear)
    {
        c=que[front];
        rear = -1;
        front = -1;
    }
    else
    {
        c=que[front];
        front=(front+1)%size;
        printf("Deleted element: %d \n", c);
    }
}