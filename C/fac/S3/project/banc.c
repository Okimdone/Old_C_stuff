#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<ctype.h>
#include<unistd.h>
#include<string.h>

//762164689 :916190186
#define MAXCLIENT 100//1B

/*typedef struct {
int CB;   //Code banque
int CG;   //Code Guichet
int NC;   // Numéro de compte
}NUMERO;
*/
//keeping track of number of deleted clients and their index
typedef struct {
    int n;
    int indx[MAXCLIENT];
}DELETE;

typedef struct tm tm;

typedef struct{
    short int j;
    short int m;
    short int y;
}DATE;

typedef struct{
    int Cpostal;
    char ville[25];
    char quartier[30];
    char rue[30];
    int num;
}ADRESSE;

//int numero,j,m,y,type,sold,string nom,int Cpostal,string ville,quartier,rue,int num,tel,j,m,y,string CIN     17
typedef struct {
    //NUMERO numero;//3
    int numero;//1
    DATE date;//3
    short int type;//1
    long int sold;//1
    char nom[35];//1
    char prenom[35];//1
    ADRESSE adresse;//5
    char tel[10];//1
    DATE birthday;//3
    char CIN[8];//1
}CLIENT;
//CLIENT (*client)[MAXCLIENT];

//important declarations :
CLIENT client[MAXCLIENT];
int Cnum=0;/*number of lines | structs filled with clients s info already */;
DELETE todel;


//fonctions :
//selection sort
void sort(void);
//search compte
int search(int num,int inf,int sup);
//random numbers for client num
int RAND_A_B(int A,int B);
//mounting clients to the client STRUCTS
bool init(FILE *book);
//Menu
int menu(void);
//la saisie des infos des clients
void saisie(void);
//modification
void modif(void);
//menu du modification
int minimenu(int i);
//lister tous les comptes clients
void list(void);
//faure une transaction
void transaction(void);
//afficher relv de compte d un client
void relev(void);
//supprimer un compte:
void delt(void);
//tri des elements a suppr
void tri(void);
//end of program-->Coping data into the file.dat-->closing file
void quit(void);

int main(void)
{

    int choix/*choix depuis le menu*/;

    FILE *book = NULL;
    book = fopen("bank.dat","rb");
    if(!book)
    {
        book = fopen("bank.dat","wb");
        if(!book)
        {
            printf("can't open file\n");
            return 1;
        }
    }
    else
    {
        //mounting the clients data to structs array, returns error 2 n quit if it faced a problem!
        if(init(book)){
            printf("initialization complete!\n");


        }
        else
        {
            fprintf(stderr,"Fichier vide, Ajouter des Clients !!\n");
            saisie();
            if(!Cnum)
            {
                printf("Pas de compte dans le fichier!!!\n");
                return 2;
            }
        }
    }
    fclose(book);


    do
    {
        choix=menu();


        switch(choix)
        {
            case 1:
                saisie();
                break;
            case 2:
                modif();
                break;
            case 3:
                list();
                break;
            case 4:
                transaction();
                break;
            case 5:
                relev();
                break;
            case 6:
                delt();
                break;
            case 7:
                quit();
                break;
        }
    }while(choix!=7);

}









