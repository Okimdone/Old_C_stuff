#include <stdio.h>

int look(int value, int values[],int min,int max)
{
    int m = (int) (max + min)/2;

    if(value == values[m])
    {
        return m;
    }
    else if(min = max)
    {
        return -1;
    }
    else if(value < values[m])
    {
        return look(value, values , m, min, m - 1);
    }
    else
    {
        return look(value, values , m, m + 1 , max);
    }
}

int main()
{
    int V[100]=
}