#include<stdio.h>

typedef struct cords{
    float x;
    float y;
    float z;
}cords;

int main(){
    cords p,q;
    cords *X;

    for(int i=0;i<2;i++){
        printf("entrez les coordonnées du vecteur %c :\n",(i==0)?'p':'q');

        if(i==0){
            X=&p;
        }
        else{
            X=&q;
        }

        printf("entrez x :");scanf("%f",&(X->x));
        printf("entrez y :");scanf("%f",&(X->y));
        printf("entrez z :");scanf("%f",&(X->z));
    }

    printf("produit scalaire :");
    cords V;
    V.x=p.x * q.x;
    V.y=p.y * q.y;
    V.z=p.z * q.z;


}