int menu(void)
{

    char *end, inpt[60];//for choix number only
    int choix;
    system("clear");
    //printf("\e[1;1H\e[2J");
    printf("----------------------------------Menu----------------------------------\n\n");
    printf(" _______________________________________________________________________\n");
    printf("| Ajouter des comptes bancaires clients.                  |\t1\t|\n");
    printf("|_________________________________________________________|_____________|\n");
    printf("| Mise à jour des comptes clients.                        |\t2\t|\n");
    printf("|_________________________________________________________|_____________|\n");
    printf("| Lister tous les clients.                                |\t3\t|\n");
    printf("|_________________________________________________________|_____________|\n");
    printf("| Faire une transaction.                                  |\t4\t|\n");
    printf("|_________________________________________________________|_____________|\n");
    printf("| Afficher un relevé de compte d'un client.               |\t5\t|\n");
    printf("|_________________________________________________________|_____________|\n");
    printf("| Supprimer un compte déja existant.                      |\t6\t|\n");
    printf("|_________________________________________________________|_____________|\n");
    printf("| QUITTER.                                                |\t7\t|\n");
    printf("|_________________________________________________________|_____________|\n");
    printf("<----ENTRER VOTRE CHOIX----> : ");

    fgets(inpt, sizeof inpt, stdin);
    inpt[strlen(inpt) - 1]='\0';
    choix= strtol(inpt, &end, 10);

    //getting numbers only


    while(choix<1 || choix>7 || (end != inpt + strlen(inpt)))
    {

        printf("\033[A\33[2K\rVeuillez saisir un choix valide! :");
        fflush(stdout);

        if (!fgets(inpt, sizeof inpt, stdin))
            continue;

        //removing \n
        inpt[strlen(inpt) - 1]='\0';
        choix= strtol(inpt, &end, 10);
    }
    return choix;



}

