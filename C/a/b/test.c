#include <stdio.h>
#include <string.h>

void TRI(int num[],int n,int Tab[][3],int i);
void AFFICH(int Tab[][3],int n,int m);
int main()
{
    int n[3],Tab[20][3];

    printf("Tab :\n");

    for(int i=1; i <= 20;i++)
    {
        printf("%ith ligne :", i);
        scanf("%i %i %i",&n[0],&n[1],&n[2]);
        TRI(n,3,Tab,i - 1);
    }

    AFFICH(Tab,20,3);


}

void TRI(int num[],int n,int Tab[][3],int i)
{
    int min,swap;
    for(int k=0,m=n - 1; k<m ; k++)
    {
        min=k;
        for(int j=k; j < n;j++)
        {
            if(num[min]>num[j])
            {
                min=j;
            }
        }
        if(k!=min)
        {
            swap=num[min];
            num[min]=num[k];
            num[k]=swap;
        }
    }

    for(int k = 0;k < n;k++)
    {
        Tab[i][k]=num[k];
    }
}

void AFFICH(int Tab[][3],int n,int m)
{
    for(int i=0;i < n;i++)
    {
        for(int j=0; j<m;j++)
        {
            printf("%3i ",Tab[i][j]);
        }
        printf("\n");
    }
}