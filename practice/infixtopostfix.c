//////////////////////////// do on your own ////////////////////////////////////////
#include <stdio.h>
#include <ctype.h>

char stack[30];
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
    char p[30],q[30],a;
    int i=0,j=0,choice;
    printf("1.Infix to postfix\n2.Evaluate postfix\n3.stop\n-: ");
    switch(choice)
    {  
        case 1:
        printf("Enter infix expression: ");
        scanf("%s",p);
        printf("postfix of ");
        printf("%s:",p);
        while(p[i] !='\0')
        {
        if(isalnum(p[i])) 
                q[j++]=p[i];
            else if(p[i]=='(') 
                push('(');
            else if(p[i]==')')
                while((a=pop())!='(') 
                    q[j++]=a;
            else
            {   while(priority(stack[top]) >= priority(p[i]))
                    q[j++]=p[i];
                push(p[i]);
            }
            i++;
        }
        while(top != -1)
            q[j++]=pop();
        q[j]='\0';    
        printf(" %s\n",q);

        case 2:
        if(choice==2)
        {
            printf("Enter postfix: ");
            scanf(" %s",q);
        }
        

    }

    

}
