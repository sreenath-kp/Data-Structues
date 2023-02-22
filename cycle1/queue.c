#include <stdio.h>



void main(){
    int que[50], size, choice, front=-1, rear=-1, i=1;
    printf("Enter the size of queue: ");
    scanf("%d", &size);

    while(i){
        printf("--- Operations:\n");
        printf("1 : Enqueue\n");
        printf("2 : Dequeue\n");
        printf("3 : Terminate\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            
            if (rear == size-1){
                printf("overflow...\n");
                printf("Queue: \n");
                for (int i = front; i < rear+1; i++)
                {
                    printf("%d ", que[i]);
                }
                printf("\n");
                break;
            }
            else if(front==-1 && rear == -1){
                printf("Enter element:\n");
                front++;
                scanf("%d", &que[++rear]);
            }
            else 
            {
                printf("Enter element:\n");
                scanf("%d", &que[++rear]);
            }

            printf("Queue: \n");
            for (int i = front; i < rear+1; i++)
            {
                printf("%d ", que[i]);
            }
            printf("\n");
            
            break;
        
        case 2:
            if (rear == front-1){
                printf("underflow...\n");
                rear = -1;
                front = -1;
                break;
            }
            else if(front==-1 && rear == -1){
                printf("Queue: \n");
                printf("underflow...\n");
                break;
            }
            else{
                printf("element: %d dequeued\n", que[front++]);
            }
            printf("Queue: ");
            for (int i = front; i < rear+1; i++)
            {
                printf("%d ", que[i]);
            }
            printf("\n");
            break;
        case 3:{
            i--;
            break;
        }
        default:
            break;
        }




    }
}