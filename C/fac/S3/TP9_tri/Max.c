#include <stdio.h>

int max(int T[],int n,int i);

int main(){

 int T[100], n;

 printf("La taille du tableau d'entier : ");
 scanf("%i",&n);

 //l'affectation:
 for(int i = 0; i < n; i++)
 {
    printf("Tab[i] :");
    scanf("%i",&T[i]);
 }

 printf("Le max est : %i\n",max(T,n,0));

}

int max(int T[],int n,int i)
{
    if(i == n-1)
    {
        return T[i];
    }

    int x=max(T,n,i+1);
    return (T[i]>x)?T[i]:x;
}
