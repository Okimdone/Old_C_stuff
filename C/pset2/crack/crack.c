 #define _XOPEN_SOURCE
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>
 //thought of creating a fonction the save the pain of ctrl +c  ctrl +v but then n thought making the program more automatic an saving the time from making conditions and stuff for every key !! and the keys are "hi .  .   "

/*
andi:50.jPgLzVirkc-->hi
jason:50YHuxoCN9Jkc-->JH
malan:50QvlJWn2qJGE-->NOPE
mzlatkova:50CPlMDLT06yY-->ha
patrick:50WUNAFdX/yjA-->Yale
rbowden:50fkUxYHbnXGw-->rofl
summer:50C6B0oz0HWzo-->FTW
stelios:50nq4RV/NVU0I-->ABC
wmartin:50vtwu4ujL.Dk-->haha
zamyla:50i2t3sOSAZtk-->lol
*/

 //fonction to use
int iskey(string n,string ss);
 //START of int main
 int main(int argc,string argv[]){
  if(argc != 2){
   printf("Usage: ./crack hash\n");
   return 1;
  }
  //give this some time later: https://stackoverflow.com/questions/45318219/c-store-to-null-pointer-error-segmentation-fault
  string s = calloc( 5, sizeof(char));
printf("tries done :  ");
//generate and check keys made of 1 character!!
  int ka,kaa,kaaa,kaaaa,z = 0;
  ka = 'a';
  for(int i = 0;i < 26; i++){
    s[0] = ka + i;
   switch(iskey(crypt( s ,"50"),argv[1])){
    case 0 :
     printf("%i the key is %s\n", z, s);
     return 0;
    case 1 :
     z++;
     }
  }
  //k = A BCDEF..Z
  ka = 'A';
  for(int i = 0;i < 26; i++){
   s[0] = ka + i;
   switch(iskey(crypt(  s ,"50"),argv[1])){
    case 0 :
     printf("%i the key is %s\n", z, s);
     return 0;
    case 1 :
     z++;
   }
  }



//generate and check keys made of 2 characters!!

 kaa = 'a';
  for(int j = 0;j < 26; j++){
  s[1] = kaa + j;
   //check the crypt for S= S1=kaa+i while s0 = all characs
       //k= abcdef ..z
   ka = 'a';
   for(int i = 0;i < 26; i++){
    s[0] = ka + i;
    switch(iskey(crypt( s ,"50"),argv[1])){
     case 0 :
      printf("%i the key is %s\n", z, s);
      return 0;
     case 1 :
      z++;
      }
    }
   //k = A BCDEF..Z
    ka = 'A';
   for(int i = 0;i < 26; i++){
    s[0] = ka + i;
    switch(iskey(crypt(  s ,"50"),argv[1])){
     case 0 :
      printf("%i the key is %s\n", z, s);
      return 0;
     case 1 :
      z++;
    }
   }
 }
 kaa = 'A';
  for(int j = 0;j < 26; j++){
  s[1] = kaa + j;
   //check the crypt for S= S1=kaa+i while s0 = all characs
       //k= abcdef ..z
   ka = 'a';
   for(int i = 0;i < 26; i++){
    s[0] = ka + i;
    switch(iskey(crypt( s ,"50"),argv[1])){
     case 0 :
      printf("%i the key is %s\n", z, s);
      return 0;
     case 1 :
      z++;
      }
    }
   //k = A BCDEF..Z
    ka = 'A';
   for(int i = 0;i < 26; i++){
    s[0] = ka + i;
    switch(iskey(crypt(  s ,"50"),argv[1])){
     case 0 :
      printf("%i the key is %s\n", z, s);
      return 0;
     case 1 :
      z++;
    }
   }
 }


 //generate and check keys made of 3 characters!!

   kaaa = 'a';
   for(int l = 0;l < 26; l++){
    s[2] = kaaa + l;
    kaa = 'a';
    for(int j = 0;j < 26; j++){
    s[1] = kaa + j;
    //check the crypt for S= S1=kaa+i while s0 = all characs
        //k= abcdef ..z
    ka = 'a';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt( s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
       }
     }
    //k = A BCDEF..Z
     ka = 'A';
     for(int i = 0;i < 26; i++){
      s[0] = ka + i;
      switch(iskey(crypt(  s ,"50"),argv[1])){
       case 0 :
        printf("%i the key is %s\n", z, s);
        return 0;
       case 1 :
        z++;
      }
     }
   }
  kaa = 'A';
   for(int j = 0;j < 26; j++){
   s[1] = kaa + j;
    //check the crypt for S= S1=kaa+i while s0 = all characs
        //k= abcdef ..z
    ka = 'a';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt( s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
       }
     }
    //k = A BCDEF..Z
     ka = 'A';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt(  s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
     }
    }
   }
   }

   kaaa = 'A';
   for(int l = 0;l < 26; l++){
    s[2] = kaaa + l;
    kaa = 'a';
    for(int j = 0;j < 26; j++){
    s[1] = kaa + j;
    //check the crypt for S= S1=kaa+i while s0 = all characs
        //k= abcdef ..z
    ka = 'a';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt( s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
       }
     }
    //k = A BCDEF..Z
     ka = 'A';
     for(int i = 0;i < 26; i++){
      s[0] = ka + i;
      switch(iskey(crypt(  s ,"50"),argv[1])){
       case 0 :
        printf("%i the key is %s\n", z, s);
        return 0;
       case 1 :
        z++;
      }
     }
   }
  kaa = 'A';
   for(int j = 0;j < 26; j++){
   s[1] = kaa + j;
    //check the crypt for S= S1=kaa+i while s0 = all characs
        //k= abcdef ..z
    ka = 'a';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt( s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
       }
     }
    //k = A BCDEF..Z
     ka = 'A';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt(  s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
     }
    }
   }
   }
   //generate and check keys made of 4 characters!!

    kaaaa = 'a';
   for(int o = 0;o < 26; o++){
    s[3] = kaaaa + o;
   kaaa = 'a';
   for(int l = 0;l < 26; l++){
    s[2] = kaaa + l;
    kaa = 'a';
    for(int j = 0;j < 26; j++){
    s[1] = kaa + j;
    //check the crypt for S= S1=kaa+i while s0 = all characs
        //k= abcdef ..z
    ka = 'a';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt( s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
       }
     }
    //k = A BCDEF..Z
     ka = 'A';
     for(int i = 0;i < 26; i++){
      s[0] = ka + i;
      switch(iskey(crypt(  s ,"50"),argv[1])){
       case 0 :
        printf("%i the key is %s\n", z, s);
        return 0;
       case 1 :
        z++;
      }
     }
   }
  kaa = 'A';
   for(int j = 0;j < 26; j++){
   s[1] = kaa + j;
    //check the crypt for S= S1=kaa+i while s0 = all characs
        //k= abcdef ..z
    ka = 'a';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt( s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
       }
     }
    //k = A BCDEF..Z
     ka = 'A';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt(  s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
     }
    }
   }
   }

   kaaa = 'A';
 for(int l = 0;l < 26; l++){
 s[2] = kaaa + l;
  kaa = 'a';
   for(int j = 0;j < 26; j++){
    s[1] = kaa + j;
    //check the crypt for S= S1=kaa+i while s0 = all characs
        //k= abcdef ..z
    ka = 'a';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt( s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
       }
    }
    //k = A BCDEF..Z
     ka = 'A';
    for(int i = 0;i < 26; i++){
      s[0] = ka + i;
      switch(iskey(crypt(  s ,"50"),argv[1])){
       case 0 :
        printf("%i the key is %s\n", z, s);
        return 0;
       case 1 :
        z++;
     }
    }
   }
  kaa = 'A';
   for(int j = 0;j < 26; j++){
   s[1] = kaa + j;
    //check the crypt for S= S1=kaa+i while s0 = all characs
        //k= abcdef ..z
    ka = 'a';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt( s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
       }
     }
    //k = A BCDEF..Z
     ka = 'A';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt(  s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
     }
    }
   }
  }
 }
   kaaaa = 'A';
 for(int o = 0;o < 26; o++){
    s[3] = kaaaa + o;
   kaaa = 'a';
   for(int l = 0;l < 26; l++){
    s[2] = kaaa + l;
    kaa = 'a';
    for(int j = 0;j < 26; j++){
    s[1] = kaa + j;
    //check the crypt for S= S1=kaa+i while s0 = all characs
        //k= abcdef ..z
    ka = 'a';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt( s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
       }
     }
    //k = A BCDEF..Z
     ka = 'A';
     for(int i = 0;i < 26; i++){
      s[0] = ka + i;
      switch(iskey(crypt(  s ,"50"),argv[1])){
       case 0 :
        printf("%i the key is %s\n", z, s);
        return 0;
       case 1 :
        z++;
      }
     }
   }
  kaa = 'A';
   for(int j = 0;j < 26; j++){
   s[1] = kaa + j;
    //check the crypt for S= S1=kaa+i while s0 = all characs
        //k= abcdef ..z
    ka = 'a';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt( s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
       }
     }
    //k = A BCDEF..Z
     ka = 'A';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt(  s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
     }
    }
   }
   }

   kaaa = 'A';
   for(int l = 0;l < 26; l++){
    s[2] = kaaa + l;
    kaa = 'a';
    for(int j = 0;j < 26; j++){
    s[1] = kaa + j;
    //check the crypt for S= S1=kaa+i while s0 = all characs
        //k= abcdef ..z
    ka = 'a';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt( s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
       }
     }
    //k = A BCDEF..Z
     ka = 'A';
     for(int i = 0;i < 26; i++){
      s[0] = ka + i;
      switch(iskey(crypt(  s ,"50"),argv[1])){
       case 0 :
        printf("%i the key is %s\n", z, s);
        return 0;
       case 1 :
        z++;
      }
     }
   }
  kaa = 'A';
   for(int j = 0;j < 26; j++){
   s[1] = kaa + j;
    //check the crypt for S= S1=kaa+i while s0 = all characs
        //k= abcdef ..z
    ka = 'a';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt( s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
       }
     }
    //k = A BCDEF..Z
     ka = 'A';
    for(int i = 0;i < 26; i++){
     s[0] = ka + i;
     switch(iskey(crypt(  s ,"50"),argv[1])){
      case 0 :
       printf("%i the key is %s\n", z, s);
       return 0;
      case 1 :
       z++;
     }
    }
   }
  }
 }
printf("no keys found tries %i\n",z);
return 1;
 }

 //function to check if the crypted key and the hash match as fast as i could think of for now!
 int iskey(string n,string ss){
  //strlen(argv[1])=13
  int m = 2;
  while(n[m] == ss[m] && m < 13){
   if(m == 12){
    return 0;
   }
   m++;
  }
  return 1;
 }