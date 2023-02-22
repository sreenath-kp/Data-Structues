/* K P SREENATH
    S3 B2 34
    cycle 3 EX02
   polynomial addition using Linked list
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist{
    int coeff;
    int exp;
    struct linkedlist *link;
}node;

node* getNode(){
    node* ptr = (node *)malloc(sizeof(node));
    ptr -> link = NULL;
    ptr -> exp = 0;
    ptr -> coeff = 0;
    return ptr;
}

void display(node *head){
    if (head ->link == NULL){
        printf("No Polynomial\n");
    }
    else {
        node *ptr = head ->link;
        while(ptr -> link  != NULL){
            printf("%dX^%d+", ptr -> coeff,ptr -> exp);
            ptr = ptr -> link;
        }
        printf("%dX^%d\n", ptr -> coeff,ptr -> exp);

    }
}
void insertterm(int c,int e,node* head)
{
    node* ptr = head;
    while (ptr -> link != NULL){
        ptr = ptr -> link;
    }
    node* new = getNode();
    ptr -> link = new;
    new -> coeff = c;
    new -> exp = e;
}

void add(node *P,node *Q,node* R)
{
    node * ptr1 = P-> link;
    node * ptr2 = Q-> link;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->exp>ptr2->exp)
        {
            insertterm(ptr1->coeff,ptr1->exp,R);
            ptr1=ptr1->link;
        }
        else if (ptr1->exp<ptr2->exp)
        {
            insertterm(ptr2->coeff,ptr2->exp,R);
            ptr2=ptr2->link;
        }
        else
        {
            insertterm((ptr1->coeff+ptr2->coeff),ptr1->exp,R);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
    }
    while(ptr1!=NULL)
    {
        insertterm(ptr1->coeff,ptr1->exp,R);
        ptr1=ptr1->link;
    }  
    while(ptr2!=NULL)
    {
        insertterm(ptr2->coeff,ptr2->exp,R);
        ptr2=ptr2->link;
    }  
}
void insertmultiple(int c,int x,node* m)
{
    // not entering code block 
    // node * ptr=m;
    // while(ptr!=NULL && ptr->exp > x)
    // {
    //     ptr=ptr->link;
    //     if(ptr->exp == x)
    //     {
    //         ptr->coeff=ptr->coeff+c;
    //         return;
    //     }
    //     else
    //     {
    //         node *new = getNode();
    //         new->exp=x;new->coeff=c;
    //         if(ptr->link=NULL)
    //         {
    //             ptr->link=new;
    //         }
    //         else
    //         {
    //             m->link=new;
    //             new->link=ptr;
    //         }
    //         return;
    //     }
    //     printf("code block is used");
    // }
    insertterm(c,x,m);
    
}
void multiply(node * P, node * Q, node * M){
    node * ptr1 = P;
    node * ptr2 = Q;

    if(ptr1->link == NULL || ptr2->link == NULL){
        printf("multiplication not possible \n");
    }
    else{
        while(ptr1->link != NULL){
            while (ptr2->link != NULL)
            {
                int exp = ptr1->link->exp + ptr2->link->exp;
                int coeff = ptr1->link->coeff * ptr2->link->coeff;
                insertmultiple(coeff,exp,M);
                ptr2 = ptr2 -> link;
            }
            ptr1 = ptr1->link;
            ptr2 = Q;
        }
    }
}

void main()
{
    node *P ,*Q , *R ,* M;
    int i,n1,n2,c,e;
    P=getNode();
    Q=getNode();
    R=getNode();
    M=getNode();
    printf("Enter the number of terms in the first polynomial\n");
    scanf("%d",&n1);
    printf("Enter the terms of polynomial in decreasing order of exponents\n");
    
    for(i=0;i<n1;i++)
    {
        printf("Coefficient and exponent of term-%d\n",i+1);
        scanf("%d%d",&c,&e);
        insertterm(c,e,P);
    }
    printf("Enter the number of terms in the second polynomial\n");
    scanf("%d",&n2);
    printf("Enter the terms of polynomial in decreasing order of exponents\n");
    int j=0;
    for(i=0;i<n2;i++)
    {
        printf("Coefficient and exponent of term-%d\n",j+1);
        scanf("%d%d",&c,&e);
        insertterm(c,e,Q);
        j++;
    }
    add(P,Q,R);
    printf("polynomial 1:\n");
    display(P);
    printf("polynomial 2:\n");
    display(Q);
    printf("Sum polynomial:\n");
    display(R);
    multiply(P,Q,M);
    printf("Product polynomial:\n");
    display(M);
}