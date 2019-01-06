#include <stdio.h>
#define MAX 10

int main()
{
    char M[MAX][MAX]={{'a','b','c','d'},{'e','f','g','h'},{'i','j','k','l'}};
    char vect[MAX*MAX];
    int k=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            vect[k] = M[i][j];
            k++;
        }
    }

    for(int i=0;i<3;i++){
        printf("| ");
        for(int j=0;j<4;j++)
        {
            printf("%c ",M[i][j]);
        }
        printf("|");
        printf("\n");
    }


    for(int j=0;j<k;j++)
    {
        printf("%c ",vect[j]);
    }
}