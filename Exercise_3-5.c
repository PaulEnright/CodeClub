#include <stdio.h>
#include <string.h>

#define MIN_BASE 2
#define MAX_BASE 16

char *digits = "0123456789ABCDEF";

void reverse(char *s)
{
  int c, i, j;
  
  for (i = 0, j = strlen(s) - 1 ; i < j ; i++, j-- )
  {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itob(int n, char *s, int base)
{
  int index = 0;
  int sign = n;
  
  if (n < 0)
  {
    n = -n;
  }
  
  if ((base < MIN_BASE) || (base > MAX_BASE))
  {
    printf("BASE MUST BE BETWEEN %d and %d.\n", MIN_BASE, MAX_BASE);
    return;
  }
  
  // Generate the number backwards like the example program.
  do
  {
    s[index++] = digits[n % base];
  } while ((n /= base) > 0);
  
  if (sign < 0)
  {
    s[index++] = '-';
  }
  s[index] = '\0';
  
  reverse(s);
}

main()
{
  int n, base;
  char s[1000];
  
  printf("Enter number to convert: ");
  scanf("%d", &n);
  printf("Enter base to convert to: ");
  scanf("%d", &base);
  
  itob(n, s, base);
  
  printf("Original Number: %d, Converted Number (Base %d): %s\n", n, base, s);
}