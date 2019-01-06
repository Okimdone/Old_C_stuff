#include <stdio.h>


#define nbe 2
#define nbet 3


void saisie(char nom[nbet][20],float not[nbet][nbe]);
void affiche(char nom[nbet][20],float not[nbet][nbe]);
float moy(float not[nbe] );


int main()
{
    char nom[nbet][20];
    float not[nbet][nbe];
   // float s=0;

    saisie( nom, not);
    affiche( nom, not);
    /*s=moy( not );
    printf("votre moyenne %s est %f2",nom,s);*/
}


void saisie(char nom[nbet][20],float not[nbet][nbe])
{
    int i,j;
    for(j=0; j<nbet; j++)
    {
        printf("entrer nom  detudiant %i: ",j+1);
        scanf(" %s",nom[j]);
        for(i=0; i<nbe; i++)
        {
            printf("note %i :",i+1);
            scanf(" %f",&not[j][i]);
        }
    }
}


void affiche(char nom[nbet][20],float not[nbet][nbe])
{


    int i,j;
    for(j=0; j<nbet; j++)
    {
        printf("etudiant %i: ",j+1);
        printf("%s ",nom[j]);
        for(i=0; i<nbe; i++)
        {
            printf("note %i :",i+1);
            printf("| %f |",not[j][i]);
        }
        printf("\n");
    }
}











/*float moy(float not[nbe] ){
int i;
float s=0;
for(i=0;i<nbe;i++){
    s+= not[i];
}
return (s/nbe);




}*/