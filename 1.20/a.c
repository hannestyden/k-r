#include <stdio.h>

#define MAXLINE 80
#define COL_WIDTH 8

int getline(char line[], int maxline);
void detab(char to[], char from[]);

int main() {
  int  len;
  char line[MAXLINE];
  char detabbed[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0) {
    detab(detabbed, line);
    printf("%s", detabbed);
  }

  return 0;
}

int getline(char s[],int lim) {
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

void detab(char to[], char from[]) {
  int i, j, k, pad;
  char c;

  i = j = 0;
  while((c = from[i]) != '\0') {
    if (c == '\t') {
      to[j] = ' ';
      pad = COL_WIDTH - (j % COL_WIDTH);
      for (k = 1; k < pad; ++k) {
        ++j;
        to[j] = ' ';
      }
    } else
      to[j] = c;


    ++j;
    ++i;
  }

  to[j] = '\0';
}
