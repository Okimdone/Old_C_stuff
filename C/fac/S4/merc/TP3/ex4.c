#include<stdio.h>
#include<string.h>




int main(){

    char x[]="yyyyyyyyyyyyyyyyyyyyyyyyyyy";

    char y[5]="pppp";

    printf("y %s\n",y);


    strncpy( y ,  x,5);


    printf("x %s\n",x);

    printf("y %s\n",y);
}

