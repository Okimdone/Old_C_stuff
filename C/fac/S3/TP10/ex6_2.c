#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool ispalin(char *pal,int x);

int main()
{
    char T[100];
    printf("Texte :");
    scanf("%[^\n]",T);

    char *Text=T;

    char *palin=malloc(sizeof(Text));
    int i=0,j=0;

    //suppr les espaces du texte
    int tolow='a'-'A';
    while(*(Text+i))
    {
        if((*(Text+i)>= 'a'&& *(Text+i)<='z') || (*(Text+i)>= '0'&& *(Text+i)<='9'))
            *(palin+j++)=*(Text+i);
        else if(*(Text+i)>= 'A'&& *(Text+i)<='Z')
            *(palin+j++)=*(Text+i) + tolow;

        i++;
    }
    //palin[j]='\0';

    //check if palin
    if(ispalin(palin,j))
    {
        printf("\"%s\" est un palindrome.\n",Text);
    }
    else
        printf("\"%s\" n'est pas un palindrome.\n",Text);


    free(palin);
}

bool ispalin(char* pal,int x)
{
    int X=x-1;

    for(int i=0,n=x/2;i<n;i++)
    {
        if(*(pal+i)!=*(pal+X-i))
            return false;
    }
    return true;
}