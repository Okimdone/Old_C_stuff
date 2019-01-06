#include<stdio.h>

int main(){
    float *pf1,*pf2;            //1

    float f1,f2;                //2

    pf1=&f1; pf2=&f2;           //3

    *pf1 = 12.5;                //4

    *pf2 = 5.76;                //5

    //6
    float swap;
    swap=*pf1;
    *pf1=*pf2;
    *pf2=swap;

}