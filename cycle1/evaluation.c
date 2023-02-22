//EVALUATION OF POSTFIX EXPRESSION

#include<stdio.h>
#include<math.h>
#define max 20

int stack[max],top=-1;

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
        case 5:stack[top]=pow(stack[top],stack[top+1]);
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
        case '^':return 5;
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