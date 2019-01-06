#include<stdio.h>

int recur(int U){
    if(U==U1)
    return recur(U - 1) + recur(U - 2);
}

int U1,U2;

int main(){

    int Un;
    printf("donnez U1 :");scanf("%i",&U1);
    printf("donnez U2 :");scanf("%i",&U2);

    printf("donnez Un :");scanf("%i",&Un);

    printf("Un = ",recur(Un));
}