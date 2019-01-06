#include <stdio.h>
#include <cs50.h>

int main(void){

    int taille,poids;

    //sexe
    char sexe ;
    do{

        //if(sexe != 10 ){
        printf("Entez H pour sexe homme, F pour femme: ");
        //}
        //oldsexe = sexe;
        //scanf("%c", &sexe);
        //printf("%i=%c",(int)sexe,sexe);
        sexe = get_char();




    }while(sexe != 'H' && sexe != 'F');

    //Poid
    printf("Poids en kg : ");
    scanf("%i", &poids);

    //taille
    printf("taille en cm : ");
    scanf("%i", &taille);

    if(sexe == 'H')
    {
        if(poids/(taille*taille) >= 25)
            printf("vous devriez surveiller votre alimentation\n");
    }
    else
    {
        if(poids/(taille*taille) >= 23)
            printf("vous devriez surveiller votre alimentation!\n");
    }

}