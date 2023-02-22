#include<stdio.h>
#include <string.h>
char s[20];
void main()
{
    FILE* ptr;
    int i=0;
    ptr = fopen("text.txt","r");
    if (ptr == NULL)
    {
        printf("not found");

    }
    else{
        while (fscanf(ptr,"%s",s+i)==1)
        {
            i++;
        }
        
    }
    int n = i;
    printf("%s\n",s);
    printf("___________\n");
}
    