#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char **T;
    T=(char **) malloc(sizeof(char *)*10);

    if(!T){
        fprintf(stderr,"error!");
        return 1;
    }

    for(int i=0; i < 10; i++){
        T[i] =  (char*) malloc(sizeof(char) * 200);
        if(!T[i]){
            fprintf(stderr,"error!");
            return 2;
        }

        printf("T[%i] :",i);scanf("%s",T[i]);


    }


    printf("\nprinting text before:\n\n");
    for(int i=0; i < 10; i++){
        printf("T[%i] : %s\n",i,T[i]);
    }

    //swaping
    char* swap;

    for(int i=0,n=10/2; i < n; i++){
        swap = T[i];
        T[i]= T[10 - 1 - i];
        T[10 - 1 - i] = swap ;

    }


    printf("\nprinting text after:\n\n");
    for(int i=0; i < 10; i++){
        printf("T[%i] : %s\n",i,T[i]);
    }

}