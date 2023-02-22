#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int stack[40];
int top=-1;

void push(char item)
{
    top++;
    stack[top]=item;
}

char pop()
{
    if(top==-1)
        return -1;
    else
        return stack[top--];
}
void operate(char c)
{
    int result;
    switch(c)
    {
        case '+':
            result=stack[top-1]+stack[top];
            top--;
            stack[top]=result;
            break;
        case '-':
            result=stack[top-1]-stack[top];
            top--;
            stack[top]=result;
            break;

        case '*':
            result=stack[top-1]*stack[top];
            top--;
            stack[top]=result;
            break;

        case '/':
            result=stack[top-1]/stack[top];
            top--;
            stack[top]=result;
            break;


    }

}

void main()
{
    char q[30];
    int i=0;
    printf("Enter postfix: ");
    scanf(" %s",q);
    while(q[i]!='\0')
    {   
        if(isdigit(q+i))
            push(atoi(q+i));
        else
        {
            operate(q[i]);
        }
        i++;
    }
    printf("result :%d",stack[top]);
}