#include <stdio.h>

int main(){
    int x;
    int tab[10]={1,2,3,5,6,7,8,9,10,11};

    printf("Number :");
    scanf("%i",&x);

    for(int i = 0; i<10;i++)
    {
        if(x < tab[i]){
            printf("X n existe pas\n");
            break;
        }
        if(x==tab[i])
        {
            printf("Indice = %i\n",i);
            break;
        }

    }
}