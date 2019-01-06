#include <stdio.h>
#define TAILLE_MAX 1000

int main()
{
    FILE* fichier = NULL;
    int x;
    char chaine[TAILLE_MAX] = "";

    fichier = fopen("test.txt", "r");

    if (fichier != NULL)
    {
        while (!feof(fichier)) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {

            x = fgets(chaine, TAILLE_MAX, fichier);
            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
            x=

        }

        fclose(fichier);
    }

    return 0;
}