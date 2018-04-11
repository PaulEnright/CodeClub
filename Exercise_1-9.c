#include <stdio.h>

/* Replace multiple spaces with one space. */
main()
{
  int c;
  int spaceEncountered = 0;
  
  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
      if (!spaceEncountered)
      {
        putchar(c);
        spaceEncountered = 1;
      }
    }
    else
    {
      putchar(c);
      spaceEncountered = 0;
    }
  }
}
