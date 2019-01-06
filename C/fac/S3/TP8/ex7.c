#include <stdio.h>
#include <string.h>

int main()
{
    char CH1[50],CH2[50];
    printf("CH1 : ");
    scanf("%[^\n]", CH1);
    printf("CH2 : ");
    scanf("%[^\n]", CH2);

    int len1=strlen(CH1)/2, len2=strlen(CH2)/2;

    char CH3[len1+len2];

    for(int i=0;i<len1;i++)
    {
        CH3[i]=CH1[1];
    }
    for(int j=0;j<=len2;j++)
    {
        CH3[len1+j]=CH2[j];
    }
    CH3[len1+len2-1]='\0';

    printf("%s",CH3);
}