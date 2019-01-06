#include <stdlib.h>
#include <setjmp.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
static jmp_buf env;



int main(void)
{
  //asm ("movl $payload, %eax");
  printf("g");
  asm (".byte 0x0f, 0x3f");
  printf("g2");
  int fd = open("test.txt",O_RDONLY);
  if(fd=-1){
    perror("open");
    exit(EXIT_FAILURE);

  }
  exit(EXIT_SUCCESS);
}