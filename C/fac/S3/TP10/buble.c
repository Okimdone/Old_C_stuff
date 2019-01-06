#include<stdio.h>
#include<stdbool.h>

int main(){
    int T[]={5,1,2,5,4,9,3,88,22,5,1,5,1,51,5,16,849},k=17,n=k-1,swap;

    bool swaped=true;
    while(swaped)
    {
        swaped=false;
        for(int i=0;i<n;i++)
        {
            if(T[i]>T[i+1])
            {
                swaped=true;
                swap=T[i+1];
                T[i+1]=T[i];
                T[i]=swap;
            }
        }
    }
    n--;


    for(int i=0;i<k;i++)
    {
        printf("%i ",T[i]);
    }
    printf("\n");
}