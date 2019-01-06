#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char s[100];
    int letter[26]={0},i=0;
/*
    for(int k=0;k < 26;k++)
    {
        letter[k]=0;
    }
*/
    printf("texte : ");
    scanf("%[^\n]", s);

    while(s[i] != '.')
    {

        letter[tolower(s[i]) - 'a']++;
        i++;
    }

    for(int k=0;k < 26;k++)
    {
        printf("%c = %i ",k + 'a',letter[k]);
    }

}