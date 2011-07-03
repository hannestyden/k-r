#include <stdio.h>

/* print
 * Celsius - Fahrenheit table for celsius = -20, 0, ..., 160 */

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = -20; /* lower limit of temperature scale */
  upper = 160; /* upper limit                      */
  step  = 20;  /* step size                        */

  /* Table heading */
  printf("Celsius  Fahrenheit\n");

  /* Table body */
  celsius = lower;
  while (celsius <= upper) {
    fahr = 32 + (9 * celsius / 5); 
    printf("%7.2f  %10.2f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}
