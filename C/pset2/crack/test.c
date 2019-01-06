#include <stdio.h>
#include <cs50.h>


int iskey(string n,string ss);
int main(int argc,string argv[]){
if(argc != 3){
    printf("not good usage!");
}
printf("argv1 = %s and argv2 = %s\n",argv[1],argv[2]);
printf("int = %i\n",iskey((char*)argv[1],(char*)argv[2]));    
}


int iskey(string n,string ss){
  //strlen(argv[1])=13
  int m = 0;
  while(n[m] == ss[m] && m < 2){
   if(m == 1){
    return 0;
   }
   m++;
  }
  return 1;
 }