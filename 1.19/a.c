#include <stdio.h>

#define MAXLINE 10

int getline(char line[], int maxline);
void reverse(char to[], char from[], int len);

int main() {
  int  len;
  char line[MAXLINE];
  char reversed[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0) {
    reverse(reversed, line, len);
    printf("%s", reversed);
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

void reverse(char to[], char from[], int len) {
  int i;

  for (i = 0; i < len - 1; ++i) {
    to[len - i - 2] = from[i];
  }
  to[len - 1] = '\n';
  to[len]     = '\0';
}
