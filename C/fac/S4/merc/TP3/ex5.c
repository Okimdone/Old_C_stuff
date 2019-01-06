#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

int main(){
    char ch1[50];
    printf("CH1:");scanf("%s",ch1);
    char ch2[50];
    printf("CH2 :");scanf("%s",ch2);

    bool alphas[26] = {0};

    for(int i=0; ch2[i]; i++){
        if(isalpha(ch2[i])){
            alphas[tolower(ch2[i]) - 'a'] = true;
        }
    }



    for(int i=0; ch1[i]; i++){
        if(isalpha(ch1[i])){
            if(alphas[tolower(ch1[i]) - 'a'])
                continue;

        }
        printf("%c",ch1[i]);
    }
    printf("\n");
}