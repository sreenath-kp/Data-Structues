/*
    K P SREENATH
    Roll no: 34
    Cycle 2 EX07
    linear search from employee data
*/
#include <stdio.h>
typedef struct employee
{
    char empid[20];
    char firstname[20];
    char middlename[20];
    char lastname[20];
    int salary;
}
void main()
{
    employee* list;
    int n;
    printf("Enter no of employees: ");
    scanf("%d",&n);
    list=(employee*)malloc(n*sizeof(employee));
    printf("Enter details of employees\n");
    for(int i=0;i<n;i++)
    {
        printf("First name: ");
        scanf("%s",list[i]->firstname);
    }
}
