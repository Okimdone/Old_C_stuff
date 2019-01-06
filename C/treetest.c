#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct TREE{
	struct TREE *letter[2];
}TREE;

bool check(const char *word);

TREE firstt;
TREE *first =&firstt;
TREE snd;
first->letter[0]=&snd;

int main(){
for(int i=0;i < 220;i++){
	for(int j=0; j< 220;j++){
		//printf("%c%c",i,j);
		printf("%c", -72540008);
	}
	if(check("c")){

	printf("true");}
	else{
		printf("false");
	}
}

}


bool check(const char *word)
{
    //pointer to word
    const char *wdptr=word;
    //pointer to tree
    TREE *ptr=first;

    //index for the letter
    int index;

    //if character != '\0'
    while(*wdptr){

        index=tolower(*wdptr) - 'a';

        //if ptr->letter[i]==NULL
        if(!ptr->letter[index]){
            return false;
        }

        //go to the next pointer charater/charater
        ptr=ptr->letter[index];
        wdptr++;
    }
    return true;


}
