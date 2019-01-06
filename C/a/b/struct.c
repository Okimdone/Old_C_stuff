#include <stdio.h>

typedef struct {
    int a;
    char c;
    char *d;
}foo;

foo* stuff(foo  Z[]){

    for(int i=0;i<4;i++)
    {
        Z[i].a=1111*i;
        Z[i].c='a' +('a'+ i)%'a';
        Z[i].d=malloc(sizeof(char)*20);
        Z[i].d="gogoers";
    }
    return Z;
}

int main()
{
    foo x[4];
    foo *X;

    X=stuff(x);


    for(int i=0;i<4;i++)
    {
        printf("%i "    ,X[i].a);
        printf("%c "    ,X[i].c);
        printf("%s \n"  ,X[i].d);
    }
    //printf("%i",X->a);





}