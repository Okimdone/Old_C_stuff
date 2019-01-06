#include <stdio.h>

int main (void)
{
    int A,B,C,swap;
    printf("Entrer A : ");
    scanf("%i", &A);
    printf("Entrer B : ");
    scanf("%i", &B);
    printf("Entrer C : ");
    scanf("%i", &C);


    printf("\nBefore :\nA = %i\n",A);
    printf("B = %i\nC = %i",B,C);

    //swaping

    swap = A;
    A = B;
    B = C;
    C = swap;

    printf("\n\nAfter :\nA = %i\n",A);
    printf("B = %i\nC = %i\n",B,C);
}