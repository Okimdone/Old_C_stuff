#include <stdio.h>

int main(){
    int k=0;
    int tab[10]={4,8,9,9,10,16,18,18,19,20};
    for(int i = 0; i<10;i++)
    {
        if(tab[i]>=10){
            break;
        }
        if(5<=tab[i])
        {
            printf("%s%i ",(k==0)?"indices : ":"",i);
            k++;
            continue;
        }

    }
    printf("\n");
}