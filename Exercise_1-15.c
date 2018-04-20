#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */

float fahrToCelsius(float fahr)
{
  return (5.0/9.0) * (fahr - 32.0);
}

main()
{
  float fahr, celsius;
  int lower, upper, step;
  
  lower = 0;    /* lower limit of temperature table */
  upper = 300;  /* upper limit */
  step = 20;    /* step size */
  
  fahr = lower;
  printf("FAHR CELSIUS\n");
  while (fahr <= upper) {
    celsius = fahrToCelsius(fahr);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}