#include <stdio.h>
#include <stdlib.h>


int main(){

    float* ptr = (float*)calloc(15,sizeof(float));

    if(ptr){
        free(ptr);
    }
}