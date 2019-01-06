#include <stdio.h>
#include <string.h>

int main()
{
    char s[]="salam afeaz    abcde";
    int i=0;

    while(i < strlen(s))
    {
        int j;
        char mot[50];

        while(s[i]!=' ' && i < strlen(s))
        {
            mot[j]=s[i];
            i++;
            j++;
            mot[j]='\0';
            permute(mot);
            printf("%s",mot);
        }
    }
}