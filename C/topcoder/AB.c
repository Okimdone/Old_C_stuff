#include<stdio.h>
#include <stdlib.h>
#include <sys/time.h>



char* make_string(int n ,int k );

int main(){
    int N,K;

    do{
        printf("N :");scanf("%i",&N);
    }while(N < 2 || N > 50);

    int k_lim = N* (N - 1) / 2;

    do{
        printf("K :");scanf("%i",&K);
    }while(K < 0 || K > k_lim);

    char * string = make_string(N ,K );

    printf("string = %s\n",string);


    free(string);
}


char* make_string(int n ,int k ){

    int base = n, half_n = n/2, As=0;

    //calculating the number of As
    while(As*base < k){
        if(base < half_n){
            return NULL;
        }

        As++;base--;
    }


    //allocating space
    char * AB= (char *) malloc(sizeof(char) *(n + 1));
    if(!AB){
        printf("error allocating");
        exit(1);
    }

    //typing the big As with the value of the base leaving one A for the value of less than a base
    int i;
    if(As*base == k){
        for(i=0;i < As;i++){
            AB[i]='A';
        }
        for(;i < n;i++){
            AB[i]='B';
        }
    }
    else{
        for(i=0;i < As - 1;i++){
            AB[i]='A';
        }
        for(;i < n;i++){
            AB[i]='B';
        }
        //k becomes the distance bitween last writen A and the last A the write (wa7adat ) As - 1 + base - (k - (As - 1) * base)
        AB[]='A';
    }
    printf("base = %i, As=%i ,position=%i\n",base,As,As - 1 + base - (k - (As - 1) * base));
    return AB;
}