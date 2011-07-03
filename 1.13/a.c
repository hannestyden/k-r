#include <stdio.h>

#define IN	1  /* inside a word */
#define OUT 0  /* outside a word */
#define MAX 32 /* max length for a word, larger words are grouped */

int main() {
  int c, i, j, state, wl, too_long;
  int wordlength[MAX];

  state = OUT;
  wl = 0;
  too_long = 0;

  for (i = 0; i < MAX; ++i)
    wordlength[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        if (wl < MAX)
          wordlength[wl]++;
        else
          too_long++;
        wl = 0;
      }
      state = OUT;
    } else {
      state = IN;
      wl++;
    }
  }

  for (j = 0; j < 80; ++j)
    putchar('-');
  printf("\n");

  for (i = 1; i < MAX; ++i) {
    printf("%3d ", i);
    for (j = 0; j < wordlength[i]; ++j)
      putchar('-');
    if (wordlength[i] > 0)
      printf(" (%d)", wordlength[i]);
    printf("\n");
  }

  printf(">%d ", MAX - 1);
  for (j = 0; j < too_long; ++j)
    putchar('-');
  if (too_long > 0)
    printf(" (%d)", too_long);
  printf("\n");

  return 0;
}
