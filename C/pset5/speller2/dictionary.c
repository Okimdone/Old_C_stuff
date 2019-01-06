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
{/*
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
    return false;*/
    TREE *ptr=first;
    if(word[0] && ptr)
    return true;
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //read passed dictionary
    FILE *dict = fopen( dictionary , "r");
    if(!dict)   return false;

    //char to store every char in DICTIONARY
    char c;//int index;

    //getting the 1st char in dictionnary , to check if the dict is empty or not , if empty quit
    c=getc(dict);

    //checking n setting up the head of the tree
    if(!first && (isalnum(c) ||  ispunct(c)))
    {

        first=(TREE*) malloc(sizeof(TREE));
        first->letter = c;
        first->delta = false;
        first->next = NULL;
        first->down = NULL;
        /*for(int i=0;i < 26;i++){
            first->letter[i]=NULL;
        }*/
    }
    else // quit if dict is empty
        return false;




    //cursor for the tree
    TREE *ptr=first;

    for(;;){

        c=fgetc(dict);

        //if end of line start the tree over for the next word
        if(c == '\n'){
            ptr->delta=true;
            ptr=first;

            //set the 1st line-list
            c=fgetc(dict);
            for(;;){

                if(c == EOF){
                    if (ferror(dict))
                    {
                        return false;
                    }
                    return true;
                }

                if(ptr->letter == c)
                    break;

                if(!ptr->next){
                    ptr->next   = (TREE*) malloc(sizeof(TREE));
                    ptr         = ptr->next;
                    ptr->letter = c;
                    ptr->delta  = false;
                    ptr->next   = NULL;
                    ptr->down   = NULL;
                    break;
                }
                else
                    ptr         = ptr->next;
            }
            continue;
        }


        //break when reaching end of file
        else if(c == EOF){
            break;
        }



        //if it s a charater
        else{
            //after checking that the word doesn t end at this point , we re going down at the tree to add the actual next char that isn t an end of a word
            //ptr = ptr->down;
            //if ptr is null add a new list down with char inside , then start from 1st loop m else go down n continue the code down below
            if(!ptr->down){

                ptr->down   = (TREE*) malloc(sizeof(TREE));
                ptr         = ptr->down;
                ptr->letter = c;
                ptr->delta  = false;
                ptr->next   = NULL;
                ptr->down   = NULL;
                continue;
            }
            else //go down to the next line of nodes
                ptr         = ptr->down;


            //keep going throught the columns of list untill u reach null then add it in the end (ordered dict), if char already exists start from the very top of the first loop again
            for(;;){

                //check if the "next" place holder already contains the char -c-
                if(ptr->letter == c)
                    break;

                //if the next ptr != NULL make one
                if(!ptr->next){
                    ptr->next   = (TREE*) malloc(sizeof(TREE));
                    ptr         = ptr->next;
                    ptr->letter = c;
                    ptr->delta  = false;
                    ptr->next   = NULL;
                    ptr->down   = NULL;
                    break;
                }

                //else if next element wasnt empty n the current element isn t what we r searshing for yet , go to the next one then

                else
                    ptr         = ptr->next;
            }






/*            //transform every char into its corresponding index
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

                //go to the next pointer//character
                ptr = ptr->letter[index];
                //for(int i=0;i < 26;i++){
                //   ptr->letter[i]=NULL;
                //}


            }
*/
        }
    }

    if (ferror(dict))
    {
        return false;
    }
    return true;




}
/*
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
*/

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
  /*  if(!first) return 0; //TREE* layers[LENGTH];
    else{
        return Nwords(first);
    }*/
    return false;
}



// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    free(first);
    // TODO
    return true;
}
