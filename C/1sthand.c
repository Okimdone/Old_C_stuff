#include<stdio.h>
#include<stdlib.h>
unsigned int int_num(FILE *);

int main(){
	//opening files
	FILE *fa	= fopen("FA.txt","r");
	if(!fa)
		return 1;
	FILE *fb	= fopen("FB.txt","r");
	if(!fb)
		return 2;

	//sizes
	unsigned int a=int_num(fa),b=int_num(fb);
	rewind(fa);rewind(fb);
	//tabs
	int *TABA=malloc(sizeof(int)*a), *TABB=malloc(sizeof(int)*b), *TABC=malloc(sizeof(int)*(a+b));

	for(int i=0;i < a;i++)
	{
		fscanf(fa,"%d ",&TABA[i]);
		printf("TABA[%d] = %d\n",i,TABA[i]);
	}
	for(int i=0;i < a;i++)
	{
		fscanf(fb,"%d ",&TABB[i]);
		printf("TABB[%d] = %d\n",i,TABB[i]);
	}
	//moving A n B -> C
	int n=a + b;
	for(int i = 0, j=0, k=0; i < n ; i++)
	{
		if(j >= a){	TABC[i]=TABB[k];	k++;}
		else if(k >= b){TABC[i]=TABA[j];	j++;}
		else{
			if(TABA[j] <= TABB[k]){ TABC[i]=TABA[j];	j++;}
			else{ 			   TABC[i]=TABB[k];	k++;}
		}

	}

	for(int i=0; i < n; i++){
		printf("TABC[%d] = %d\n",i,TABC[i]);
	}



}



unsigned int int_num(FILE *F)
{
    int x;
	unsigned int c=0;
	while(fscanf(F,"%d",&x)==1)
		c++;
	return c;
}