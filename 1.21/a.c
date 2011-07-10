#include <stdio.h>

#define MAXLINE 80
#define COL_WIDTH 8

#define IN 1
#define OUT 0

int getline(char line[], int maxline);
void entab(char to[], char from[]);

int main() {
  int  len;
  char line[MAXLINE];
  char entabbed[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0) {
    entab(entabbed, line);
    printf("%s", entabbed);
  }

  return 0;
}

int getline(char s[],int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

void entab(char to[], char from[]) {
  int i, j, k;
  int state;
  int tabs;
  int blanks;
  int start;
  int off;
  char c;

  blanks = tabs = 0;

  i = j = 0;
  state = IN;
  while((c = from[i]) != '\0') {
    if (c == ' ' || c == '\t') {
      if (state == IN) {
        fprintf(stderr, "Opening at %d\n", i);
        state = OUT;
        start = i;
      }
      if (c == ' ') {
        blanks++;
        fprintf(stderr, "O: %d, B: %d.\n", i, blanks);
        if (blanks % COL_WIDTH == 0) {
          fprintf(stderr, "Enough with the blanks.\n");
          blanks = 0;
          tabs++;
        }
      } else if (c == '\t') {
        blanks = 0;
        tabs++;
      }
    } else {
      if (state == OUT) {
        fprintf(stderr, "Closing time at %d\n", i);
        state = IN;
        off = start % COL_WIDTH;
        fprintf(stderr, "Off %d\n", off);

        if (off > 0 && (off + blanks) % COL_WIDTH == 0) {
          blanks = 0;
          tabs++;
        }
        fprintf(stderr, "Tabs %d\n", tabs);
        for (k = 0; k < tabs; ++k) {
          to[j] = '\t';
          ++j;
        }

        fprintf(stderr, "Blanks %d\n", blanks);
        for (k = 0; k < blanks; ++k) {
          to[j] = ' ';
          ++j;
        }
        blanks = tabs = 0;
      }
      to[j] = c;
      ++j;
    }

    ++i;
  }

  to[j] = '\0';
}
