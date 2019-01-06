#include<stdio.h>
#include<stdlib.h>

int main(){
    int *A,*B;
    int N,M;

    //A
    printf("entrer la dimension de TABLEAU A :");scanf("%i",&N);

    A=(int*) malloc(sizeof(int)*N);

    if(!A){
        printf("ERROR");
        return 1;
    }

    for(int i=0;i<N;i++){
        printf("A[%i] :",i);scanf("%i", A+i);
    }



    //B
    printf("entrer la dimension de TABLEAU B :");scanf("%i",&M);
    B=(int*) malloc(sizeof(int)*M);
    if(!B){
        printf("ERROR");
        return 2;
    }

    for(int i=0;i<M;i++){
        printf("B[%i] :",i);scanf("%i", B+i);
    }


    //copying A to B
    A=(int* ) realloc(A , N+M);

    for(int i=0;i <M;i++){
        *(A+N+i) = *(B+i);
    }

    N += M;

    //printing A elements

    for(int i=0;i <N ;i++){
        printf("%i ",*(A+i));
    }
    printf("\n");

    free(A);
    free(B);

}









//tas==heap
//int(*tableau[4]);
//tableau= malloc (5*sizeof(*tableau));
/*
int main(){
    char* ptr1 = (char*) malloc(sizeof(char)*190);

    if(!ptr1){
        printf("ptr1->NULL\n");
        return 1;
    }


    char* ptr2 = (char*) realloc(ptr1 ,999);

     if(!ptr2){
        printf("ptr2->NULL\n");
        return 2;

     }


    if(ptr1==ptr2){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }

}*/