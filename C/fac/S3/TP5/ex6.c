#include <stdio.h>

void AFFICH(int X){
     printf("   |");
    for(int i = 1; i<=10 ; i++){
        printf("%2i ",i);
    }
    printf("\n");
    //2eme line
    for(int i = 1; i<12 ; i++){
        printf("___");
    }
    printf("\n");


    //math
    printf("%2i |",X);
    for(int j=1; j <= 10 ; j++){
        printf("%2i ",X*j);
    }
    printf("\n");
}

int main(void){
    int x;
    do
    {
        printf("Enter X (X doit etre compris entre 2 et 9) :");
        scanf("%i",&x);
    }while(!(9>=x && x >= 2));
    AFFICH(x);
}
