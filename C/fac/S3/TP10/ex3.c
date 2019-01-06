#include<stdio.h>

void sort(int *V,int n)
{
    int min,swap;

    for(int i=0,N=n - 1;i < N ;i++)
    {
        min= i;
        for(int j=i + 1;j < n;j++)
        {
            if(*(V+j)<*(V+min))
            {
                min=j;
            }
        }
        if(min != i)
        {
            swap=*(V+i);
            *(V+i)=*(V+min);
            *(V+min)=swap;

        }
    }
}

int main()
{
    int tab[]={20,18,17,15,12,11,10,8,4,6,3,2,1,55},A=14;

    sort(tab,A);

    for(int i=0;i<A;i++)
    {
        printf("%i ",*(tab+i));
    }
    printf("\n");
}