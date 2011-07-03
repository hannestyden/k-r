#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void print(int length, char string[]);

int main() {
  int len;
  int max;
  char line[MAXLINE];

  max = 0;
  while ((len = getline(line, MAXLINE)) > 0)
    print(len, line);

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

void print(int length, char string[]) {
  printf("%d: %s", length, string);
}
