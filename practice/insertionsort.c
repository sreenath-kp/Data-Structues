#include <stdio.h>
void main()
{
    int a[20];int n;
    printf("Enter size of list\n");
    scanf("%d",&n);
    printf("Enter the list of numbers\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int temp;
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1]) 
        {
            temp=a[i];
            a[i]=a[i-1];
            a[i-1]=temp;
            i=i-2;
        }
    }
    printf("sorted\n");
     for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}