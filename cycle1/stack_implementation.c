
/*
    K P SREEENATH
    rollno:34
*/
#include <stdio.h>
#include <ctype.h>
#include<math.h>

char stack[100];
int top = -1;



void push1(char c)
{
    stack[++top] = c;
}

char pop1()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char c)
{
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

void infixtopostfix()
{
    char infix[100];
    char c, *d;
    printf("enter the infix expression: ");
    scanf("%s", infix);
    printf("postfix:\n");
    d = infix;

    while (*d != '\0')
    {

        if (isalnum(*d))
            printf("%c", *d);
        else if (*d == '(')
            push1(*d);
        else if (*d == ')')
            while ((c = pop1()) != '(')
                printf("%c", c);
        else
        {
            while (priority(stack[top]) >= priority(*d))
                printf("%c", pop1());
            push1(*d);
        }
        d++;
    }
    while (top != -1)
        printf("%c", pop1());
    printf("\n");    
}
#define max 20

void push(int x){
    if(top==max-1)
        return;
    top++;
    stack[top]=x;
}

void pop(int op){
    if(top<1)
        return;
    top--;
    switch(op)
    {
        case 1:stack[top]=stack[top]+stack[top+1];
            break;
        case 2:stack[top]=stack[top]-stack[top+1];
            break;
        case 3:stack[top]=stack[top]*stack[top+1];
            break;
        case 4:stack[top]=stack[top]/stack[top+1];
            break;
    }

}

int operator(char ch)
{
    switch(ch)
    {
        case '+':return 1;
        case '-':return 2;
        case '*':return 3;
        case '/':return 4;
        default: return 0;
    }
}

void main()
{
    char Q[max];
    int i,j;
    printf("Enter Postfix expression: ");
    scanf(" %s",Q);
    for(i=0;Q[i]!='\0';i++)
    {
        if(Q[i]>='0'&&Q[i]<='9')
            push(Q[i]-'0');
        else
            pop(operator((int)Q[i]));
    }
    printf("Evaluated result: %d\n",stack[top]);
}
