#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct ELEMENT{
    int nombre;
    struct ELEMENT* up;
    struct ELEMENT* down;
}ELEMENT;


ELEMENT* first=NULL;
ELEMENT* last=NULL;


bool insr();
bool supprimer();
bool chercher(int a);


int main(){

    int X;
    int num;


    while(true){
        printf("1-insert\n");
        printf("2-delete\n");
        printf("3-search\n");

        printf("0-quit\n");
        printf("entrez votre choix :");scanf("%i",&X);

        if(X==0)
            break;

        switch(X){
            case 1:
                insr();break;
            case 2:
                supprimer();break;
            case 3:

                printf("entrez le num a chercher :");scanf("%i",&num);
                if(chercher(num)){
                    printf("true\n");
                }
                else
                    printf("no\n");
                break;
        }

    }

    for(ELEMENT *ptr=last; ptr!=NULL ; ptr=ptr->up)
    {
        printf("%i ",ptr->nombre);
        free(ptr);
    }
+
    printf("\n");

}

bool insr(){
    int num;
    printf("entrez le num a ajouter :");scanf("%i",&num);

    if(chercher(num)){
        printf("the num is already in the list!\n");
        return false;
    }
    else{


        ELEMENT *n=malloc(sizeof(ELEMENT));
        if(!n){
            printf("error");
            exit(2);
        }

        n->nombre=num;
        n->up=NULL;



        if(!first){
            first=n;
            last=n;
            n->down=NULL;
            return true;
        }

        //else
        n->down=first;
        first->up=n;
        first=n;
        return true;
    }


}


bool supprimer(){

    int num;
    printf("entrez le num a supprimer :");scanf("%i",&num);


    for(ELEMENT* ptr=last; ptr ;ptr=ptr->up){
        if(ptr->nombre == num){
            ELEMENT* upper=ptr->up;
            ELEMENT* downer=ptr->down;

            upper->down=downer;
            downer->up=upper;
            free(ptr);
            return true;
        }
    }
    return false;
}


bool chercher(int a){

    for(ELEMENT* ptr=last; ptr ;ptr=ptr->up){
        if(ptr->nombre == a){
            return true;
        }
    }

    return false;
}

