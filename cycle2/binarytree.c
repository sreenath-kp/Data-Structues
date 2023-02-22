#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *rc;
    struct tree *lc;
};
typedef struct tree node;
node *searchink(node *ptro, int key);


node *getNode()
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->rc = NULL;
    ptr->lc = NULL;
    return ptr;
}

void createnode(node *root)
{
    int item;
    
    if(root!=NULL)
    {
        printf("Enter item: ");
        scanf("%d", &item);
        root->data=item;
    }
    

}
void insertnode(node *root)
{
    int key, item;
    char option;
    printf("Enter key: ");
    scanf("%d", &key);
    node *ptr = searchink(root, key);
    if (ptr == NULL)
    {
        printf("Search unsuccessful: No insertion");
        return;
    }
    if (ptr->lc == NULL || ptr->rc == NULL)
    {
        do
        {
            printf("Insert options\nAs left child(L)\nAs right child(R)\nEnter option: ");
            scanf(" %c", &option);
            if (option == 'L')
            {
                if (ptr->lc == NULL)
                {
                    node *new = getNode();
                    printf("Enter item: ");
                    scanf("%d", &item);
                    new->data = item;
                    ptr->lc = new;
                }
                else
                {
                    printf("Left child alredy exist\n");
                }
            }
            else if (option == 'R')
            {
                if (ptr->rc == NULL)
                {
                    node *new = getNode();
                    printf("Enter item: ");
                    scanf("%d", &item);
                    new->data = item;
                    ptr->rc = new;
                }
                else
                {
                    printf("Right child alredy exist\n");
                }
            }
            else
            {
                printf("invalid option\n");
            }
        } while (option != 'R' && option != 'L');
    }
    else
    {
        printf("key node already full\n");
    }
}
void visit(node* ptr)
{
    printf("%d ",ptr->data);
}

void preorder(node *root)
{
    node *ptr = root;
    if (ptr != NULL)
    {
        visit(ptr);
        preorder(ptr->lc);
        preorder(ptr->rc);
    }
}

void inorder(node *root)
{
    node *ptr = root;
    if (ptr != NULL)
    {
        inorder(ptr->lc);
        visit(ptr);
        inorder(ptr->rc);
    }
}

void postorder(node *root)
{
    node *ptr = root;
    if (ptr != NULL)
    {
        postorder(ptr->lc);
        postorder(ptr->rc);
        visit(ptr);
    }
}

node *searchink(node *ptro, int key)
{
    node *ptr = ptro;
    if (ptr->data != key)
    {
        if (ptr->lc != NULL)
            searchink(ptr->lc, key);
        else if (ptr->rc != NULL)
            searchink(ptr->rc, key);
        else
            return NULL;
    }
    else
        return ptr;
}
node* search_parent(node *ptro,int key,node *prev)
{
    if(ptro==NULL) return NULL;
    if(ptro->data==key)
    {
        return prev;
    }
    else{
        search_parent(ptro->lc,key,ptro);
        search_parent(ptro->rc,key,ptro);
    }
    return prev;
}
void deletenode(node *root)
{
    int key;
    printf("Enter key: ");
    scanf("%d", &key);
    node *ptr=root;
    if(ptr==NULL)
    {
        printf("Tree empty\n");
        return;
    }
    node* parent=search_parent(root,key,NULL);
    if(parent!=NULL)
    {
        node*ptr1=parent->lc;
        node*ptr2=parent->rc;
        if(ptr1!=NULL)
        {
            if(ptr1->data==key)
            {
                if(ptr1->lc==NULL&&ptr1->rc==NULL)
                    parent->lc=NULL;
                else{
                    printf("not a leaf node\n");
                }
            }
            
        }
        else if(ptr2!=NULL)
        {
            if(ptr2->data==key)
            {
                if(ptr2->lc==NULL&&ptr2->rc==NULL)
                    parent->rc=NULL;
                else{
                    printf("not a leaf node\n");
                }
            }
            
        }
    }
    else{
        printf("node with key not found\n");
    }
}

void main()
{
    int option;
    node * root;
 do{printf("1.Create node\n2.Preorder traversal\n3.Inorder traversal\n4.Postorder traversal\n5.Delete node\n-: ");
    scanf("%d",&option);
    switch (option)
    {
    case 0:
        createnode(root);
        break;
    case 1:
        insertnode(root);
        break;
    case 2:
        preorder(root);
        break;
    case 3:
        inorder(root);
        break;
    case 4:
        postorder(root);
        break;
    case 5:
        deletenode(root);
        break;
    case 6:
        return;
    default:
        printf("invalid option\n");
        return;
    }
 }while(1);
}