#include <stdio.h>
#include <stdlib.h>
typedef struct linkedlist
{
    int data;
    int priority;
    struct linkedlist *link;
} node;
node *head = NULL;
void insert(int item, int p)
{
    node *ptr, *prev;
    node *new = (node *)malloc(sizeof(node));
    new->data = item;
    new->priority = p;
    new->link = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else if (head->priority > p)
    {
        ptr = head;
        head = new;
        new->link = ptr;
    }
    else
    {
        ptr = head;
        prev = NULL;

        while (ptr != NULL && ptr->priority <= p)
        {
            prev = ptr;
            ptr = ptr->link;
        }
        new->link = ptr;
        prev->link = new;
    }
}
void deque()
{
    node *ptr = head;
    if (head == NULL)
    {
        printf("Empty\n");
        return;
    }
    else if (head->link == NULL)
    {
        head = NULL;
    }
    else
    {
        head = head->link;
    }
}
void display()
{
    node *ptr = head;
    if (ptr == NULL)
    {
        printf("Empty\n");
        return;
    }

    while (ptr != NULL)
    {
        printf("%d(%d) ", ptr->data, ptr->priority);
        ptr = ptr->link;
    }
    printf("\n");
}
void main()
{
    int item, p, op = 0;
    printf("1.insert\n2.dequeue\n3.Display\n");
    do
    {
        printf("-: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter item:");
            scanf("%d", &item);
            printf("Priority:");
            scanf("%d", &p);
            insert(item, p);
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        default:
            printf("INVALID");
            break;
        }
    } while (1);
}