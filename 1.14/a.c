#include <stdio.h>

#define IN	1   /* inside a word */
#define OUT 0   /* outside a word */
#define MIN 32  /* char considered out of bound */
#define MAX 127 /* char considered out of bound */

void line(int l)
{
  int j;

  for (j = 0; j < l; ++j)
    putchar('-');
  if (l > 0)
    printf(" (%d)", l);
  printf("\n");
}

int main() {
  int c, i, j, state, wl, out_of_bound, blanks, newlines, tabs;
  int charfreq[MAX];

  state = OUT;
  wl = 0;
  out_of_bound = blanks = newlines = tabs = 0;

  for (i = 0; i < MAX; ++i)
    charfreq[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c > MIN && c < MAX)
      charfreq[c]++;
    else if (c == '\n')
      newlines++;
    else if (c == '\t')
      tabs++;
    else if (c == ' ')
      blanks++;
    else
      out_of_bound++;
  }

  for (j = 0; j < 80; ++j)
    putchar('-');
  printf("\n");

  for (i = MIN + 1; i < MAX; ++i) {
    printf("(%2c)", i);
    line(charfreq[i]);
  }

  printf("(  )");
  line(blanks);

  printf("(\\t)");
  line(tabs);

  printf("(\\n)");
  line(newlines);

  printf("(*>)");
  line(out_of_bound);

  return 0;
}
