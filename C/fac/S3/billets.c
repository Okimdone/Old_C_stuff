#include <stdio.h>

int main(void){
    //int somme,_100=0,_50=0,_10=0,_5=0,_1=0;
    int somme;
    printf("Entrer la somme d argent :");
    scanf("%i",&somme);

    printf("Dans 1376 dh il y a:\n");

    /*while(somme >= 100){
        _100++;
        somme-=100;
    }
    while(somme >= 50){
        _50++;
        somme-=50;
    }
    while(somme>=10){
        _10++;
        somme-=10;
    }
    while(somme>=5){
        _5++;
        somme-=5;
    }
    while(somme>=1){
        _1++;
        somme-=1;
    }*/
    //printf("%i\tbillets de 100 dh\n%i\tbillets de 50 dh\n%i\tbillets de 10 dh\n%i\tbillets de 5 dh\n%i\tpiece de 1 dh\n",_100,_50,_10,_5,_1);
    printf("%i\tbillets de 100 dh\n%i\tbillets de 50 dh\n%i\tbillets de 10 dh\n%i\tbillets de 5 dh\n%i\tpiece de 1 dh\n",somme/100,somme%100/50,somme%50/10,somme%10/5,somme%5/1);
}