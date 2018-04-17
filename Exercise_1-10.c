#include <stdio.h>

/* Replace tabs, backspaces and backslashes with their escaped forms. */
main()
{
  int c;
  
  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      putchar('\\');
      putchar('t');
    }
    else if (c == '\\')
    {
      putchar('\\');
      putchar('\\');
    }
    else if (c == '\b')
    {
      putchar('\\');
      putchar('b');
    }
    else
    {
      putchar(c);
    }
  }
}