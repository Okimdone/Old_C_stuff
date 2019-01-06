#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct element element;
struct element
{
    int entier;
    element *suivant;

};
typedef struct list list;
struct list
{
    element*tete;
};
////////









/////dayr variable globale////////////////////////////////////////////////////////////////////////////////////
int tab[6]= {2,7,1,8,2};
///u katban b7ala mdekhelha hnaya, ula m3awd mdeclariha wst l fonction o hia aslan globale o katban l kulchi
list* remp(int tabl[50]);
int longeur(int tabl[50]);//fontion longueur tableau









int longeurL(list *L);//fonction longueur liste
void aff(list *L);
///////
int main()
{
    list *l= remp(tab);
    aff(l);
//int a=longeurL(l);

//printf("\nhahowa %i",a);
}
///////
list* remp(int tabl[50])
{
    int a=longeur(tabl);
    int i;
    list* L=malloc(sizeof(list));
    element* E=malloc(sizeof(element));















////nta mdayr ////////////////////////////////////////////////////////////////////////////////////////////
//  element*= int * ????
    L->teten=tabl;
    printf("///%i",a);
    for(i=0; i<a; i++)
    {
        E->entier=tabl[i];


////awtani mdayr ////////////////////////////////////////////////////////////////////////////////////////////
//      element*  = int * ????
        E->suivant=&tabl[i];

    }
    /*   if(i=a)
       {
           E->suivant=NULL;
       }*/
    return L;
}
void aff(list *L)
{

    element* E=malloc(sizeof(element));
    E->suivant=L->tete;
    while(E!= NULL)
    {
        printf("\n===%i",E->entier);
        E=E->suivant;
    }


}

int longeurL(list *L)
{
    element* E=malloc(sizeof(element));
    int i=0;
    E->suivant=L->tete;
    while(E->suivant!= NULL)
    {
        i++;
    }
    return i;
}

int longeur(int tab[50])
{
    int i;
    for(i=0; tab[i]; i++);
    return i;
}