#include <stdio.h>
void insertion_sort(int a[], int n)
{
    int current, j;
    for (int i = 1; i < n; i++)
    {
        current = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (current < a[j])
            {
                a[j + 1] = a[j];
            }
            else
                break;
        }
        a[j + 1] = current;
    }
}
void selection_sort(int b[], int n)
{
    int i, min, m;
    for (i = 0; i < n; i++)
    {
        min = i;
        m = b[i];
        for (int j = i + 1; j < n; j++)
        {
            if (b[j] < b[min])
            {
                min = j;
            }
        }
        b[i] = b[min];
        b[min] = m;
    }
}
void bubble(int a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}
void main()
{
    int a[20], b[20], c[20], n;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
        c[i] = a[i];
    }
    insertion_sort(a, n);
    selection_sort(b, n);
    bubble(c, n);
    printf("sorted:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}