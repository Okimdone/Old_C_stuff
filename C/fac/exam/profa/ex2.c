#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct ELEMENT{
    char c;
    struct ELEMENT* next;
}ELEMENT;

typedef struct LISTE{
    ELEMENT *premier;
}LISTE;










bool appartient(LISTE* L, char X);
LISTE* supprimer_occurences_multiples(LISTE* L);











int main(){

}








bool appartient(LISTE* L, char X){
    for(ELEMENT* ptr=L->premier; ptr ; ptr=ptr->next ){
        if(ptr->c == X)
            return true;
    }
    return false;
}

LISTE* supprimer_occurences_multiples(LISTE* L){

    //pointer the element that we might delete
    ELEMENT *ptr=L->premier;
    //pointer to its parent
    ELEMENT *ptr_parent=ptr;

    //a simple pointer to the rest right part of the list of type "LISTE" so as to be able to passe it as an arguemnt to the function "appartient"
    LISTE *rest_of_thelist=(LISTE*) malloc(sizeof(LISTE));
    if(!rest_of_thelist)
        exit(-1);

    //checking the first element existence n deleting it if "found twice" separately
    rest_of_thelist->premier = ptr->next;




    //in the case of the element we should delete is at the beginning of the list



    //while the 1st element or the new 1st element has a duplicate in the list , delete it n stitch the list
    while(ptr == ptr_parent){
        //if it exists do
        if(appartient(rest_of_thelist , ptr->c)){
            //make the list s head point to the second (new first) element
            L->premier=ptr->next;
            //make the parent == the child , cause we r at the head of the list and to keep the loop going
            ptr_parent=L->premier;
            //"delete" the element
            free(ptr);
            //set the new element to check(try to delete)
            ptr       =L->premier;
        }
        //else move on
        else
            ptr=ptr->next;

        //set the new rest of the list to check next "|ptr|reeest_____of_____the______list"
        rest_of_thelist->premier = ptr->next;
    }



    //for the other case, element is in the middle of the list (it can t be deleted if it was on the end of the list cause their s the "left_list to check it with")

    //untile ptr reaches NULL
    for(; ptr ; ptr=ptr->next){
        if(appartient(rest_of_thelist , ptr->c)){
            //make the parent s new child == the next child(the son of its son)
            ptr_parent->next=ptr->next;
            //"delete" the element
            free(ptr);
            //set the new element "ptr" to become the new parent s child
            ptr       =ptr_parent->next;
        }
        else{
            //move both of the pointers by (1,1) to the right
            ptr_parent=ptr;
            ptr=ptr->next;
        }

        rest_of_thelist->premier = ptr->next;
    }


    free(rest_of_thelist);
    return L;
}