#include <stdio.h>
#include <string.h>

int inside(char c, char s[], int j){

    while (s[j++] != '\0')
    {
        if (s[j] == c)
        {
            return 0;
        }
        else return 1;
        
    }
    
}
void main(){
    char s[50], temp[50], store[50][50];
    int i, j, maxlength =0, templength=0, k = 0;


    printf("enter string: ");
    scanf("%[^\n]", s);

    for(i=0; s[i] != '\0'; i++){
        temp[0] = 0;
        templength = 0;

        for (int j = i; s[j] != '\0'; j++){
            if(strchr(s, s[j])){
                temp[templength++] = s[j];
            }
            else break;
            temp[templength] = '\0';

        if(templength > maxlength){
            maxlength = templength;
            strcpy(store[k++], temp);
            }
        }

    }

    printf("the longest substring has length: %d\n", maxlength);
    
        printf("substring: %s \n", store[--k]);

    


}