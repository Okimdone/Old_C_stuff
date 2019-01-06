#include<stdio.h>

struct{
    noeud *first;
    
}

typedef struct POL{
    int coeff;
    int expo;
    struct POL* next;
} POL;

POL *CreePolynomeVide();
void AjouterNoeud(POL *po,int coef,int expo);

int main(){

    POL* first=NULL;

}



POL *CreePolynomeVide(){
    POL first;
    int N;
    printf("Entez le nombres des exposants :"); scanf("%i",&N);
    
    
}