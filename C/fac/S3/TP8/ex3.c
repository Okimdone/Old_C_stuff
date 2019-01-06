#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char *s="aefeofñnrw ngworngweosufhpwie hfwe weFI";
    int voy=0;


    for(int i=0, len = strlen(s);i < len;i++)
    {
        s[i]=tolower(s[i]);
        if(s[i]=='a' /*||s[i]=='A'*/ ||s[i]=='e' /*||s[i]=='E'*/ ||s[i]=='y' /*||s[i]=='Y'*/ ||s[i]=='i'/* ||s[i]=='I'*/ ||s[i]=='o' /*||s[i]=='O'*/ ||s[i]=='u' /*||s[i]=='U'*/)
        {
            voy++;
        }
    }
    printf("voys = %i\n",voy);
}