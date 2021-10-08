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
  int i = mystrlen(dest);
  int c = i;
  while (*(source + c)) {
    *(dest + i) = *(source + c - i);
    c += 1;
  }
  *(dest + i + c) = '\0';
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

char * mystrchr( char *s, char c ) {
  while (*s != c && *s) {
    s += 1;
  }
  if (*s == c) return s;
  else return 0;
}