void saisie(void)
{
    char YorN;//continuer ou pas
    char  inpt[60];//for choix number only

    while(Cnum < MAXCLIENT)
    {
        printf("\e[1;1H\e[2J");
        do{
            YorN='\0';
            printf("ajouter un compte :Entrez 'o' pour oui // 'n' pour non : ");
            if (!fgets(inpt, sizeof inpt, stdin))
            {
                printf("\033[A\33[2wK\r");
                continue;
            }
            inpt[strlen(inpt) - 1]='\0';

            if(strlen(inpt) == 1)
            {
                YorN= inpt[0];
                printf("\033[A\33[2K\r");
            }
            else{
                printf("\033[A\33[2K\r");
                continue;
            }


        }while(YorN!='o' && YorN!='O' && YorN!='n' && YorN!='N');

        if(YorN=='n' || YorN=='N')
        {
            break;
        }

        //acount num :
        client[Cnum].numero=RAND_A_B(100000000,999999999);
        /*client[Cnum].numero.CB=RAND_A_B(10000,100000);
	    sleep(1);
	    client[Cnum].numero.CG=RAND_A_B(10000,100000);
	    sleep(1);
	    client[Cnum].numero.NC=RAND_A_B(1000000,10000000);*/

        //creation time :
        time_t nowtime; time ( &nowtime );
        tm * timedate=localtime(&nowtime);
        //coping it to the struct date:
        client[Cnum].date.j= timedate->tm_mday;
        client[Cnum].date.m= timedate->tm_mon + 1;
        client[Cnum].date.y= timedate->tm_year + 1900;

        //account name :
        for(;;){
            printf("Entrez votre nom :");
            //scanf("%s",client[Cnum].nom);
            if (!fgets(inpt, 35, stdin) || strlen(inpt) < 4)
            {
                printf("\033[A\33[2K\r");
                continue;
            }
            else
                inpt[strlen(inpt) - 1]='\0';

            for(int i=0;inpt[i];i++)
            {
                client[Cnum].nom[i]=toupper(inpt[i]);
            }
            break;
        }

        for(;;){
            printf("Entrez votre prenom :");
            //scanf("%s",client[Cnum].nom);
            if (!fgets(inpt, 35, stdin) || strlen(inpt) < 4)
            {
                printf("\033[A\33[2K\r");
                continue;
            }
            else
                inpt[strlen(inpt) - 1]='\0';

            for(int i=0;inpt[i];i++)
            {
                client[Cnum].prenom[i]=toupper(inpt[i]);
            }
            break;
        }


        //Addresse
        printf("\nEntrez votre Adresse :\n");
        /*Ville*/for(;;){
                    printf("Ville\t\t:");
                    //scanf("%s",client[Cnum].nom);
                    if (!fgets(inpt, 25, stdin) || strlen(inpt) < 4)
                    {
                        printf("\033[A\33[2K\r");
                        continue;
                    }
                    else
                        inpt[strlen(inpt) - 1]='\0';

                    for(int i=0;inpt[i];i++)
                    {
                        client[Cnum].adresse.ville[i]=toupper(inpt[i]);
                    }
                    break;
                }
        /*Quartier*/for(;;){
                            printf("quartier\t:");
                            //scanf("%s",client[Cnum].nom);
                            if (!fgets(inpt, 25, stdin) || strlen(inpt) < 4)
                            {
                                printf("\033[A\33[2K\r");
                                continue;
                            }
                            else
                                inpt[strlen(inpt) - 1]='\0';

                            for(int i=0;inpt[i];i++)
                            {
                                client[Cnum].adresse.quartier[i]=toupper(inpt[i]);
                            }
                            break;
                }
        /*rue*/         for(;;){
                            printf("rue\t\t:");
                            //scanf("%s",client[Cnum].nom);
                            if (!fgets(inpt, 30, stdin) || strlen(inpt) < 4)
                            {
                                printf("\033[A\33[2K\r");
                                continue;
                            }
                            else
                                inpt[strlen(inpt) - 1]='\0';
                            break;

                        }
    /*Numero*/          for(;;){
                            printf("Numero\t\t:");
                            if (!fgets(inpt, 30, stdin) || strlen(inpt) > 5 || strlen(inpt) <= 1)
                            {
                                printf("\033[A\33[2K\r");
                                continue;
                            }
                            else
                                inpt[strlen(inpt) - 1]='\0';

                            client[Cnum].adresse.num=atoi(inpt);
                            break;
                        }

    /*Code postal*/  for(;;){
                            printf("Code postal\t:");
                            if (!fgets(inpt, 30, stdin) || strlen(inpt) != 6)
                            {
                                printf("\033[A\33[2K\r");
                                continue;
                            }
                            else
                                inpt[strlen(inpt) - 1]='\0';

                            client[Cnum].adresse.Cpostal=atoi(inpt);
                            break;
                    }

    /*CIN*/         for(;;){
                        printf("Entrez votre CIN :");
                        if (!fgets(inpt, 30, stdin) || strlen(inpt) < 8 ||strlen(inpt) > 9)
                        {
                            printf("\033[A\33[2K\r");
                            continue;
                        }
                        else
                            inpt[strlen(inpt) - 1]='\0';

                        for(int i=0;inpt[i];i++)
                        {
                            client[Cnum].CIN[i]=toupper(inpt[i]);
                        }
                        break;
                    }

        //date de naissance :
        printf("\nDate de naissance :\n");
        //year
        do{
                            printf("Entrez l'année\t:");
                            if (!fgets(inpt, 30, stdin) || strlen(inpt) != 5)
                            {
                                printf("\033[A\33[2K\r");
                                continue;
                            }
                            else
                                inpt[strlen(inpt) - 1]='\0';

                            client[Cnum].birthday.y=atoi(inpt);
                            if(1817 < client[Cnum].birthday.y && client[Cnum].date.y >= client[Cnum].birthday.y)
                                break;
                            else
                                printf("\033[A\33[2K\r");
        }while(1);
        //mois
        do{
                            printf("Entrez le mois\t:");
                            if (!fgets(inpt, 30, stdin) || strlen(inpt) < 2 || strlen(inpt) > 3 )
                            {
                                printf("\033[A\33[2K\r");
                                continue;
                            }
                            else
                                inpt[strlen(inpt) - 1]='\0';

                            client[Cnum].birthday.m=atoi(inpt);
                            if(1 <= client[Cnum].birthday.m && 12 >= client[Cnum].birthday.m)
                                break;
                            else
                                printf("\033[A\33[2K\r");
        }while(1);
        //jour
        int maxj=client[Cnum].birthday.m;
        if(maxj == 2)
        {
            if((client[Cnum].date.y % 4) == 0) maxj=29;
            else maxj=28;
        }
        else if(maxj == 4|| maxj == 6|| maxj == 9|| maxj == 11) maxj=30;
        else maxj=31;
        do{
                            printf("Entrez le jour :");
                            if (!fgets(inpt, 30, stdin) || strlen(inpt) < 2 || strlen(inpt) > 3 )
                            {
                                printf("\033[A\33[2K\r");
                                continue;
                            }
                            else
                                inpt[strlen(inpt) - 1]='\0';

                            client[Cnum].birthday.j=atoi(inpt);
                            if(client[Cnum].birthday.j >= 1 && client[Cnum].birthday.j <= maxj)
                                break;
                            else
                                printf("\033[A\33[2K\r");
        }while(1);

        //telephone :
        for(;;){
            printf("Num de téléphone : ");
            //scanf("%s",client[Cnum].nom);
            if (!fgets(inpt, 35, stdin) || strlen(inpt) != 11)
            {
                printf("\033[A\33[2K\r");
                continue;
            }
            else
                inpt[strlen(inpt) - 1]='\0';

            for(int i=0;inpt[i];i++)
            {
                client[Cnum].prenom[i]=inpt[i];
            }
            break;
        }

        //type de compte:
        do{
                            printf("Type de compte :(| 1 | 2 | 3 | 4 |)");
                            if (!fgets(inpt, 30, stdin) || strlen(inpt) != 2)
                            {
                                printf("\033[A\33[2K\r");
                                continue;
                            }
                            else
                                inpt[strlen(inpt) - 1]='\0';

                            client[Cnum].type=atoi(inpt);
                            if(0 < client[Cnum].type && client[Cnum].type < 5)
                                break;
                            else
                                printf("\033[A\33[2K\r");
        }while(1);

         //solde :
         do{
                            printf("Solde :");
                            if (!fgets(inpt, 30, stdin) || strlen(inpt) < 1)
                            {
                                printf("\033[A\33[2K\r");
                                continue;
                            }
                            else
                                inpt[strlen(inpt) - 1]='\0';

                            client[Cnum].sold=atoi(inpt);
                            if(0 < client[Cnum].sold )
                                break;
                            else
                                printf("\033[A\33[2K\r");
        }while(1);

         Cnum++;
    }


    sort();
}


