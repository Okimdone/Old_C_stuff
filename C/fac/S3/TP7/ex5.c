#include <stdio.h>

#define NB_ETUD 50
#define NB_Mat 11

void saisie(char nom[][50],int *etudx,float (*note)[11],int *matdx,int *coef);
/*void rlvnot(float DL_MG[],int nbr);
void ratt(float DL_MG[],int nbr);
void reussi(float DL_MG[],int nbr);
*/

int main()
{
//
 char Tab_nom[NB_ETUD][50];
 float Tab_Not[NB_ETUD][NB_Mat];
 int Coef_Mat[NB_Mat];

//opt = option choisit ,tracker de nomb des etudiants , et matiers
 int opt,num_etud,num_mat;


 MENU:
 printf("--------------------MENU PRINCIPAL---------------------\n_______________________________________________________\n|Saisie de données\t\t\t\t|  1  |\n|Relevé de note d'un etudiant\t\t\t|  2  |\n|Liste des etudiants ayant des rattrapages\t|  3  |\n|Liste des etudiants ayant tout validé\t\t|  4  |\n|Quitter\t\t\t\t\t|  5  |\n|_______________________________________________|_____|\nEntrez votre choix : ");
 scanf("%i",&opt);
 switch(opt)
 {
  case 1:
   saisie(Tab_nom,&num_etud, Tab_Not,&num_mat, Coef_Mat);
   goto MENU;
   break;
/*  case 2:
   rlvnot( DL_MG, nbr);
   goto MENU;
   break;
  case 3:
   ratt( DL_MG, nbr);
   goto MENU;
   break;
  case 4:
   reussi( DL_MG, nbr);
   goto MENU;
   break;*/
  case 5:
   break;
  default:goto MENU;
 }
}

void saisie(char nom[][50],int *etudx,float note[][11],int *matdx,int coef[])
{
 //demander le num des etudians à entree
 do
 {
  printf("Nombre des etudiants :");
  scanf("%i",etudx);
 }while(*etudx>NB_ETUD);

 for(int i=0,e=*etudx; i < e;i++)
 {
  printf("Le Nom du %i etudiant : ",i + 1);
  scanf("%s",nom[i]);

  do
  {
   printf("Le Nombre des matiers : ");
   scanf("%i",matdx);
  }while(*matdx > NB_Mat);

  for(int j=0,m=*matdx; j < m ;j++)
  {
   do
   {
    printf("Entrez La note numero : %i",j+1);
    scanf("%f",note[i] + j);
   }while(20 < note[i][j] || note[i][j] < 0);

   if(i==0)
   {
    printf("Entrez le coefficient du matier : ");
    scanf("%i",&coef[j]);
   }
  }
 }

}


/*void rlvnot(float DL_MG[],int nbr)
{
 do
 {
  int todel;

   printf("notes :\t\t");
   for(int i = 0; i<nbr;i++)
   {
    printf("%4.2f    :: %2i\n",DL_MG[i],i+1);
   }
   printf("Quitter ::  0\n");

   do
   {
   printf("indice : ");
   scanf("%i",&todel);
   }while(todel<0 || todel >= nbr);

   if(todel==0) goto END;

   nbr--;
   for(int i=todel-1;i<nbr;i++)
   {
    DL_MG[i]=DL_MG[i+1];
   }
  }while(1);
  END:;

}

void ratt(float DL_MG[],int nbr)
{
 int somm=0;
 for(int i=0;i <=nbr ;i++)
 {
  somm+=DL_MG[i];
 }
 printf("%i",somm/(nbr+1));
}

void reussi(float DL_MG[],int nbr)
{
 printf("les notes V: ");
 for(int i=0;i<=nbr;i++)
{
 if(DL_MG[i]>=10) printf("%f ",DL_MG[i]);
}
printf("\n");
}
*/