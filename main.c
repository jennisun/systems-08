#include <stdio.h>
#include "main.h"

int mystrlen( char *s ) {
  int i = 0;
  while (*(s + i) != '\0') {
    i += 1;
  }
  return i;
}

int main() {
  char s2[100] = "hello";
  printf("[standard]:\t%d\n", mystrlen(s2) );
  return 0;
}