void modif(void)
{
    char YorN;//continuer ou pas
    int numCP,indx,choice;

    for(;;)
    {
        do{
            printf("Modifier un compte :Entrez 'o' pour oui // 'n' pour non :");
            scanf("%c",&YorN);
            if(YorN=='n' || YorN=='N')
            {
                return;
            }

        }while(YorN!='o' && YorN!='O');

        for(;;){
            printf("Nº de compte (0 pour quitter):");
            scanf("%i",&numCP);
            if(numCP==0)
                return;

            indx=search(numCP,0,Cnum - 1);

            if(indx== -1)
            {
                printf("Num de compte invalide\n");
                continue;
            }
            else
                break;
        }

        choice=minimenu(indx);
        if(choice==0){
            return;
        }
        else if (choice==4)
        {
            do
            {
                printf("tapez votre choix :");
                printf("1-Code postal : %i\n",client[indx].adresse.Cpostal);
                printf("2-Ville : %s\n",client[indx].adresse.ville);
                printf("3-Quartier : %s\n",client[indx].adresse.quartier );
                printf("4-Rue : %s\n", client[indx].adresse.rue );
                printf("5-Nº : %i\n", client[indx].adresse.num);
                scanf("%i",&choice);
            }while(choice<1 || choice>5);
            choice += 40;

        }

        switch(choice)
        {
            case 1:

                //solde :
                printf("Ancien Solde :%li\nNouveau solde :",client[indx].sold );scanf("%li",&client[indx].sold);
                break;

            case 2:
                //account name :
                printf("Ancien nom %s\nNouveau nom :",client[indx].nom);
                scanf("%s",client[indx].nom);
                break;
            case 3:
                //account name :
                printf("Ancien prenom %s\nNouveau prenom :",client[indx].prenom);
                scanf("%s",client[indx].prenom);
                break;

            //Addresse
            case 41:
            printf("Ancien Code postal : %i\nNouveau :",client[indx].adresse.Cpostal);scanf("%i",&client[indx].adresse.Cpostal);
            break;

            case 42:
            printf("Ancienne Ville: %s\nNouvelle :",client[indx].adresse.ville);scanf("%s",client[indx].adresse.ville);
            break;

            case 43:
            printf("Ancien quartier : %s\nNouveau :",client[indx].adresse.quartier);scanf("%s",client[indx].adresse.quartier);
            break;

            case 44:
            printf("Ancienne rue : %s\nNouvelle :",client[indx].adresse.rue);scanf("%s",client[indx].adresse.rue);
            break;

            case 45:
            printf("Ancien Nº : %i\nNouveau :",client[indx].adresse.num);scanf("%i",&client[indx].adresse.num);
            break;

            //telephone :
            case 5:
            printf("Ancien Nº de téléphone : %s\nNouveau : ",client[indx].tel);scanf("%s",client[indx].tel);
            break;

            case 6:
            //date de naissance :
            printf("Ancienne Date de naissance : %hi/%hi/%hi\n",client[indx].birthday.j,client[indx].birthday.m,client[indx].birthday.y);
            //year
            do{
                printf("Nouvelle année : ");scanf("%hi",&client[indx].birthday.y);
            }while(1817 > client[indx].birthday.y || client[indx].date.y < client[indx].birthday.y);
            //mois
            do{
                printf("nouveau mois : ");scanf("%hi",&client[indx].birthday.m);
            }while(1 > client[indx].birthday.m || 12 < client[indx].birthday.m);
            //jour
            int maxj=client[indx].birthday.m;
            if(maxj == 2)
            {
                if((client[indx].date.y % 4) == 0) maxj=29;
                else maxj=28;
            }
            else if(maxj == 4|| maxj == 6|| maxj == 9|| maxj == 11) maxj=30;
            else maxj=31;
            do{
                printf("Nouveau jour : ");scanf("%hi",&client[indx].birthday.j);
            }while(client[indx].birthday.j < 1 || client[indx].birthday.j > maxj);
            break;

            /*//type de compte:
            do{
                printf("Type de compte :(| 1 | 2 | 3 | 4 |)");scanf("%hi",&client[indx].type);
            }while(client[indx].type<1 || client[indx].type > 4);*/


            case 7:
            //CIN
            printf("Ancien CIN %s\nNouveau : ",client[Cnum].CIN);scanf("%s",client[Cnum].CIN);
            break;
        }
    }
}


