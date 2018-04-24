#include <stdio.h>

/* Replace tabs with strings of spaces. */

#define TAB_SIZE  (8)
#define MAX_INPUT_LENGTH (500)

main()
{
  int c, i;
  char inputLine[MAX_INPUT_LENGTH];
  int column = 0;
  
  // Read in a line of input.
  while (c = getchar())
  {
    inputLine[column] = c;
    column++;
    
    if ((c == EOF) || (c == '\n'))
    {
      break;
    }
  }

  // Output the line replacing tabs with spaces.
  column = 0;
  for (i = 0 ; inputLine[i] != '\0' ; i++)
  {
    if (inputLine[i] == '\t')
    {
      int j;
      int numSpaces = TAB_SIZE - (column % TAB_SIZE);
      for (j = 0 ; j < numSpaces ; j++)
      {
        putchar(' ');
        column++;
      }
    }
    else
    {
      putchar(inputLine[i]);
      column++;
    }
  }
}