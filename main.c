#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

int mystrlen( char *s ) {
  int i = 0;
  while (*(s + i) != '\0') {
    i += 1;
  }
  return i;
}

char * mystrncpy( char *dest, char *source, int n) {
  int i = 0;
  for (i = 0; i < n; i ++) {
    *(dest + i) = *(source + i);
  }
  *(dest + n) = '\0';
  return dest;
}

char * mystrcat( char *dest, char *source ) {
  int i = 0;
  int k  = 0;
  i = mystrlen(dest);
  while (*(source + k) != '\0') {
    *(dest + i + k - 2) = *(source + k);
    k += 1;
  }
  *(dest + i + k) = '\0';
  return dest;
}

int main() {
  char s1[100];
  char s2[100] = "hello";
  char s3[100] = "goodbye";

  printf("start strings:\n");
  printf("s1: [%s]\n", s1);
  printf("s2: [%s]\n", s2);
  printf("s3: [%s]\n", s3);

  printf("\nTesting strlen(s2):\n");
  printf("[standard]:\t%lu\n", strlen(s2) );
  printf("[mine]:\t\t%d\n", mystrlen(s2) );

  printf("\nTesting strncpy(s1, s3, 3):\n");
  printf("[standard]:\t[%s]\n", strncpy(s1, s3, 3) );
  printf("[mine]:\t\t[%s]\n", mystrncpy(s1, s3, 3) );

  printf("\nTesting strcat(s1, s3):\n");
  printf("[standard]:\t[%s]\n", strcat(s1, s3) );
  s1[5] = 0;
  printf("[mine]:\t\t[%s]\n", mystrcat(s1, s3) );

  return 0;
}
