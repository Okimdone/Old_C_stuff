#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void){
        string s;
    do{
        printf("What is your name, kind Sir ?: ");
        s = get_string();
    }
    while(s == NULL);
    //Check every character if it s the 1st one, and in case it is , capitalise it if possible
    for(int i = 0, n = strlen(s); i < n; i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            if(i == 0){
                printf("%c",toupper(s[i]));
            }
            else if(s[i-1] == ' '){
                printf("%c",toupper(s[i]));
            }
            else
                printf("%c",tolower(s[i]));
        }
        else if(s[0] == ' ' || (s[i] == ' ' && s[i-1] == ' ')){
            
        }
        else
            printf("%c",s[i]);
    }
    printf("\n");
    //scan n only print 1st chars as Uppercase
    for(int i = 0, n = strlen(s); i < n; i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            if(i == 0){
                printf("%c",toupper(s[i]));
            }
            else if(s[i-1] == ' '){
                printf("%c",toupper(s[i]));
            }
          
        }
  
    }
    printf("\n");
}