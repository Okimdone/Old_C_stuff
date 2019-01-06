#include <stdio.h>
#include <math.h>

int main(void){

    int N;
    do
    {
        printf("Entrez N : ");
        scanf("%i",&N);
    }while(N <= 1);

    //testing
    for(int i = 2; i < N ;i++){
        if(i%2 == 0 && i!= 2) continue;
        int k=0;
        for(int j = sqrt(i); j > 1 ; j=j-2)
        {
            if(i%j == 0){ k++; break;}
        }
        if(k==0){
            printf("\t%i ",i);
        }
    }
    printf("\n");
}