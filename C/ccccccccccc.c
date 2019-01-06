#include <stdio.h>
#include <stdbool.h>

typedef struct X{
    bool a=false;
    bool b=true;

}X;

int main(){
    X x;
    printf("%i ,%i \n",x->a,x->a);
}