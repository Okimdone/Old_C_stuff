#include <stdio.h>
#include <string.h>

int main(){
    char s[100];
     scanf("%[^\n]", s);

    char swap;
    int lengh = strlen(s) - 1;

    for(int i = 0,l=strlen(s)/2;i<l;i++)
    {
        swap = s[i];
        s[i]=s[lengh - i];
        s[lengh - i]= swap;
    }

    printf("%s\n",s);
}