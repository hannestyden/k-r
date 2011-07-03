#include <stdio.h>

#define LOWER 0   /* lower limit */
#define UPPER 300 /* upper limit */
#define STEP  20  /* step size   */

#define TABLE_ROW "%10.2f  %7.2f\n" /* table row format */

/* print Fahrenheit-Celsius table for fahr = 300, 280, ..., 0 */

int main() {
  float fahr;

  /* Table heading */
  printf("Fahrenheit  Celsius\n");

  /* Table body */
  for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    printf(
      TABLE_ROW,
      fahr, 
      (fahr - 32) * 5 / 9
    );
  }

  return 0;
}
