#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stack[20], top = -1;
void push(int);
char pop();
int priority(char i);

int main(void)
{
    int n, n1, n2, n3, num;
    char str[100];
    char *e, x;
    while (1)
    {
        printf("Operations:\n****\nConvert(1): \nEvaluate(2): \nEnd(3):\n*****\nYour Option: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the infix expression: ");
            scanf("%s", str);
            e = str;
            printf("Postfix : ");
            while (*e != '\0')
            {
                if (isalnum(*e))
                {
                    printf("%c", *e);
                }
                else if (*e == '(')
                {
                    push(*e);
                }
                else if (*e == ')')
                {
                    while ((x = pop()) != '(')
                        printf("%c", x);
                }
                else
                {
                    while (priority(stack[top]) >= priority(*e))
                        printf("%c", pop());
                    push(*e);
                }
                e++;
            }
            while (top != -1)
                printf("%c", pop());
            printf("\n");
            break;
        case 2:

            printf("Enter the expression :: ");
            scanf("%s", str);
            e = str;
            while (*e != '\0')
            {
                if (isdigit(*e))
                {
                    num = *e - 48;
                    push(num);
                }
                else
                {
                    n1 = pop();
                    n2 = pop();
                    switch (*e)
                    {
                    case '+':
                    {
                        n3 = n1 + n2;
                        break;
                    }
                    case '-':
                    {
                        n3 = n2 - n1;
                        break;
                    }
                    case '*':
                    {
                        n3 = n1 * n2;
                        break;
                    }
                    case '/':
                    {
                        n3 = n2 / n1;
                        break;
                    }
                    }
                    push(n3);
                }
                e++;
            }
            printf("\nThe result of expression %s  =  %d\n\n", str, pop());
            break;

        case 3:
            printf("Terminating all operations........\n");
            exit(1);
        }
        printf("\n-------------\n");
    }
}

int priority(char i)
{
    if (i == '(')
        return 0;
    else if (i == '+' || i == '-')
        return 1;
    else if (i == '*' || i == '/')
        return 2;
    return 0;
}

void push(int n)
{
    if (top == 19)
    {
        printf("Overflow!!\n ");
        return;
    }
    else
    {
        top += 1;
        stack[top] = n;
    }
}

char pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
