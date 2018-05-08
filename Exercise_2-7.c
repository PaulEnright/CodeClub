#include <stdio.h>

int invert(int x, int p, int n)
{
  int bit;
 
  if (p > 31)
  {
    printf("INVALID STARTING BIT\n");
    return x;
  }
  
  for (bit = p ; bit < 32 && bit < p + n ; bit++)
  {
    x ^= (1 << bit);
  }
  return x;
}

main()
{
  int x, bit, bitCount, result;
  
  printf("Enter integer: ");
  scanf("%d", &x);
  printf("Enter starting bit: ");
  scanf("%d", &bit);
  printf("Enter number of bits: ");
  scanf("%d", &bitCount);
  
  result = invert(x, bit, bitCount);
  
  printf("Original Number: %08x, Result: %08x\n", x, result);
}