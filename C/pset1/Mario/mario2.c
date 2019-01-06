#include <stdio.h>

int main(){
    int A,i,j,s,k;
    printf("enter a number!!");
    scanf("%d",&A);
        for(i=1;i<=A;i++){
            k=A-i;
            for(s=0;s<k;s++){
                printf(" ");
            }
            for(j=1;j<=i;j++){
                printf("#");
            }
            printf("\n");
        }
}