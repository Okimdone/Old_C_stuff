#include<stdio.h>
#include<stdlib.h>


int main(){
    int X;

    printf("X :");scanf("%i",&X);

    //lire A
    int A[9];
    for(int i=0;i<9;i++){
        printf("A[%i]:",i);scanf("%i",&A[i]);
    }


    int *p1=A,*p2=A;
    int del=0;

    while(p2 - A < 9){
        if(*p2==X){
            p2++;
            del++;
        }

        if(p1!=p2){
            *p1 = *p2;
        }

        p1++;
        p2++;
    }

   // A = (int*) realloc(A,9-del);

    p1 = A;

    for(int i=0;i<9-del;i++){
        printf("%i ",*(p1 + i));
    }
    printf("\n");

}