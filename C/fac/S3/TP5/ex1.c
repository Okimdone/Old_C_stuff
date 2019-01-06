#include <stdio.h>

void permute(short *a,short *b){
    short temp;
    if(a>b){
        temp=*a;
        *a=*b;
        *b=temp;
    }
}

/*Voici une utilisation de la fonction permute*/
int main(){
    short x,y;/*declaration de deux entiers courts*/

    x=5;
    y=2;
    printf("%hd %hd\n",x,y);/*affiche les nombres*/
    permute(&x,&y);/*appel de notre fonction*/
    printf("%hd %hd\n",x,y);/*affiche les nombres*/

}