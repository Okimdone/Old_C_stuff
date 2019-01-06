#include <stdio.h>

int main(){
    int N,ids=0,Vs=0;

    printf("Entrez le num des entrees : ");
    scanf("%i",&N);


    int V[N];

    printf("Entrez les nombres :\n");
    for(int i=0;i<N;i++)
    {
        scanf("%i",&V[i]);
        if(V[i]%2 == 0)
        {
            Vs += V[i];
        }
        if(i%2 == 0)
        {
            ids += V[i];
        }
    }

    printf("Somme des elements dont l indice est pair est %i\nSomme des elements pairs est %i\n",ids,Vs);
}