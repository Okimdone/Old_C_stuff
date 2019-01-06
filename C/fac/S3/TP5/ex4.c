#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool premier(int k){
    if(k%2 == 0 && k!= 2) return false;

        for(int j = sqrt(k); j > 1 ; j=j-2)
        {
            if(k%2 == 0 && k!= 2) continue;
            if(k%j == 0) return false;
        }
        return true;
}

void main(void){

    int N;
    do
    {
        printf("Entrez N : ");
        scanf("%i",&N);
    }while(N <= 1);

    //testing
    for(int i = 2; i < N ;i++){

        if(premier(i)){
            printf("%i ",i);
        }
    }
    printf("\n");
}