void list(void)
{
    int j=0;

    if(todel.n!=0)
    {
        for(int i=0;i<Cnum;i++)
        {
            if(i!=todel.indx[j])
            {
                //num de cpt
                printf("Nº de compte :%i\n",client[i].numero);

                //date de creation
                printf("Date de creation\t: %hi/%hi/%hi\n",client[i].date.j,client[i].date.m,client[i].date.y);
                //name
                printf("Nom\t\t: %s\n",client[i].nom);
                printf("Prenom\t\t: %s\n",client[i].prenom);

                 //Addresse
                printf("Adresse :\n");
                printf("Ville\t\t: %s\n",client[i].adresse.ville);
                printf("quartier\t: %s\n",client[i].adresse.quartier);
                printf("rue\t\t: %s\n",client[i].adresse.rue);
                printf("Numero\t\t:%i\n", client[i].adresse.num);
                printf("Code postal\t: %i\n", client[i].adresse.Cpostal);

                //CIN
                printf("Entrez votre CIN\t: %s\n",client[i].CIN);

                //date de naissance :
                printf("Date de naissance\t: %hi/%hi/%hi\n",client[i].birthday.j,client[i].birthday.m,client[i].birthday.y);

                //telephone :
                printf("Num de téléphone\t: %s\n",client[i].tel);
                //getchar();

                //type de compte:
                printf("Type de compte\t: %hi\n",client[i].type);

                 //solde :
                 printf("Solde\t: %li\n",client[i].sold);
                 printf("_________________________________________\n");
            }
            else
                j++;
        }
    }
    else
    {
        for(int i=0;i<Cnum;i++)
        {

            //num de cpt
            printf("Nº de compte :%i\n",client[i].numero);

            //date de creation
            printf("Date de creation\t: %hi/%hi/%hi\n",client[i].date.j,client[i].date.m,client[i].date.y);
            //name
            printf("Nom\t\t\t: %s\n",client[i].nom);
            printf("Prenom\t\t\t: %s\n",client[i].prenom);

             //Addresse
            printf("Adresse :\n");
            printf("Ville\t\t\t: %s\n",client[i].adresse.ville);
            printf("quartier\t\t: %s\n",client[i].adresse.quartier);
            printf("rue\t\t\t: %s\n",client[i].adresse.rue);
            printf("Numero\t\t\t: %i\n", client[i].adresse.num);
            printf("Code postal\t\t: %i\n", client[i].adresse.Cpostal);

            //CIN
            printf("Entrez votre CIN\t: %s\n",client[i].CIN);

            //date de naissance :
            printf("Date de naissance\t: %hi/%hi/%hi\n",client[i].birthday.j,client[i].birthday.m,client[i].birthday.y);

            //telephone :
            printf("Num de téléphone\t: %s\n",client[i].tel);
            //getchar();

            //type de compte:
            printf("Type de compte\t\t: %hi\n",client[i].type);

             //solde :
             printf("Solde\t\t\t: %li\n",client[i].sold);
             printf("_________________________________________\n");
        }
    }
    printf("Appuyez sur \"Entrer\" pour continuer\n");
    getchar();
}


