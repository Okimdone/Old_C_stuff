#include <stdio.h>

int main(){
    int T[50],Tpos[50],Tneg[50];
    int idx = 0;
    int idp = 0;
    int idn = 0;

    printf("Entrez les Nums :\n");
    while(scanf("%i",&T[idx])!=EOF)
    {

        if(T[idx]>0)
        {
            Tpos[idp]=T[idx];
            idp++;
        }
        else if(T[idx]<0)
        {
            Tneg[idn]=T[idx];
            idn++;
        }
        if(idx == 49) break;
        idx++;
    }

    //print posi
    if(idp > 0){
        printf("les nombres positives sont : ");
        for(int i=0;i<idp;i++)
        {
            printf("%i ",Tpos[i]);
        }
        printf("\n");
    }
    else
        printf("Pas de valeur positive.\n");

    //print nega
    if(idn > 0){
        printf("les nombres negatives sont : ");
        for(int i=0;i<idn;i++)
        {
            printf("%i ",Tneg[i]);
        }
        printf("\n");
    }
    else
        printf("Pas de valeur negative.\n");

}