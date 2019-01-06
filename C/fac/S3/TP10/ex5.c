#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>


int main()
{
    char CH[250];
    printf("String : ");
    scanf("%[^\n]", CH);

    char *P=CH,N=0;
    bool word=false;

    while(*P)
    {

        if(!isalnum(*P)){
            word=false;
        }
        else if(!word)
        {
            N++;
            word=true;
        }
        P++;
    }

    printf("Num of words : %i\n",N);


}