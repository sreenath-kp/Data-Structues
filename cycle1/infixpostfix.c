#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;
void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char c)
{
    switch(c)
    {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default :
            return 0;                 
    }
}

void main()
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
            push(*d);
        else if (*d == ')')
            while ((c = pop()) != '(')
                printf("%c", c);
        else
        {
            while (priority(stack[top]) >= priority(*d))
                printf("%c", pop());
            push(*d);
        }
        d++;
    }
    while (top != -1)
        printf("%c", pop());
    printf("\n");    
}
