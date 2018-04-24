#include <stdio.h>

/* Replace strings of spaces with tabs. */

#define TAB_SIZE  (8)
#define MAX_INPUT_LENGTH (500)

main()
{
  int c, i;
  char inputLine[MAX_INPUT_LENGTH];
  int column = 0;
  int numSpaces = 0;
  
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

  // Output the line replacing strings of spaces with tabs.
  column = 0;
  for (i = 0 ; inputLine[i] != '\0' ; i++)
  {
    if (inputLine[i] == ' ')
    {
      numSpaces++;
    }
    else
    {
      if (numSpaces == 1)
      {
        putchar(' ');
        column++;
      }
      else if (numSpaces > 1)
      {
        int numTabs = (column % TAB_SIZE + numSpaces) / TAB_SIZE;
        int numTrailingSpaces = (column % TAB_SIZE + numSpaces) % TAB_SIZE;
        int j;
        for (j = 0 ; j < numTabs ; j++)
        {
          putchar('\t');
        }
        for (j = 0 ; j < numTrailingSpaces ; j++)
        {
          putchar(' ');
        }
        column += numSpaces;
      }
      numSpaces = 0;
      putchar(inputLine[i]);
      column++;
    }
  }
}