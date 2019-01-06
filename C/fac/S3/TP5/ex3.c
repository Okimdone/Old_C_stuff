#include <stdio.h>

void somme(int *resultat,int x,int y){
    *resultat = x+y;
}

int main(){
    int a,b,result;
    printf("Entrez les nombres :\n");
    scanf("%i %i",&a,&b);
    somme(&result,a,b);
    printf("la somme est %i\n",result);

}