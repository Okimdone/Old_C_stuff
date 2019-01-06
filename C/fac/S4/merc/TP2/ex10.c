#include <stdio.h>
#include<stdlib.h>
int main()
{
    int L, C;

    printf("donner le nombre de ligne:"); scanf("%d",&L);
    printf("donner le nombre de cologne:"); scanf("%d",&C);

    if(n>50 || m>50)
    {
        printf("error\n");
        return 1;
    }

    //int A[n][m];
    int **T;
    T= (int **) malloc(sizeof(int*)*L);
    for(int i=0;i<L;i++){
        *(T+i) = (int *) malloc(sizeof(int)*);
    }


    for(int i=0;i<L;i++)
    {
        for(int j=0;j<C;j++){
            printf("T[%i][%i]:",L,C); scanf("%i",*(T+i)+j);
        }
    }

    //affichage du Tableau
    for(int i=0;i<L;i++)
    {
        for(int j=0;j<C;j++){
            printf("%i ",*(*(T+i)+j));
        }
        printf("\n");
    }

    printf("\n\n");


    //somme des lignes :
    //int somme
    int S;

    printf("Somme des lignes:\n");

    for(int i=0;i<L;i++)
    {
        S=0;
        for(int j=0;j<C;j++){
            S += T[i][j];
        }
        printf("Somme de la ligne Nº%i : %i\n",i,S);
    }

    printf("\n");    int S;

    printf("Somme des Colo:\n");

    for(int i=0;i<L;i++)
    {
        S=0;
        for(int j=0;j<C;j++){
            S += T[i][j];
        }
        printf("Somme de la ligne Nº%i : %i\n",i,S);

}



