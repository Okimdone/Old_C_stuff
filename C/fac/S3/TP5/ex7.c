#include <stdio.h>

void mention(int note)
int moyenne(int x1,int x2,int x3,int x4)
{
    return (x1+x2+x3+x4)/4;
}

int main(){
    int N1,N2,N3,N4,moy;
    do
    {
        printf("Entrez les notes : ");
        scanf("%i %i %i %i",N1,N2,N3,N4);
    }while(N1<0&&N1>20&&N2<0&&N2>20&&N3<0&&N3>20&&N4<0&&N4>20);

    moy = moyenne(N1,N2,N3,N4);


}