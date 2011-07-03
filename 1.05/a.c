#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 300, 280, ..., 0 */

int main() {
  float fahr;

  /* Table heading */
  printf("Fahrenheit  Celsius\n");

  /* Table body */
  for (fahr = 300; fahr >= 0; fahr -= 20) {
    printf(
      "%10.2f  %7.2f\n",
      fahr, 
      (fahr - 32) * 5 / 9
    );
  }

  return 0;
}
