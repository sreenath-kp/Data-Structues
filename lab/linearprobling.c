#include <stdio.h>
#define size 10

void insert(int t[], int key)
{
    int k = key % size,i = 0;
    while (t[k] != -1)
    {
        k = (key + i) % size;
    }
    t[i] = key;
}
void display(int t[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", i);
        if (t[i] != -1)
            printf("  %d", t[i]);
        printf("\n");    
    }
}
void main()
{
    int op = 0, key;
    int t[size];
    for (int i = 0; i < size; i++)
        t[i] = -1;
    printf("1.Insert key\n2.Display\n3.Exit\n");
    do
    {
        printf("-: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("key: ");
            scanf("%d", &key);
            insert(t, key);
            break;
        case 2:
            display(t);
            break;
        case 3:
            return;
        default:
            printf("Invlid\n");
            break;
        }
    } while (1);
}