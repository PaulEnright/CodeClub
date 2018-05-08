#include <stdio.h>

int invert(int x)
{
  int bit;
 
  for (bit = 0 ; bit < 32 ; bit++)
  {
    x ^= (1 << bit);
  }
  return x;
}

main()
{
  int x, result;
  
  printf("Enter integer: ");
  scanf("%d", &x);
  
  result = invert(x);
  
  printf("Original Number: %08x, Result: %08x\n", x, result);
}