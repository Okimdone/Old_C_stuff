#include <stdio.h>
#include <stdlib.h>
int main(){
    char* n=malloc(sizeof(char)*100 + 1);
    for(int i=0;i<101;i++){
    printf("%i ",n[i]);

    }
}