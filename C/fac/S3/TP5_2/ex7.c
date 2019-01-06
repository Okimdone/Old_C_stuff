#include <stdio.h>

void saisie(float DL_MG[],int *nbr);
void elimine(float DL_MG[],int nbr);
void reussi(float DL_MG[],int nbr);
void moyenne(float DL_MG[],int nbr);

int main()
{
 int opt,nbr=0;
 float DL_MG[50];

 ALLO:
 printf("Saisir les données\t\t\t1\nAfficher les etudiants\t\t\t2\nAfficher les étudiants de moyenne >10\t3\nAfficher le moyenne de promotion\t4\nQuitter\t\t\t\t\t5\nton choix: ");
 scanf("%i",&opt);
 switch(opt)
 {
  case 1:
   saisie(DL_MG, &nbr);
   goto ALLO;
   break;
  case 2:
   elimine( DL_MG, nbr);
   goto ALLO;
   break;
  case 3:
   reussi( DL_MG, nbr);
   goto ALLO;
   break;
  case 4:
   moyenne( DL_MG, nbr);
   goto ALLO;
   break;
  case 5:
   break;
  default:goto ALLO;
 }
}

void saisie(float DL_MG[],int *nbr)
{
 printf("note %2i : ",*nbr + 1);
 while(scanf("%f",&DL_MG[*nbr])!=EOF)
    {
        if(*nbr == 49) break;
        (*nbr)++;
        printf("note %2i : ",*nbr + 1);
    }
}


void elimine(float DL_MG[],int nbr)
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
void reussi(float DL_MG[],int nbr)
{
 printf("les notes V: ");
 for(int i=0;i<=nbr;i++)
{
 if(DL_MG[i]>=10) printf("%f ",DL_MG[i]);
}
printf("\n");
}
void moyenne(float DL_MG[],int nbr)
{
 int somm=0;
 for(int i=0;i <=nbr ;i++)
 {
  somm+=DL_MG[i];
 }
 printf("%i",somm/(nbr+1));
}

















/*#include <stdio.h>

int main()
{

 int T[50][50], L, C, i, j;
 long somme;

 printf("Nombre de lignes   (max.50) : ");
 scanf("%d", &L );
 printf("Nombre de colonnes (max.50) : ");
 scanf("%d", &C );
 for (i=0; i<L; i++)
    for (j=0; j<C; j++)
        {
         printf("Elément[%d][%d] : ",i,j);
         scanf("%d", &T[i][j]);
        }
 //tableau
 printf("Tableau donné :\n");
 for (i=0; i<L; i++)
    {
     for (j=0; j<C; j++)
          printf("%7d", T[i][j]);
     printf("\n");
    }

 //les sommes
 for (i=0; i<L; i++)
     {
      for (somme=0, j=0; j<C; j++)
             somme+= T[i][j];
      printf("ligne %d : %ld\n",i,somme);
     }

 for (j=0; j<C; j++)
     {
      for (somme=0, i=0; i<L; i++)
             somme+= T[i][j];
      printf("colonne %d : %ld\n",j,somme);
     }
  return 0;
}*/