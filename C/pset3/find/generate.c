/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // if the user enters no argv or more than 2 argv printf the Usage n stop the program returning 0!
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // turn the number in argv[1] (1st argument) stored as a string into an int stored in n!
    int n = atoi(argv[1]);

    // srand48() is an initialization functions, one of which should be called before using drand48(),so if their is a seed it takes it as an argument , if not it takes what ever the fonction time() give it !
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    // The function drand48() stores the last 48-bit Xi generated in an internal buffer, generates an X from it , and 0 <= X <= 1 , then multiply it by the LIMIT number which would give as an int between 0 and 65536 and print it out !  
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
