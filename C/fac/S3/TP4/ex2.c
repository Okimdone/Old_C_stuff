#include <stdio.h>
#include <stdlib.h>

int frame(int x, int y)
{
    x=(abs(x)>abs(y))?x*10:y*10;
    int c=1;
    while(x >= 10)
    {
        x=x/10;
        c++;
    }
    return c;

}

int main(int argc,char * argv[]){

    //utilisation
    if(argc != 3 ){
        printf("usage : ./multp n m\n");
        return 1;
    }

    //n=min(argv[1-2]) et m=max
    int n = (atoi(argv[1])< atoi(argv[2]))?atoi(argv[1]):atoi(argv[2]);
    int m = (atoi(argv[1])> atoi(argv[2]))?atoi(argv[1]):atoi(argv[2]);

    int cadr;
    cadr = frame(n, m);
    //
   /* if(n < -99 || m > 99){
        printf("usage : ./multp n m\n");
        return 2;
    }*/
    //1st line
    for(int l=0;)
    printf("    |");
    for(int i = 1; i<=10 ; i++){
        printf("%*i ",cadr - 1,i);
    }
    printf("\n");
    //2eme line
    for(int i = 1; i<19 ; i++){
        printf("___");
    }
    printf("\n");


    //math
    for(int i = n; i <= m; i++){
        printf("%*i |",cadr - 1,i);
        for(int j=1; j <= 10 ; j++){
            printf("%*i",cadr,i*j);
        }
        printf("\n");
    }
}