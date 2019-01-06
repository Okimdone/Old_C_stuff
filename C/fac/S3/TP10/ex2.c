#include <stdio.h>
#include <stdlib.h>

int possi(int *ptab,int k,int *tab )
{
    //num des elements possitve
    int pos=0;

    for(int i=0;i<k;i++)
    {
        if(*(tab + i) > 0)
        {
            *(ptab+pos)=*(tab + i);
            pos++;
        }
    }
    return pos;
}

int main()
{
    //insert input
    int T[]={-5,0,16,-59,64},i = 5;


    int* POS=malloc(sizeof(int)*i);

    //num des possi
    int N = possi(POS,i,T);

    //affichage
    for(int j=0;j<N;j++)
    {
        printf("%i ",*(POS+j));
    }
    printf("\n");
    free(POS);
}