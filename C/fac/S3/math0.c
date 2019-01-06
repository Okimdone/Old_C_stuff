#include <stdio.h>
int main(void){
    int A,B;
    printf("Nombre A : ");
    scanf("%i",&A);
    printf("Nombre B : ");
    scanf("%i",&B);

    printf("le quotient est %i, Le reste est %i\n", A/B , A % B);
    //printf("le quotient est %i, Le reste est %i\n", (A-(A%B))/B , A % B);
}