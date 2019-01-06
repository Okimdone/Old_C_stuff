#include<stdio.h>
#include<stdlib.h>


int main()
{
    int *A,*B;
    int a,b;

    //AAAAAAAAAAAAAAAAA
    printf("Dimension de A : ");
    scanf("%i",&a);

    A=malloc(sizeof(int)*a);
    printf("Entrez A : \n");
    for(int i=0;i<a;i++)
    {
        printf("A[%i] :", i);
        scanf("%i",A+i);
    }

    //BBBBBBBBBBBBBBBBBB
    printf("Dimension de B : ");
    scanf("%i",&b);

    B=malloc(sizeof(int)*b);
    printf("Entrez B : \n");
    for(int i=0;i<b;i++)
    {
        printf("B[%i] :", i);
        scanf("%i",B+i);
    }

    //resizing A
    A=realloc(A,sizeof(int)*(a+b));

    //transferring

    for(int i=0,*AA=A+a;i<b;i++)
    {
        *(AA+i)=*(B+i);
    }

    //affichage
    for(int i=0,n=a+b;i<n;i++)
    {
        printf("%i ",*(A+i));
    }
    printf("\n");

    free(A);
    free(B);
}