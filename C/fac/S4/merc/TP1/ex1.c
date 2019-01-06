#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr=NULL;                      //1

    int **ptptr;                        //2

    int var;                            //3

    ptr=&var;                           //4

    ptptr=&ptr;                        //5

    ptr = (int*) malloc(sizeof(int));   //6
}