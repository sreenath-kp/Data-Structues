#include <stdio.h>
#include <ctype.h>
char stack[20],q[20];
int top = -1;
void push(char item)
{
    stack[++top] = item;
}
char pop()
{
    return stack[top--];
}
int priority(char op)
{
    switch (op)
    {
    case ')':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    case '(':
        return 0;
    default:
        return 0;
    }
}
void postfix(char d[])
{
    char ch;
    char *e = q;
    while (*d != '\0')
    {
        if (isalnum(*d))
        {
            *e++ = *d;
        }
        else if (*d == '(')
            push(*d);
        else if (*d == ')')
            while ((ch = pop()) != '(')
                *e++ = ch;
        else
        {
            while (priority(*d) < priority(stack[top]))
                *e++ = pop();
            push(*d);
        }
        d++;
    }
    while (top != -1)
    {
        *e++ = pop();
    }
}
void evaluate(char pf[])
{
    int i = 0;
    int op1, op2;
    char ch;
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
}
void main()
{
    char p[20], *e, ch;
    int i = 0;
    printf("Enter infix:\n");
    scanf(" %s", p);
    postfix(p);
    while (q[i] != '\0')
    {
        printf("%c", q[i++]);
    }
    printf("\n");
    evaluate(q);
    printf("RESULT : %d\n", stack[top]);
}