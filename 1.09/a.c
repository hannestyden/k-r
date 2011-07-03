#include <stdio.h>

int main() {
  int cc; /* Current character  */
  int pc; /* Previous character */

  while ((cc = getchar()) != EOF) {
    if (cc != ' ' || cc != pc) {
      /* If current character is not blank
       * or if it is but the previous was not.
       */
      putchar(cc);
    }
    pc = cc;
  }

  return 0;
}
