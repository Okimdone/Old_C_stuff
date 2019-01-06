#include<stdio.h>

void swaping(int T[],int n){
    int swap;
    
    int Nsur2=n/2;
    int N=n-1;

    for(int i=0;i<Nsur2;i++){
        swap=T[i];
        T[i]=T[N-i];
        T[N-i]=swap;
    }
}


void printout(int T[],int n){
    for(int i=0;i<n;i++){
        printf("| %i  ",T[i]);
    }
    printf("|\n");
}

int main(){
    int T1[10]={1,2,3,4,5,6,7,8,9,10};
    int T2[9]={1,2,3,4,5,6,7,8,9};


    swaping(T1,10);
    swaping(T2,9);

    printf("T1:");printout(T1,10);
    printf("T2:");printout(T2,9);
}
