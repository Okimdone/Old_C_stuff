#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>




int main(){
    char **MOT;
    MOT=(char **) malloc(sizeof(char *) *10);

    if(!MOT){
        fprintf(stderr,"error!");
        return 1;
    }

    for(int i=0; i < 10; i++){
        MOT[i] =  (char*) malloc(sizeof(char) * 50);
        if(!MOT[i]){
            fprintf(stderr,"error!");
            return 2;
        }

        printf("MOT[%i] :",i);scanf("%s",MOT[i]);


    }


    //swaping
    int N_mots=10;




    int index;

    while(N_mots > 0){

        printf("\nType anything to delete!\n");getchar();

        //init
        index = 0;

        for(int j = 1; j < N_mots; j++){
            if(tolower(MOT[index][0]) > tolower(MOT[j][0])){
                index=j;
            }
        }

        //freeing
        free(MOT[index]);

        //refixing the array
        for(int k=index,n = N_mots - 1; k < n ;k++){
            MOT[k]=MOT[k + 1];
        }
        N_mots--;








        printf("\nprinting text :\n\n");
        for(int i=0; i < N_mots; i++){
            printf("MOT[%i] : %s\n",i,MOT[i]);
        }



    }

    free(T);

}