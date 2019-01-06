#include <stdio.h>
#include<string.h>

int main(int argc,char* argv[]){
    if(argc!=2)
        return 1;
    int A,i,j,s,k,d;
    printf("enter a number!!");
    memcpy(&A,&argv[1],strlen(argv[1]));
        for(i=0;i<A;i++){
            k=A-i;

            for(s=0;s<i;s++)
            {
                printf(" ");
            }

            for(j=0;j<k;j++)
            {
                printf("#");
            }
            printf("  ");
            d=A-i;

            for(j=0;j<d;j++)
            {
                printf("#");
            }


            printf("\n");
        }
}