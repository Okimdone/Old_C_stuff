//trees

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct noeud{
    int n;
    struct noeud *left;
    struct noeud *right;
}noeud;


typedef struct A{
    noeud *head;
}A;


A* creation(void);
bool listvide(A* ptr);
void add(A* H, int x);
void search(noeud* ptr);


int main(){

}


A* creation(void){

    A* first= (A*) malloc(sizeof(A));

    if(!first){
        return false;
    }

    first->head=NULL;
    return first;

}


bool listvide(A* ptr){
    if(!ptr->head){
        return true;
    }
    return false;
}







A * tab_arbre(A* arbre,int *tab, int n){
    for(int i=0; i<n ; i++){
        add(arbre,tab[i]);
    }
}



void add(A* H, int x){

    noeud* N = (noeud*)  malloc(sizeof(noeud));

    if(!N){
        fprintf(stderr,"didn t add n = %i",x);
        return;
    }

    N->n = x;
    N->right = NULL;
    N->left = NULL;

    if(listvide(H)){
        H->head = N;
        return;
    }
    noeud* ptr=H->head;
    while(true){
        if(ptr->n == x){
            return;
        }
        if(ptr->n < x){
            if(!ptr->right){
                ptr->right = N;
                return;
            }
            else{
                ptr=ptr->right;
            }
        }

        if(ptr->n > x){
            if(!ptr->left){
                ptr->left = N;
                return;
            }
            else{
                ptr=ptr->left;
            }
        }
    }0
}




void affich(noeud* ptr){

    printf("%i ",ptr->n);

    //search left
    if(!ptr->left)
        search(ptr->left);


    //search right
    if(!ptr->right)
        search(ptr->right);


}