void transaction(void)
{
    int numCP,indCP[2];
    long int Stransf;

    for(int i=0;i<2;i++)
    {
        for(;;){
            printf("Nº de compte du %s (0 pour quitter): ",(i==0)?"donneur d'ordre":"bénéficiaire");
            scanf("%i",&numCP);

            if(numCP==0)
                return;

            indCP[i]=search(numCP,0,Cnum - 1);

            if(indCP[i]== -1)
            {
                printf("Num de compte invalide\n");
                continue;
            }
            else
                break;
        }
    }

    printf("Entrez la somme que vous voulez transféré : ");
    scanf("%li",&Stransf);
    while(client[indCP[0]].sold < Stransf)
    {
        printf("Vous n'avez que %li DH dans votre compte!!\n",client[indCP[0]].sold);
        printf("Rentrez la somme que vous voulez transféré : ");
        scanf("%li",&Stransf);
    }
    client[indCP[0]].sold -= Stransf;
    client[indCP[1]].sold += Stransf;

    printf("La transaction a été bien effectué!\n");

}

void relev(void)
{
    int numCP,indCP;

    for(;;){
        printf("Nº de compte à afficher (0 pour quitter): ");
        scanf("%i",&numCP);

        if(numCP==0)
            return;

        indCP=search(numCP,0,Cnum - 1);

        if(indCP== -1)
        {
            printf("Num de compte invalide\n");
            continue;
        }
        else
            break;
    }

    //num de cpt
    printf("Nº de compte :%i\n",client[indCP].numero);

    //date de creation
    printf("Date de creation\t: %hi/%hi/%hi\n",client[indCP].date.j,client[indCP].date.m,client[indCP].date.y);
    //name
    printf("Nom\t\t: %s\n",client[indCP].nom);
    printf("Prenom\t\t: %s\n",client[indCP].prenom);

     //Addresse
    printf("Adresse :\n");
    printf("Ville\t\t: %s\n",client[indCP].adresse.ville);
    printf("quartier\t: %s\n",client[indCP].adresse.quartier);
    printf("rue\t\t: %s\n",client[indCP].adresse.rue);
    printf("Numero\t\t:%indCP\n", client[indCP].adresse.num);
    printf("Code postal\t: %i\n", client[indCP].adresse.Cpostal);

    //CIN
    printf("Entrez votre CIN\t: %s\n",client[indCP].CIN);

    //date de naissance :
    printf("Date de naissance\t: %hi/%hi/%hi\n",client[indCP].birthday.j,client[indCP].birthday.m,client[indCP].birthday.y);

    //telephone :
    printf("Num de téléphone\t: %s\n",client[indCP].tel);
    //getchar();

    //type de compte:
    printf("Type de compte\t: %hi\n",client[indCP].type);

     //solde :
     printf("Solde\t: %li\n\n",client[indCP].sold);
     getchar();
}


