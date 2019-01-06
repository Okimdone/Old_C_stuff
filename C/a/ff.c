//only int input

/*#include <stdio.h>
#include <unistd.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>

int main(){

}

char *end;
char inpt[9];
int n ;
do {
     if (!fgets(inpt, sizeof inpt, stdin))
        continue;

     // remove \n
     inpt[strlen(inpt) - 1]='\0';
     printf("%s-------\n\n",inpt);
     //fflush(stdin);
     n= strtol(inpt, &end, 10);
} while (end != inpt + strlen(inpt));

printf("%s %i %s\n",end,n,inpt);*/

typedef struct{
    char dd[15];
    int n;
}qqq;

#include <stdio.h>

int main(){
    FILE *x=fopen("ddd.dat","w");
    if(x==NULL)
    {
        printf("error openning f\n");
        return 1;
    }
    qqq pp;
    qqq xx;
    scanf("%s",pp.dd); pp.n=2;

    fwrite(&pp,sizeof(qqq),1,x);
    fclose(x);
    x=fopen("ddd.dat","r");
    size_t e=fread(&xx,sizeof(qqq),2,x);

    printf("%s %i %zu\n",xx.dd,xx.n,e);

    fclose(x);


}