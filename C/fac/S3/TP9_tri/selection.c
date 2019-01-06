#include <stdio.h>

void sort(int V[],int n);

int main()
{
    int indx=-1;
    int T[100];
    do
    {
        indx++;
        printf("T[%i] :",indx);
    }while(scanf("%i",&T[indx])!= EOF);

    printf("\n___________________\n\n");

    for(int i = 0; i < indx; i++)
    {
        printf("T[%i] : %i\n",i,T[i]);
    }

    //sorting
    sort(T,indx);

     printf("___________________\n\n");

    for(int i = 0; i < indx; i++)
    {
        printf("T[%i] : %i\n",i,T[i]);
    }
}

void sort(int V[],int n)
{
    int max,swap;

    for(int i=0,N=n - 1;i < N ;i++)
    {
        max= i;
        for(int j=i + 1;j < n;j++)
        {
            if(V[j]>V[max])
            {
                max=j;
            }
        }
        if(max != i)
        {
            swap=V[i];
            V[i]=V[max];
            V[max]=swap;

        }
    }
}