#include <stdio.h>
void swap(int* x,int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void heapify(int a[],int n,int i)
{
    int large = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if (left<n && a[left]>a[large])
        large = left;
    if (right<n && a[right]>a[large])
        large = right;
    if(large != i)
    {    
        swap(&a[large],&a[i]);
        heapify(a,n,large);
    }
}
void heap_sort(int a[],int n)
{
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(a,n,i);
    }
    for (int i = n-1; i >=0; i--)
    {
        swap(&a[i],&a[0]);
        heapify(a,i,0);
    }
}
void main()
{
    int a[20],n;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    heap_sort(a,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
}