#include <stdio.h>

void merge(int a[],int l,int m,int h)
{
    int c[20];
    int i = l,j = m,k = 0;
    while (i<m && j<h)
    {
        if (a[i]<a[j])
        {
            c[k++] = a[i++];
        }
        else if (a[j]<a[i])
        {
            c[k++] = a[j++];
        }
        else
        {
            c[k++] = a[i++];
            j++;
        }
    }
    while (i<m)
    {
        c[k++] = a[i++];
    }
    while (j<h)
    {
        c[k++] = a[j++];
    }

    for (int i = 0; i < k; i++)
    {
        a[l+i] = c[i];
    }
}
void sort(int a[],int l,int h)
{
    if (h-l == 1)
    {
        return;
    }
    
    int m = (l+h)/2;
    sort(a,l,m);
    sort(a,m,h);
    merge(a,l,m,h);
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
    //divide
    //sort halves
    //merge
    sort(a,0,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
}
