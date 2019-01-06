#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char **T;
    T=(char **) malloc(sizeof(char *)*5);

    if(!T){
        fprintf(stderr,"error!");
        return 1;
    }

    for(int i=0; i < 5; i++){
        T[i] =  (char*) malloc(sizeof(char) * 50);
        if(!T[i]){
            fprintf(stderr,"error!");
            return 2;
        }

        printf("T[%i] :",i);scanf("%s",T[i]);


    }


    printf("\nprinting text before:\n\n");
    for(int i=0; i < 5; i++){
        printf("T[%i] : %s\n",i,T[i]);
    }

    //swaping
    char swap;

    for(int i=0; i < 5; i++){
        int n = strlen(T[i]);
        for(int j=0,N= n / 2 ; j < N; j++){
            swap = T[i][j];
            T[i][j]= T[i][n - 1 - j];
            T[i][n - 1 - j] = swap ;
        }
    }


    printf("\nprinting text after:\n\n");
    for(int i=0; i < 5; i++){
        printf("T[%i] : %s\n",i,T[i]);
    }

}