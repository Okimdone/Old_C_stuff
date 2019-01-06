#include <stdio.h>

int ARM(int x)
{
    int arm=1;
    for(int i = 2; i < x ;i++){
        if(i%2 == 0 && i!= 2) continue;

            for(int j = sqrt(i); j > 1 ; j=j-2)
            {
                if(i%2 == 0 && i!= 2  && i%j == 0) continue;
                if(i%2 == 0 && i!= 2) continue;
                if(i%j == 0) continue;
            }
            return true;
    }
}

int PGCD(int x,int y)
{
    int r;
    if(y>x)
    {
        r=y;
        y=x;
        x=r;
    }

    r=x%y;
    if(r!=0)
        return PGCD(y,r);
    else
        return y;
}

int main()
{
    int N1,N2;
    printf("Entrez les 2 nombres :\n");
    scanf("%i %i",&N1,&N2);

    printf("le PGCD de %i et %i est %i\n",N1,N2,PGCD(N1,N2));





}