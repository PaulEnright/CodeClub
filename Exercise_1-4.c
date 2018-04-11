#include <stdio.h>

/* print Celsius-Fahrenheit table
    for celsius = 0, 5, ..., 100; floating-point version */
main()
{
  float fahr, celsius;
  int lower, upper, step;
  
  lower = 0;    /* lower limit of temperature table */
  upper = 100;  /* upper limit */
  step = 5;    /* step size */
  
  fahr = lower;
  printf("CELSIUS FAHR\n");
  while (celsius <= upper) {
    fahr = (9.0/5.0) * celsius + 32.0;
    printf("%8.0f %6.1f\n", fahr, celsius);
    celsius = celsius + step;
  }
}