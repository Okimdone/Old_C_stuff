#include <stdio.h>
#include <string.h>

int main()
{
    /*char *S;
    printf("string : ");
    scanf("")11*/

    char nom[100],prn[50];
    scanf("%s %s",nom,prn);
    int s= strlen(nom);
    s += strlen(prn);
    printf("%i\n",s);
}