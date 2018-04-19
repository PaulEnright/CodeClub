#include <stdio.h>

/* Prints each input word on a separate line. */
main()
{
  int c;
  int prevCharWasSpace = 0;
  
  while ((c = getchar()) != EOF)
  {
    if ((c == '\t') || (c == ' '))
    {
      if (!prevCharWasSpace)
      {
        putchar('\n');
      }
      prevCharWasSpace = 1;
    }
    else
    {
      prevCharWasSpace = 0;
      putchar(c);
    }
  }
}