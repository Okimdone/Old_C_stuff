#include <stdio.h>

int somme(int x,int y){
    return x+y;
}

int main(){
    int a,b;
    printf("Entrez les nombres :\n");
    scanf("%i %i",&a,&b);
    printf("la somme est %i\n",somme(a,b));

}