void delt(void)
{
    int numCP,indCP;char YorN;

    for(;;){
        printf("Nº de compte à supprimer (0 pour quitter): ");
        scanf("%i",&numCP);

        if(numCP==0)
            return;

        indCP=search(numCP,0,Cnum - 1);

        if(indCP== -1)
        {
            printf("Num de compte invalide\n");
            continue;
        }
        else
            break;
    }
    do{
            printf("Nº du compte trouvé : Entrez 'o' pour oui // 'n' pour non :");
            /*while(1!=*/scanf("%c",&YorN);/*)
            {
                printf("Retapez:");
            }*/
            if(YorN=='n' || YorN=='N')
            {
                return;
            }

        }while(YorN!='o' && YorN!='O');

    todel.indx[todel.n++]=indCP;
    tri();
    printf("Le compte est supprimé\n");

}





//random num
int RAND_A_B(int A,int B)
{
    srand(time(NULL));
    return (rand()%(B-A) +A);
}

void tri(void)
{
    int min, swap;

    for(int i=0,N=todel.n - 1;i < N ;i++)
    {
        min= i;
        for(int j=i + 1;j < todel.n;j++)
        {
            if(todel.indx[j]< todel.indx[min])
            {
                min=j;
            }
        }
        if(min != i)
        {
            swap=todel.indx[i];
            todel.indx[i]=todel.indx[min];
            todel.indx[min]=swap;

        }
    }

}

void sort(void)
{
    int min;CLIENT swap;

    for(int i=0,N=Cnum - 1;i < N ;i++)
    {
        min= i;
        for(int j=i + 1;j < Cnum;j++)
        {
            if(client[j].numero < client[min].numero)
            {
                min=j;
            }
        }
        if(min != i)
        {
            swap=client[i];
            client[i]=client[min];
            client[min]=swap;

        }
    }
}

int search(int num,int inf,int sup)
{
    int mid = (inf + sup)/2;
    if(client[mid].numero==num)
        return mid;
    else if(inf==sup)
        return -1;
    else if(num < client[mid].numero)
        return search(num,inf,mid-1);
    else
        return search(num,mid + 1,sup);
}

int minimenu(int i)
{
    int choix;
    do
    {
        printf("tapez votre choix\t:\n");
        //printf("Num de compte :%i\n",client[i].numero);
        //printf("date de creation de compte %hi//%hi//%hi\n",client[i].date.j , client[i].date.m , client[i].date.y);
        //printf("type de compte %hi\n",client[i].type);
        printf("1-Solde\t\t\t: %li\n",client[i].sold);
        printf("2-Nom\t\t\t: %s\n",client[i].nom);
        printf("3-Prenom\t\t\t: %s\n",client[i].prenom);
        printf("4-Code postal\t\t: %i Addresse :%s %s %s Nº:%i\n",client[i].adresse.Cpostal, client[i].adresse.ville , client[i].adresse.quartier , client[i].adresse.rue , client[i].adresse.num);
        printf("5-Nº de telephone\t: %s\n",client[i].tel);
        printf("6-date de naissaince\t: %hi//%hi//%hi\n",client[i].birthday.j, client[i].birthday.m , client[i].birthday.y );
        printf("7-CIN\t\t\t: %s\n",client[i].CIN);
        printf("0-quitter\n");
        printf("Choix : ");scanf("%i",&choix);

    }while(choix<0 || choix>7);
    return choix;

}


