 #include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
    int p[2];
    pipe(p);
    char txt[200];

    if(fork()==0){
        close(p[0]);
        write(p[1], "Hello1 ", 7);
        write(p[1], "Hello2", 7);
        close(p[1]);

    }
    else{
        close(p[1]);
        close(0);dup(p[0]);
        scanf("%[^\n]\n", txt);

        printf("txt : %s\n", txt);
    }
}