/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool look(int value, int values[],int m, int min,int max){
        m = (int) (max + min)/2;
        if(min>max)
            return false;
        else if(value == values[m]){
            return true;
        }
        else if(value < values[m]){
            max =m - 1;
            return look(value, values , m, min, max);
        }
        else if(value > values[m]){ 
            min = m+1;
            return look(value, values , m, min, max);
        }
        return false;
}


bool search(int value, int values[], int n){
    // TODO: implement a searching algorithm
    int m,min = 0, max = n - 1;
    m = (int) (max + min)/2;
    return look(value, values,m,min, max);
    
  
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n){
    // Insertion Sort

    // changed argthe argument size to (size -1)  in find.c , so as to not enter the loop at the last n , that should alreaby be the bigger out of everything , and so as to not have to calculate n-1 everytime in the loop , n to not have to call an other variable int k = n-1; i<k ; no point in making the alg uglier 
    
    int swap;
    for(int i = 1 ; i < n;i++ ){
        for(int j = 0; j < i; j++){
             
            if(values[i] <= values[j]){
                //keep swaping until values[i] is in values[j+1]`s place
                swap = values[i];
                for(int k = i ; k > j;k--){ 
                    values[k] = values[k - 1];    
                }
                values[j] = swap;
                continue;
            }
        }
    }
    return;
}
