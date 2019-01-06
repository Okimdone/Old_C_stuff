#include<stdio.h>
#include<stdlib.h>

typedef struct element{
    int n;
    struct element* next;
}ELEMENT;


typedef struct FILES{
    ELEMENT *tete;
    ELEMENT *queue;
}FILES;

static FILES *create_file(void);
static FILES *empiler(FILES *F, int n);
static void afficher(FILES *F);

int main(){
    FILES *pair=create_file();
    FILES *impair=create_file();

    int Tab[] = {12, 1, 3, 8, 144, 107, 91};
    for(int i=0; i<7 ;i++){
        if(Tab[i] % 2 == 0){
            empiler(pair ,Tab[i]);
        }
        else{
            empiler(impair, Tab[i]);
        }
    }

    printf("pair :\n"); afficher(pair);
    printf("=========================================\n");
    printf("impair :\n"); afficher(impair);


    free(pair);
    free(impair);

}


static FILES *create_file(void){
    FILES *F=malloc(sizeof(FILES));
    if(!F){
        exit(-1);
    }
    return F;
}

static FILES *empiler(FILES *F, int n){
    ELEMENT *E=malloc(sizeof(ELEMENT));
    if(!E){
        exit(-1);
    }

    E->n = n;
    E->next=NULL;

    if(!F->queue){
        F->queue=E;
        F->tete=E;
    }
    else{
        ELEMENT* ptr=F->queue;
        ptr->next = E;
        F->queue = E;
    }

    return F;
}



static void afficher(FILES *F){
    if(!F->tete){
        return;
    }

    ELEMENT* ptr= F->tete;
    printf("%i\n",ptr->n);
    F->tete = ptr->next;
    free(ptr);
    afficher(F);
}

