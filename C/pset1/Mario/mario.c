#include <stdio.h>

int main(){
    int A,i,j;
    printf("enter a number!!");
    scanf("%d",&A);
        for(i=0;i<A;i++){
            for(j=0;j<=i;j++){
                printf("#");
            }
            printf("\n");
        }
}