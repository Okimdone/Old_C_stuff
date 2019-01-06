#include <stdio.h>

int strlengh(char s[])
{
    int i=0;
    while(s[i] != '\0')
    {
        i++;
    }
    return i ;
}

int main(){
    char *s="salam labas";

    printf("%i\n",strlengh(s));
}