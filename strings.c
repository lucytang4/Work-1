#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int strlen2(char *a){
  int ctr = 0;
  while (a[ctr] != 0)
    ctr++;
  return ctr;
}

char * strcpy2( char *dest, char *source){
  int ctr = 0;
  for (; ctr < sizeof(dest); ctr++)
    dest[ctr] = source[ctr];
  return dest;
}

char * strncat2(char *dest, char *source, int n){
  int destCtr = strlen(dest), sourceCtr = 0;
  for (; sourceCtr < n; sourceCtr++){
    dest[destCtr] = source[sourceCtr];
    destCtr++;
  }
  return dest;
}

int strcmp2( char *s1, char *s2){
  int ctr = 0, minL, min;
  if (strlen(s1) < strlen(s2)){
    minL = strlen(s1);
    min = -1;
  }
  else{
    minL = strlen(s2);
    min = 1;
  }
  for (; ctr < minL; ctr++){
    if (s1[ctr] < s2[ctr])
      return -1;
    else if (s2[ctr] < s1[ctr])
      return 1;
  }
  if (strlen(s1) == strlen(s2))
    return 0;
  return min;
}

char * strchr2( char *s, char c){
  int ctr = 0;
  for (; ctr < strlen(s); ctr++)
    if (s[ctr] == c)
      return &s[ctr];
  return NULL;
}

int main(){
  char str1[5];
  printf("strlen of str1[5] : %d\n", strlen(str1)); //0
  printf("strlen2 of str1[5] : %d\n", strlen2(str1)); //0

  char str2[100] = "hey";
  printf("strlen of str2[100] = \"hey\" : %d\n", strlen(str2)); //3
  printf("strlen2 of str2[100] = \"hey\" : %d\n\n", strlen2(str2)); //3

  char str3[5] = "none";
  char str4[5] = "none";
  char str5[5] = "abcd";
  char str6[5] = "abcd";
  printf("str3[5] : %s\n", str3);
  printf("str4[5] : %s\n", str4);
  printf("str3[5] after strcpy \"bay\" : %s\n", strcpy(str3, "bay")); //bay
  printf("str4[5] after strcpy2 \"bay\" : %s\n\n", strcpy2(str4, "bay")); //bay

  char str7[10] = "hey";
  char str8[10] = "hey";
  char str9[10] = "ya";
  printf("strncat str7[10] = \"hey\" and str9[10] = \"ya\" for 1 char : %s\n", strncat(str7,str9,1)); //heyy
  printf("strncat2 str8[10] = \"hey\" and str8[10] = \"ya\" for 1 char : %s\n\n", strncat2(str8,str9,1)); //heyy

  printf("strcmp \"hey\" and \"none\" : %d\n", strcmp("hey","none")); //-1
  printf("strcmp2 \"hey\" and \"none\" : %d\n", strcmp2("hey","none")); //-1
  printf("strcmp \"bone\" and \"none\" : %d\n", strcmp("bone","none")); //-1
  printf("strcmp2 \"bone\" and \"none\" : %d\n", strcmp2("bone","none")); //-1

  printf("strcmp \"ze\" and \"none\" : %d\n", strcmp("ze","none")); //1
  printf("strcmp2 \"ze\" and \"none\" : %d\n", strcmp2("ze","none")); //1
  printf("strcmp \"name\" and \"none\" : %d\n", strcmp("nzme","none")); //1
  printf("strcmp2 \"name\" and \"none\" : %d\n", strcmp2("nzme","none")); //1

  printf("strcmp \"none\" and \"none\" : %d\n", strcmp("none","none")); //0
  printf("strcmp2 \"none\" and \"none\" : %d\n\n", strcmp2("none","none")); //0

  printf("strchr \"hey\" and \"e\" : %s\n", strchr("hey",'e')); //ey
  printf("strchr2 \"hey\" and \"e\" : %s\n", strchr2("hey",'e')); //ey

  printf("strchr \"hey\" and \"a\" : %s\n", strchr("hey",'a')); //NULL
  printf("strchr2 \"hey\" and \"a\" : %s\n", strchr2("hey",'a')); //NULL

  return 0;
}
