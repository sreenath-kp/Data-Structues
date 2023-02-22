#include <stdio.h>
void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void sort(int a[],int l,int h)
{
    if(l>=h)
    {
        return;
    }
    int s,e,pivot;
    s=l;
    e=h;
    pivot = a[(s+e)/2];
    int temp;
    while (s<=e)
    {
        while(a[s]<pivot)
            s++;
        while(a[e]>pivot)
            e--;
        if(s<=e)
        {
            temp=a[s];
            a[s]=a[e];
            a[e]=temp; 
            s++;
            e--;
        }
    }
    sort(a,l,e);
    sort(a,s,h);
}


void main()
{
    int a[20],n,l,h;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    l=0;
    h=n-1;
    sort(a,l,h);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
}