#include<stdio.h>
//#include<conio.h>
#include<string.h>

//defs
#define NBE 4
#define NBM 3

//structs
typedef struct {
    char nom[10];
    double notes[NBE];
    double moyenne;
    char mention[15];

}ETUDIANT;

ETUDIANT Liste[NBE];

//variables
int NbEtudiants, NbMatieres;

//fonctions
int Menu();
int Saisie(void);
void Afficher(ETUDIANT etd);
int Resultat(ETUDIANT *ptr);

int main(void){
    int i, r_saisie, r_resultat;
    ////clrscr();
    NbEtudiants=3;
    NbMatieres=2;
    Menu();

    r_saisie= Saisie();
    if(r_saisie==1){
        for(i=0;i<NbEtudiants;i++)
        {
            r_resultat=Resultat(&(Liste[i]));
            if(r_resultat == 1)
                Afficher(Liste[i]);

        }
    }
}

int Menu(void)
{
    int x;
    printf("--------------------MENU PRINCIPAL---------------------\n_______________________________________________________\n|Saisie de données\t\t\t\t|  1  |\n|Relevé de note d'un etudiant\t\t\t|  2  |\n|Liste des etudiants ayant des rattrapages\t|  3  |\n|Liste des etudiants ayant tout validé\t\t|  4  |\n|Quitter\t\t\t\t\t|  5  |\n|_______________________________________________|_____|\nEntrez votre choix : ");
    scanf("%i",&x);
    return x;
}

int Saisie(void)
{
    int i,j;
    float Une_Note;

    if((NbEtudiants <= 0)||(NbMatieres <= 0)) return(0);
    if(NbEtudiants >= NBE) NbEtudiants = NBE;
    if(NbMatieres >= NBM) NbMatieres = NBM;

    for(i=0;i<NbEtudiants ;i++)
    {
        printf("Introduire Nom de l'etudiant numero %d:",i);
        scanf("%s",Liste[i].nom);
        printf("Saisie des notes de l'etudiant :%s\n",Liste[i].nom);
        for(j=0;j<NbMatieres;j++)
        {
            printf("Note de la matiere %d :",j);
            scanf("%f",&Une_Note);
            Liste[i].notes[j]=(double) Une_Note;
        }
    }
    return(1);
}

void Afficher(ETUDIANT etd)
{
    int i;

    ////clrscr();
    printf("---- Affichage Informations Etudiants ----\n");
    printf("Nom: %s\n",etd.nom);
    for(i=0; i < NbMatieres; i++ )
    {
        printf("Note(%d)=%f\n",i,etd.notes[i]);
    }
    printf("Moyenne = %f\n",etd.moyenne);
    printf("Mention :%s\n" ,etd.mention);
    printf("Tapez une touche pour etudiant suivant\n");
    getchar();
}

int Resultat(ETUDIANT *ptr)
{
    if(!ptr){
        return 0;
    }

    double moy=0;
    for(int i=0;i<NbMatieres;i++)
    {
        moy += ptr->notes[i];
    }
    ptr->moyenne =(double) moy/NbMatieres;

    if(ptr->moyenne<10)
    {
        strcpy(ptr->mention,"N.V.");
    }
    else if(ptr->moyenne < 12)
    {
        strcpy(ptr->mention,"passable");
    }
    else if(ptr->moyenne < 14)
    {
        strcpy(ptr->mention,"A.B.");
    }
    else if(ptr->moyenne < 16)
    {
        strcpy(ptr->mention,"B.");
    }
    else if(ptr->moyenne < 18)
    {
        strcpy(ptr->mention,"T.B.");
    }
    else
    {
        strcpy(ptr->mention,"super");
    }
    return 1;
}