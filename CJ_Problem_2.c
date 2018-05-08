#include <stdio.h>

int isPowerOfTwo(int x)
{
  int bit, bitCount;
  
  for (bit = 0, bitCount = 0 ; bit < 32 ; bit++)
  {
    if (x & (1 << bit))
    {
      bitCount++;
    }
  }
  
  return (bitCount == 1 ? 1 : 0);
}

main()
{
  int x, result;
  
  printf("Enter integer: ");
  scanf("%d", &x);
  
  result = isPowerOfTwo(x);
  
  printf("%d %s a power of two.\n", x, (result ? "is" : "is not"));
}