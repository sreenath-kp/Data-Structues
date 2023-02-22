/*
    K P SREENATH
    Roll no: 34
    Cycle 2 EX07
    linear search from employee data
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct 
{   char empid[20];
    char firstname[20];
    char middlename[20];
    char lastname[20];
    long int salary;
}employee;
employee* list;
int n;
void search();
void main()
{
    char repeat='n';
    printf("Enter no of employees: ");
    scanf("%d",&n);
    list=(employee*)malloc(n*sizeof(employee));
    printf("Enter details of employees\n");
    for(int i=0;i<n;i++)
    {
        printf("_____________\n");
        printf("Employment ID: ");
        scanf(" %s",((list+i)->empid));
        printf("First name: ");
        scanf(" %s",((list+i)->firstname));
        printf("Middle name: ");
        scanf(" %s",((list+i)->middlename));
        printf("last name: ");
        scanf(" %s",((list+i)->lastname));
        printf("Salary: ");
        scanf(" %ld",&((list+i)->salary));
        
    }
    do{
    search();
    printf("Do you want to search again?(Y/N)");
    scanf(" %c",&repeat);
    }while(repeat=='Y'||repeat=='y');
    
}
void search()
{
    char id[20];

    printf("\nSearch with empID\nEnter Employment ID: ");
    scanf(" %s",id);
    for(int i=0;i<n;i++)
    {
        if(strcmp(list[i].empid,id)==0)
        {
            printf("FOUND\n");
            printf("NAME: %s %s %s\n",list[i].firstname,list[i].middlename,list[i].lastname);
            return;
        }
    }
    printf("NOT FOUND\n");
}
