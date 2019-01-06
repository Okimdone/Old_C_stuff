#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc,string argv[]){
    string p;
    int k,kln,t;
    
    //check for errors in argv1 an exit if their is one!
    if(argc != 2 || argv[1] == NULL){
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    kln = strlen(argv[1]);
    for(int i = 0 , n = strlen(argv[1]) ; i < n ; i++){
        if(argv[1][i] < 'A' || (argv[1][i] > 'Z' && argv[1][i] < 'a')|| argv[1][i] > 'z'){
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }
    printf("plaintext: ");
    
    //get the plaintext
    p = get_string();
    printf("\nciphertext: ");
    
    //for every caracter in the plain text do
    for(int i = 0,j = 0, n = strlen(p); i < n ;i++){
    
        //calculating int from key s letter for every letter in the plaintext, without mattering about caracters or the "while" change a bit down there 
        if(argv[1][i % kln] >= 'A' && argv[1][j % kln] <= 'Z')
            k = argv[1][j % kln] - 'A';
        else if(argv[1][j % kln] >= 'a' && argv[1][j % kln] <= 'z')
            k = argv[1][j % kln] - 'a';
    
        //while the caracter is not a letter hold the key for the next
        while(p[i] < 'A' || (p[i] > 'Z' && p[i] < 'a')|| p[i] > 'z'){
            printf("%c", p[i] );
            i++;
        }
    
        //Storing the ascii value of the caracter inside of t
        t = p[i];
        //keep adjusting for every A <= t <= Z until A <= t + k <= Z 
        if(t >= 'A'&& t <= 'Z'){
            
            t = t + k;
            if(t > 'Z'){
                t = 64 + (t - 'Z');  
            }
            printf("%c", t);
            
        }
    
        //keep adjusting for every a <= t <= z until a <= t + k <= z 
        else if(t >= 'a' && t <= 'z'){
            t = t + k;
            if(t > 'z'){
                t = t - 'z'+ 64;  
            }
            printf("%c", t);
        } 
    
        //make no changes to special caracters including numbers!
        else {
            printf("%c",t) ;
        }
        j++;
    }
    printf("\n");
    return 0;
}