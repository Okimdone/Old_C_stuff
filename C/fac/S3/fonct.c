#include <stdio.h>

long long int fact(long long int n);

int main(void){
    long long int num;
    do{
    printf("Entrer un nombre entier : ");
    scanf("%lli", &num);
    }while(num<0);

    printf("%lli! = %lli\n",num,fact(num));
}

long long int fact(long long int n){
    if(n > 0){
        return n*fact(n-1);
    }
    else{
        return 1;
    }

}