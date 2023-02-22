/*
	K P SREEENATH
	Roll no:34
*/
#include <stdio.h>
int stack[20],top=-1, max;
void pop();
void push(int stack[]);
void printstack(int stack[]);
int main()
{
    printf("size of stack:\n");
    scanf("%d",&max);
    int choice;
do{
    printf("operations:\n1.PUSH\n2.POP\n3.STOP\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        push(stack);
        printstack(stack);
    }
    else if(choice==2)
    {
        pop();
        printstack(stack);
    }
    else if(choice==3)
    {
        printf("program terminated....\n");
        return 1;
    }
    else{
        printf("Invalid option....\n");
        return 1;
    }
    }while(1);
}		
void push(int stack[])
{
    int n;
    if(top>=max-1)
    {
        printf("stack overflow...\n");
	
    }else
    {
        printf("Enter element:\n");
        scanf("%d",&n);
        top=top+1;
        stack[top]=n;
    }
}
void pop()
{
    int item;
    if(top==-1)
    {
        printf("stack underflow...\n");
    }
    else
    {
        printf("pop executed--%d\n",stack[top]);
        top=top-1;
    }
}
void printstack(int stack[])
{
    printf("stack:\n");
    for(int i=0;i<=top;i++)
    {
        printf("%d\n",stack[i]);
    }
    printf("\n");
}