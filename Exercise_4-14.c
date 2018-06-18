#include <stdio.h>

#define swap(t, x, y) {t temp; temp=(x); (x)=(y); (y)=temp;}

main()
{
  int i1=5;
  int i2=-9;
  float f1=-14.29;
  float f2=3.45;
  
  printf("Before swap (int): %d %d\n", i1, i2);
  swap(int, i1, i2);
  printf(" After swap (int): %d %d\n\n", i1, i2);
  
  printf("Before swap (float): %.2f %.2f\n", f1, f2);
  swap(float, f1, f2);
  printf(" After swap (float): %.2f %.2f\n\n", f1, f2);  
  
}