#include <stdio.h>
#include <stdlib.h>
// own code incomplete
struct linkedlist{
    int coeff;
    int exp;
    struct linkedlist *link;
};
typedef struct linkedlist node;

node* getNode(){
    node* ptr = (node *)malloc(sizeof(node));
    ptr -> link = NULL;
    return ptr;
}

node *head = NULL;

void polynomial(){
    if (head == NULL){
        printf("No Polynomial\n");
    }
    else {
        node *ptr = head -> link;
        while(ptr -> link  != NULL){
            printf("%dX%d", ptr -> coeff,ptr -> exp);
            ptr = ptr -> link;
        }
        printf("%dX%d", ptr -> coeff,ptr -> exp);

    }
}
void insertterm(int coeff,int exp){
    if (head == NULL){
        head = getNode();
        node* ptr = getNode();
        head -> link = ptr;
        ptr -> coeff = coeff;
        ptr -> exp = exp;
    }

    else {
        node* ptr = head;
        while (ptr -> link != NULL){
            ptr = ptr -> link;
        }
        node* ptrend = getNode();
        ptr -> link = ptrend;
        ptr -> coeff = coeff;
        ptr -> exp = exp;
    }
}
node* add()
{
    
}