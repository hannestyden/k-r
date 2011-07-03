#include <stdio.h>

int main() {
  int b;

  while ((b = (getchar() != EOF))) {
    printf("%d", b);
  }
  printf("%d", b);
  printf("\n");

  return 0;
}
