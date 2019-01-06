#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc,string argv[]){
    string s;
    int t;
    //check for errors in argv1 an exit if their is one!
    if(argc != 2 || argv[1] == NULL){
        printf("enter the key as a non negative number argument as an arg!!!\n");
        return 1;
    }
    int k = atoi(argv[1]);
    printf("type the text to cipher :\n");
    //get the plaintext
    s = get_string();
    //for every caracter in the plain text do
    for(int i = 0, n = strlen(s); i < n ;i++){
        //Storing the ascii value of the caracter inside of t
        t = s[i];
        //keep adjusting for every A <= t <= Z until A <= t + k <= Z
        if(t >= 'A'&& t <= 'Z'){
            t = t + k;
            while(t > 'Z'){
                 t -= 26;

            }
            printf("%c", t);

        }
        //keep adjusting for every a <= t <= z until a <= t + k <= z
        else if(t >= 'a'&& t <= 'z'){
            t = t + k;
            while(t > 'z'){
                t -= 26;
            }
            printf("%c", t);
        }
        //make no changes to special caracters including numbers!
        else {

            printf("%c",t) ;

        }
    }
    printf("\n");
    return 0;
}