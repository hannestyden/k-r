#include <stdio.h>

#define IN      1
#define OUT     0
#define MAXLINE 1000

int getline(char line[], int maxline);
void trim(char to[], char from[]);

int main() {
  char line[MAXLINE];
  char trimmed[MAXLINE];

  while (getline(line, MAXLINE) > 0) {
    trim(trimmed, line);
    printf("%s", trimmed);
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

void trim(char to[], char from[]) {
  int i;
  char c;
  int l;
  int state;

  i = 0;
  l = MAXLINE;
  state = OUT;

  while ((c = from[i]) != '\0') {
    to[i] = c;
    if (c == '\n' || c == '\n' || c == ' ') {
      if (state == IN) {
        state = OUT;
        l = i;
      }
    } else {
      state = IN;
    }
    ++i;
  }
  to[l]     = '\n';
  to[l + 1] = '\0';
}