bool init(FILE* book)
{
    todel.n=0;

    //reading
    int i=0, Echeck , sizeofclient=sizeof(CLIENT);

    while(!feof(book))
    {
        Echeck=fread(client + i , sizeofclient , 1 ,book);
        //fprintf(stdout,"%i ,%hi ,%hi ,%hi ,%hi ,%li ,%s ,%s ,%i ,%s ,%s ,%s ,%i ,%s ,%hi ,%hi ,%hi ,%s\n", client[i].numero , client[i].date.j , client[i].date.m , client[i].date.y , client[i].type , client[i].sold , client[i].nom , client[i].prenom , client[i].adresse.Cpostal , client[i].adresse.ville , client[i].adresse.quartier , client[i].adresse.rue , client[i].adresse.num , client[i].tel , client[i].birthday.j , client[i].birthday.m , client[i].birthday.y , client[i].CIN);
        //Echeck=fscanf(book,"%i ,%hi ,%hi ,%hi ,%hi ,%li ,%s ,%s ,%i ,%s ,%s ,%s ,%i ,%s ,%hi ,%hi ,%hi ,%s\n", &client[i].numero ,&client[i].date.j , &client[i].date.m , &client[i].date.y , &client[i].type , &client[i].sold , client[i].nom, client[i].prenom , &client[i].adresse.Cpostal , client[i].adresse.ville , client[i].adresse.quartier , client[i].adresse.rue , &client[i].adresse.num , client[i].tel , &client[i].birthday.j , &client[i].birthday.m , &client[i].birthday.y , client[i].CIN);
        //printf("%i||%hi||%hi||%hi||%hi||%li||%s||%s||%i||%s||%s||%s||%i||%s||%hi||%hi||%hi||%s||\n", client[i].numero  ,client[i].date.j , client[i].date.m , client[i].date.y , client[i].type , client[i].sold , client[i].nom , client[i].prenom , client[i].adresse.Cpostal , client[i].adresse.ville , client[i].adresse.quartier , client[i].adresse.rue , client[i].adresse.num , client[i].tel , client[i].birthday.j , client[i].birthday.m , client[i].birthday.y , client[i].CIN);
        //printf("echeck--->%i",Echeck);
        //printf("\ni>>>%i\n",i);
        if(Echeck == -1){return false;}
        else if(Echeck!= 1){continue;}
        i++;
    }
    //printf("faefae\n\n%i",i);
    Cnum=i;
    //rewind(book);
    //printf("%i",client[])
    return true;
}

void quit(void)
{
    FILE *book = fopen("bank.dat","wb");
    for(int i=0,j=0;i<Cnum;i++)
    {
        if(j<todel.n){
            while(i < todel.indx[j])
            {
                fwrite(client + i , sizeof(CLIENT) , 1 ,book);
                //fprintf(book,"%i ,%hi ,%hi ,%hi ,%hi ,%li ,%s ,%s ,%i ,%s ,%s ,%s ,%i ,%s ,%hi ,%hi ,%hi ,%s\n", client[i].numero , client[i].date.j , client[i].date.m , client[i].date.y , client[i].type , client[i].sold , client[i].nom , client[i].prenom , client[i].adresse.Cpostal , client[i].adresse.ville , client[i].adresse.quartier , client[i].adresse.rue , client[i].adresse.num , client[i].tel , client[i].birthday.j , client[i].birthday.m , client[i].birthday.y , client[i].CIN);
                i++;
            }
        }
        else {
            fwrite(client + i , sizeof(CLIENT) , 1 ,book);
            //fprintf(stdout,"%i ,%hi ,%hi ,%hi ,%hi ,%li ,%s ,%s ,%i ,%s ,%s ,%s ,%i ,%s ,%hi ,%hi ,%hi ,%s\n", client[i].numero , client[i].date.j , client[i].date.m , client[i].date.y , client[i].type , client[i].sold , client[i].nom , client[i].prenom , client[i].adresse.Cpostal , client[i].adresse.ville , client[i].adresse.quartier , client[i].adresse.rue , client[i].adresse.num , client[i].tel , client[i].birthday.j , client[i].birthday.m , client[i].birthday.y , client[i].CIN);
        }

    }
    fclose(book);
}
