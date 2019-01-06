#include <stdio.h>
#include <string.h>

char *reversed(char T[],int n/*,int i*/);

int main(){
    char V[]="aaaa bbbb cccc  dddd";

    printf("%s\n",reversed(V,strlen(V) - 1/*,0*/));
}

char *reversed(char T[],int n/*,int i*/){
   static int i = 0;
    if(i > n/2)
    {
        return T;
    }

    char swap=T[i];
    T[i] = T[n - i];
    T[n - i]=swap;
    i++;

    return reversed(T,n/*,i+1*/);
}