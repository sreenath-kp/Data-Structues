#include <stdio.h>
#include <string.h>
void sort();
void print();
int n;
char string[20][20];
void main()
{
    FILE *ptr;
    
    int i=0;
    ptr = fopen("text.txt","r");
    if(ptr==NULL)
    {
        printf("failed to open file");
    }else
    {
      while (fscanf(ptr, " %s", string[i]) == 1)
        {
            i++;
        }
       
    }
     n = i;
    print();
    sort();   
    print(); 

           
}
void sort()
{
    char temp[20];
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
        {
            if(strcmp(string[j],string[j+1])>0)
            {
                strcpy(temp,string[j]);
                strcpy(string[j],string[j+1]);
                strcpy(string[j+1],temp);
            }
        }

}
void print()
{
    printf("list:\n");
    for(int i=0;i<n;i++)
        printf("%s\n",string[i]);

}
void search()
{

}