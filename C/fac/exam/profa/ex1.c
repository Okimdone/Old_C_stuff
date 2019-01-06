#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct ELEMENT{
    int n;
    struct ELEMENT* next;
}ELEMENT;

typedef struct LISTE{
    ELEMENT *premier;
}LISTE;





//////////////////////
int estEquilibre(LISTE* L);
LISTE* equilibrer(LISTE* L);



/////////////////////
int main(){

}



int estEquilibre(LISTE* L){
    int zero=0,one=0;

    for(ELEMENT* ptr=L->premier; ptr ;ptr=ptr->next){
        if(ptr->n == 0)
            zero++;
        else if(ptr->n==1)
            one++;
    }
    if(zero == one)
        return 0;
    else
        return zero - one;
}


LISTE* equilibrer(LISTE* L){

    int difference = estEquilibre(L);
    //if list is empty or 0 == 1 then quit
    if(difference == 0){
        return L;
    }

    int zero_ou_un = (difference > 0)?1 : 0;
    difference = abs(difference);

    ELEMENT* ptr=L->premier;

    //fint the last element in the list
    while(ptr->next){
        ptr=ptr->next;
    }

    for(int i=0; i < difference ; i++){

        //creating an element n checking if it was indeed created
        ELEMENT* E = (ELEMENT*) malloc(sizeof(ELEMENT));
        if(!E){
            exit(-1);
        }

        //setting it up
        E->n=zero_ou_un;
        E->next=NULL;

        //then passing it the end of the list that is already set up in -ptr-
        ptr->next=E;
        ptr=ptr->next;
    }
    //return the head of the list when it s over
    return L;
}