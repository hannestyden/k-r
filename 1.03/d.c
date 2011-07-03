#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;   /* lower limit of temperature scale */
  upper = 300; /* upper limit                      */
  step  = 20;  /* step size                        */

  /* Table heading */
  printf("Fahrenheit  Celsius\n");

  /* Table body */
  fahr = lower;
  while (fahr <= upper) {
    celsius = (fahr - 32) * 5 / 9;
    printf("%10.2f  %7.2f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}
