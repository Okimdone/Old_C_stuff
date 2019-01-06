#include <stdio.h>

int main(){
    int V[10]={0,1,2,3,4,5,6,7,8,9},indx=10,todel;

    printf("Vecteur initial :\t");
    for(int i = 0; i<indx;i++)
    {
        printf("| %i ",V[i]);
    }
    printf("|\n");

    do
    {
        do
        {
            printf("Indice de la valeur : ");
            scanf("%i",&todel);
        }while(todel<0 || todel >= indx);

        indx--;
        for(int i=todel;i<indx;i++)
        {
            V[i]=V[i+1];
        }


        printf("Vecteur final :\t\t");
        for(int i = 0; i<indx;i++)
        {
            printf("| %i ",V[i]);
        }

        printf("|\n");

    }while(indx>1);
}