#include<stdio.h>
#include<math.h>



void inverser(char *tab,int nb);
void convertir(char *tab,int nb);
void afficher(char *tab,int nb);


int main(){
    int x;scanf("%i",&x);

    int e=0;

    while(pow(2,e) < x){
        e++;
    }

    char tab[e];

    convertir(tab,x);
    inverser(tab,e);
    afficher(tab,0);
}


void inverser(char *tab,int nb){

    char swap;

    int n=nb/2 + 1;

    for(int i=0;i < n;i++){
            swap=tab[i];
            tab[i]=tab[nb -1 - i];
            tab[nb -1 - i]=swap;
    }
}


void convertir(char *tab,int nb){
    int i=0;
    while(nb != 0)
    {
        tab[i]= '0' + nb%2;
        nb /= 2;
        i++;
    }
    tab[i]='\0';
}


void afficher(char *tab,int nb)
{
    nb=0;
    printf("%s\n",tab);
}