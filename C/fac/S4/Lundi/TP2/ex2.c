#include<stdio.h>
#include<stdbool.h>


typedef struct {
    int x;
    struct ENT *next;
}ENT;

ENT *first;

void InitListe(){
    first = NULL;
}

bool ListeVide(){
    if(!first){
        return true;
    }
    return false;
}

bool ListePleine(){
    if(first){
        return true;
    }
    return false;
}

void ajout(int nombre){

    ENT *ptr=first;

    if(ListeVide()){
        first = (ENT*) malloc(sizeof(ENT));
        first->x = nombre;
        first->next= NULL;
    }
    else{
        //ptr=fisrt->next;
        while(ptr){

            if(ptr->x > nombre){
                ptr=ptr->next;
            }
            else
                break;

        }


    }
}
