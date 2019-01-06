#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n, m;

    printf("donner le nombre de ligne:"); scanf("%d",&n);
    printf("donner le nombre de cologne:"); scanf("%d",&m);

    if(n>100 || m>100)
    {
        printf("error\n");
        return 1;
    }

    //int A[n][m];
    int **A;
    A= (int **) malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        *(A+i) = (int *) malloc(sizeof(int)*m);
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            scanf("%i",*(A+i)+j);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            printf("%i ",*(*(A+i)+j));
        }
        printf("\n");
    }

    printf("\n\n");
    printf("le transposée:\n");

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++){
            printf("%i ",*(*(A+j)+i));
        }
        printf("\n");
    }

    printf("matrice allignée:\n");
   for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            printf("%i ",*(*(A+i)+j));
        }

    }
    printf("\n");
}

