#include <stdio.h>

void permute(int **tab,int n,int m,int l1,int l2){

    while(n <= l1 && l1<0 && n <= l2 && l2<0 )
    {
        printf("rentrez les lignes : ");
        scanf("%i %i",&l1,&l2);
    }

    int swap;
    for(int i=0;i<m;i++)
    {
        swap = tab[l1][i];
        tab[l1][i] = tab[l2][i];
        tab[l2][i] = swap;
    }
}