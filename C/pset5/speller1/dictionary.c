// Implements a dictionary's functionality
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "dictionary.h"

//pointer the the tree
TREE *first=NULL;

//variable that contains number of pointers
//int layers=0;



// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //pointer to word
    //const char *wdptr=word;
    //pointer to tree
    TREE *ptr=first;

    //index for the letter
    int index;

    //if character != '\0'
    for(int i=0 ; word[i] ; i++){
        //check for existence of `'` characters
        if(word[i]=='\''){
            index = 26;
        }
        else{
            index = tolower(word[i]) - 'a';
        }
        //if ptr->letter[i]==NULL if the character in word[i] exists in its `i` s place in the dictionary
        if(!ptr->letter[index]){
            return false;
        }

        //go to the next pointer charater/charater
        ptr=ptr->letter[index];
    }

    //if reached the end the the word in dictionarry return true else return false , bug project' in text n Project's in dic return true!
    if(ptr->delta){
        return true;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //read passed dictionary
    FILE *dict = fopen( dictionary , "r");
    if(!dict)
        return false;

    //char to store every char in DICTIONARY
    char c;int index;

    //head of the tree
    if(!first){

        first=(TREE*) calloc(1,sizeof(TREE));
        /*for(int i=0;i < 26;i++){
            first->letter[i]=NULL;
        }*/

    }

    //cursor for the tree
    TREE *ptr=first;

    while(true){

        c=fgetc(dict);

        //if end of line start the tree over for the next word
        if(c == '\n'){
            ptr->delta=true;
            ptr=first;
            continue;
        }

        //break when reaching end of file
        else if(c == EOF){
            break;
        }

        //if it s a charater
        else{
            //transform every char into its corresponding index
            if(c=='\''){
                index=26;
            }
            else{
                index = c - 'a';
            }
            //c -= 'a';


            if(!ptr->letter[index]){

                //creating new Branches for the letter c
                ptr->letter[index] = (TREE*) calloc(1,sizeof(TREE));

                //memory check if the pointer the the next letters was really created
                if(!ptr->letter[index]){
                    return false;
                }

                //go to the next pointer//character
                ptr = ptr->letter[index];
                /*for(int i=0;i < 26;i++){
                    ptr->letter[i]=NULL;
                }*/
            }
            else{
                ptr = ptr->letter[index];
            }

        }
    }

    if (ferror(dict))
    {
        return false;
    }
    return true;


}

unsigned int Nwords(TREE* ptr){
    unsigned int NmberOfWords=0;
    if(ptr->delta==true) NmberOfWords++;

    for(int i=0;i<27 ;i++){
        if(ptr->letter[i]){
            NmberOfWords += Nwords(ptr->letter[i]);
        }
    }

    return NmberOfWords;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if(!first) return 0; //TREE* layers[LENGTH];
    else{
        return Nwords(first);
    }
}


void freememo(TREE *ptr){
    for(ptr;ptr; ptr=ptr->next){

    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{


    free(first);
    // TODO
    return true;
}
