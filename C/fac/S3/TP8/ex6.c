#include <stdio.h>
#include <string.h>

int main(){
    char s[100];
    printf("text : ");
    scanf("%[^\n]", s);
    int espace=0,j;

    while(s[espace]==' ')
    {
        espace++;
    }

    for(int i = espace,len=strlen(s);i <= len;i++)
    {
        j=0;
        if(s[i]==' ')
        {
            i++;
            while(s[i + j]==' ')
            {
                espace++;
                j++;
            }
            s[i + 1]=s[i + j];
            i = i + j;
        }
        else
            s[i - espace] =s[i];

    }



    /*if(e>0)
    {
        for(int i=tomove;i <= len;i++)
        {
            if(s[i]=='e')
            {
                e++;
                continue;
            }
            s[i-e]=s[i];
        }
    }*/


    printf("%s\n",s);
}