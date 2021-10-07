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

int mystrcmp( char *s1, char *s2 ) {
  unsigned char *p1 = s1;
  unsigned char *p2 = s2;

  while (*p1 != 0 || *p2 != 0) {
    if (*p1 > *p2) return 1;
    if (*p1 < *p2) return -1;
    p1 += 1;
    p2 += 1;
  }
  return 0;
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

  printf("\nTesting strcmp\n");
  printf("\tComparting ab to abc:\n");
  printf("\t\t[standard]:\t[%d]\n", strcmp("ab", "abc") );
  printf("\t\t[mine]:\t\t[%d]\n", mystrcmp("ab", "abc") );
  printf("\tComparting abc to ab:\n");
  printf("\t\t[standard]:\t[%d]\n", strcmp("abc", "ab") );
  printf("\t\t[mine]:\t\t[%d]\n", mystrcmp("abc", "ab") );
  printf("\tComparting abc to abc:\n");
  printf("\t\t[standard]:\t[%d]\n", strcmp("abc", "abc") );
  printf("\t\t[mine]:\t\t[%d]\n", mystrcmp("abc", "abc") );

  return 0;
}
