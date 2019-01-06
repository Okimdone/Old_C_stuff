#include <stdio.h>
#include <string.h>

int main(){
    char s[100];
    printf("text : ");
    scanf("%[^\n]", s);
    int e=0,len=strlen(s);

    for(int i=0;i<=len;i++){
        if(s[i]=='e')
        {
            e++;
            for(int j = i + 1;j <= len;j++)
            {
                if(s[j]=='e')
                {
                e++;
                continue;
                }
                s[j-e]=s[j];
            }

            break;
        }
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


char tab[2][100];
int swap;

swap=tab[0];
tab[0]=tab[1];
tab[1]=swap;