#include<stdio.h>
#include<string.h>
#include<ctype.h>

void correct(char* prenom);

int main()
{

    FILE* file1,* file2;
    char* prenom[35] ;
    file1=fopen("filemal.txt","r");
    if(file1==NULL)
    {
        printf("can t open file!\n");
        return 1;
    }
    file2=fopen("filebien.txt","w");
    if(file2==NULL)
    {
        printf("can t create file!\n");
        return 2;
    }

    while(!feof(file1))
    {
        fscanf(file1,"%s\n",prenom);
        correct(prenom);
        fprintf(file2,"%s\n",prenom);
    }
    fclose(file1);
    fclose(file2);
    return 0;
}

void correct(char* prenom)
{
int i,l;
l=strlen(prenom);
toupper(*prenom);
for(i=1;i<l;i++)
{
tolower(*prenom+i);
}
}
