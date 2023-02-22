#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book
{
    char title[50];
    int book_id;
    char author[50];
    int edition;
};
struct node
{
    struct book data;
    struct node *next;
};
void insertBook(struct node **head, struct book book_data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = book_data;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = new;
        return;
    }

    struct node *temp = *head;
    struct node *prev = NULL;
    while (temp != NULL && strcmp(temp->data.title, book_data.title) < 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL && strcmp(temp->data.title, book_data.title) == 0)
    {
        while (temp != NULL && strcmp(temp->data.title, book_data.title) == 0 && temp->data.edition < book_data.edition)
        {
            prev = temp;
            temp = temp->next;
        }
    }
    if (prev == NULL)
    {
        new->next = *head;
        *head = new;
    }
    else
    {
        prev->next = new;
        new->next = temp;
    }
}
void searchBook(struct node *head, char title[])
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->data.title, title) == 0)
        {
            printf("Book title: %s\n", temp->data.title);
            printf("Author: %s\n", temp->data.author);
        }
        temp = temp->next;
    }
}
int main()
{
    struct node *head = NULL;
    struct book book1 = {"The Alchemist", 1, "Paulo Coelho", 1};
    insertBook(&head, book1);
    struct book book2 = {"The Alchemist", 2, "Paulo Coelho", 2};
    insertBook(&head, book2);
    struct book book3 = {"Harry Potter", 3, "J.K Rowling", 1};
    insertBook(&head, book3);
    struct book book4 = {"Harry Potter", 4, "J.K Rowling", 2};
    searchBook(head,"The Alchemist");
}