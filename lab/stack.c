#include <stdio.h>
#include <ctype.h>
#define max 20
int stack[max];
int top = -1;

void push(int item)
{
    stack[++top] = item;
}
int pop()
{
    return stack[top--];
}

void main()
{
    int op1, op2;
    char pf[30], ch;
    printf("Enter postfix :\n");
    scanf(" %s", pf);
    int i = 0;
    while ((ch = pf[i]) != '\0')
    {
        if (isalnum(ch))
        {
            push(ch - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();
            switch (ch)
            {

            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            default:
                break;
            }
        }
        i++;
    }
    printf("RESULT : %d\n", stack[top]);
}