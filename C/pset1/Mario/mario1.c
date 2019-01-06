#include <stdio.h>

int main(){
    int A,i,j,k;
    printf("enter a number!!");
    scanf("%d",&A);
        for(i=0;i<A;i++){
            k=A-i;
            for(j=0;j<k;j++){
                printf("#");
            }
            printf("\n");
        }
}