#include <stdio.h>
#include <stdlib.h>
int top=-1;
int max;
int* allocate()
{
    printf("size?");
    scanf("%d",&max);
    int *ptr =(int*)malloc(max*sizeof(int));
    return ptr;
}
void display(int *stack)
{
    if(top==-1)
    {
        printf("stack empty\n");
        return;
    }
    printf("stack:");
    for(int i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
void push(int *stack)
{
    int item;
    if(top==max-1)
    {
        printf("stack overflow\n");
        return;
    }
    printf("enter item: ");
    scanf("%d",&item);
    top++;
    stack[top]=item;
    display(stack);

}
void pop(int *stack)
{
    if(top==-1)
    {
        printf("stack underflow\n");
        return;
    }
    printf("popped-%d\n",top--);
    display(stack);
}

void main()
{
    int choice,item;
    int *stack=allocate();
 do{printf("--operations--\n1.push\n2.pop\n3.stop\nchoice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        push(stack);
        break;
    case 2:
        pop(stack);
        break;
    case 3:
        return;
    default:
        printf("invalid option\n");
        break;
    }
 }while(1);
}