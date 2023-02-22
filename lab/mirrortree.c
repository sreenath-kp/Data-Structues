#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int value; //completed (simple tree)
    struct tree *rc;
    struct tree *lc;
} node;

node *getNode(int item)
{
    node *new = (node *)malloc(sizeof(node));
    new->lc = NULL;
    new->rc = NULL;
    new->value = item;
    return new;
}
node* create(node *ptr)
{
    int item;
    printf("Enter node value: ");
    scanf("%d", &item);
    if (item == -1)
    {
        return ptr;
    }
    ptr = getNode(item);
    printf("Left child of %d\n", item);
    ptr->lc = create(ptr->lc);
    printf("Right child of %d\n", item);
    ptr->rc = create(ptr->rc);
    return ptr;
}
void inorder(node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->lc);
        printf("%d ", ptr->value);
        inorder(ptr->rc);
    }
}
void mirror(node* head)
{
    if (head==NULL)
    {
        return;
    }
    node* temp = head->lc;
    head->lc = head->rc;
    head->rc = temp;
    mirror(head->lc);
    mirror(head->rc);

}
void main()
{
    node* root = NULL;
    root = create(root);
    inorder(root);
    printf("\n");
    mirror(root);
    inorder(root);
    printf("\n");
}