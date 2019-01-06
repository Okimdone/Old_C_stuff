/********************************************************************************************************
                        Listes doublement chaînées  + piles
********************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
////////////////////////////////////////////////////////////////////////////////////
////magic lines to use "getch()" , without needing to type "\n" everytime
////link: https://stackoverflow.com/questions/18801483/press-any-key-to-continue-function-in-c
#include <termios.h>
////////////////////////////////////////////////////////////////////////////////////




typedef struct ELEMENT{
    struct ELEMENT* previous;
    char c;
    struct ELEMENT* next;
}ELEMENT;


typedef struct PILE_D{
    ELEMENT* premier;
}PILE_D;




//
//Funtions
//
PILE_D *create_list(void);
void delete_char(PILE_D* pile);
void delete_list(PILE_D* pile);
void print_list(PILE_D* pile);
void add(PILE_D* pile, char c);



int main(){

////////////////////////////////////////////////////////////////////////////////////
    ////magic lines to use "getch()" , without needing to type "\n" everytime
    struct termios info;
    tcgetattr(0, &info);          /* get current terminal attirbutes; 0 is the file descriptor for stdin */
    info.c_lflag &= ~ICANON;      /* disable canonical mode */
    info.c_cc[VMIN] = 1;          /* wait until at least one keystroke available */
    info.c_cc[VTIME] = 0;         /* no timeout */
    tcsetattr(0, TCSANOW, &info); /* set immediately */
////////////////////////////////////////////////////////////////////////////////////
                                                                                                    /*
                                                                                                        char str[200];
                                                                                                        //if fgets returned no string (NULL) exit
                                                                                                        if(!fgets(str, 200 , stdin))
                                                                                                            return 1;
                                                                                                    */
    //creating an empty list
    PILE_D *pile = create_list();
    if(!pile){
        printf("Liste wasn t created");
        return 1;
    }

    //reading input instantly
    char c;
    while(1){
        //for every char typed
        c=getchar();

        if(c=='#')
            delete_char(pile);
        else if(c=='$')
            delete_list(pile);
        else if(c=='\n'){
            print_list(pile);
            break;
        }
        else
            add(pile , c);

    }






    //cleaning up allocated memory
    delete_list(pile);
    free(pile);

}



PILE_D *create_list(void){
    //creating a liste
    PILE_D *pile = (PILE_D*) malloc(sizeof(PILE_D));
    pile->premier=NULL;

    return pile;
}


void delete_char(PILE_D* pile){
    //element to delete
    ELEMENT *to_del = pile->premier;

    //ignoring the first element s existence
    pile->premier = to_del->next;

    //making the second element forget about the 1st element

    to_del->next->previous=NULL;


    free(to_del);
}





void delete_list(PILE_D* pile){
    for(ELEMENT* ptr=pile->premier; ptr ; ptr=ptr->next){
        free(ptr);
    }
    pile->premier=NULL;
}









void print_list(PILE_D* pile){
    //if list is empty
    if(!pile || !pile->premier){
        printf("list emplty!\n");
        return;
    }

    //starting from the top
    ELEMENT* ptr=pile->premier;

    //looking for the last element of the list, n putting this information inside "ptr"
    while(ptr->next){
        ptr=ptr->next;
    }

    //at this point <ptr == Address_of_the_last_Element>
    //going back from to last element of the list to the first element of the list n printing to chars inside
    for(; ptr ; ptr=ptr->previous){
        printf("%c",ptr->c);
    }
    printf("\n");
}





//adding char c to the stack "pile"
void add(PILE_D* pile, char c){
    ELEMENT* E = (ELEMENT*) malloc(sizeof(ELEMENT));
    if(!E){
        fprintf(stderr,"couldn t create element");
        exit(-1);
    }

    //setting up the element to add
    E->previous = NULL;
    E->c = c;
    E->next = pile->premier;


    //setting the next element up to know that a previous element was "E" added
    //if list is empty we don t have to change anyything in that case
    if(pile->premier){
        ELEMENT*ptr=E->next;
        ptr->previous = E;
    }


    //setting the new head to become the new element added E (stacks//piles)
    pile->premier=E;
}