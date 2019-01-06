#include <unistd.h>
#include <stdio.h>
int main()
{
    repeat:

    if(fork() < 0)
    {
        perror("Error :");
    }
    goto repeat;
}