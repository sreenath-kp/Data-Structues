#include <stdio.h>
#include <stdlib.h>
#define size 10
typedef struct chaining
{
    int value;
    struct chaining *link;
} node;
node *t[size];
void insert(int key)
{
    node *ptr;
    node *temp = (node *)malloc(sizeof(node));
    temp->value = key;
    temp->link = NULL;
    int k = key % size;
    if (t[k] == NULL)
    {
        t[k] = temp;
    }
    else
    {
        ptr = t[k];
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}
void display()
{
    node *ptr;
    for (int i = 0; i < size; i++)
    {
        ptr = t[i];
        printf("%d ", i);
        while (ptr != NULL)
        {
            printf("%d  ", ptr->value);
            ptr = ptr->link;
        }
        printf("\n");
    }
}
void main()
{
    int op = 0, key;
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
            insert(key);
            break;
        case 2:
            display();
            break;
        case 3:
            return;
        default:
            printf("Invlid\n");
            break;
        }
    } while (1);
}