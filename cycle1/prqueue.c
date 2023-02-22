

#include<stdio.h>
#include<stdlib.h>

int **PQ,**end,max=5,n;

void push(int pr){
    if((end[pr][0]+1)%max==end[pr][1])
    {
        printf("Priority Overflow");
        return;
    }
    int x;
    if(end[pr][1]==-1)
        end[pr][1]++;
    printf("Enter number to push: ");
    scanf("%d",&x);
    printf("Element %d pushed",x);
    end[pr][0]=(end[pr][0]+1)%max;  
    PQ[pr][end[pr][0]]=x;
}

void pop(){
    int i;
    for(i=0;i<n;i++)
        if(end[i][1]!=-1)
            break;
    if(i==n)
    {
        printf("Underflow");
        return;
    }
    printf("Element %d popped",PQ[i][end[i][1]]);
    if(end[i][0]==end[i][1])
        end[i][0]=end[i][1]=-1;
    else
        end[i][1]=(end[i][1]+1)%max;
}

void display()
{
    int i,j;
    printf("Priority Queue: ");
    for(i=0;i<n;i++)
        if(end[i][0]!=-1)
        {
            for(j=end[i][1];j!=end[i][0];j=(j+1)%max)
                printf("%d ",PQ[i][j]);
            printf("%d ",PQ[i][j]);
        }
        printf("\n");

}

void main()
{
    printf("Enter max priority: ");
    scanf("%d",&n);
    n++;
    PQ=(int**)malloc((n)*sizeof(int*));
    end=(int**)malloc((n)*sizeof(int*));

    for(int i=0;i<n;i++)
    {
        PQ[i]=(int*)malloc(max*sizeof(int));
        end[i]=(int*)malloc(2*sizeof(int));
        end[i][0]=end[i][1]=-1;
    }

    int pr,ch;
    do
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Stop\nYour choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Priority?:");scanf("%d",&pr);
                   push(pr);break;
            case 2:pop();break;
            case 3:display();break;
        }
    }while(ch!=4);
}