#include <stdio.h>

/* Word wrap lines to fit within N columns. */

#define MAX_INPUT_LENGTH (1000)
#define MAX_OUTPUT_COLUMNS (50)
#define TAB_SIZE (8)

main()
{
  int c, i;
  char inputLine[MAX_INPUT_LENGTH];
  int lineStartIdx = 0;
  int lineEndIdx = 0;
  int inputLength = 0;
  int lastWhitespace = -1;
  int column;
  
  // Read in a line of input.
  while (c = getchar())
  {
    if ((c == EOF) || (c == '\n'))
    {
      inputLine[inputLength] = '\0';
      inputLength++;
      break;
    }

    inputLine[inputLength] = c;
    inputLength++;
  }

  //Show column headers.
  for (i = 0 ; i < MAX_OUTPUT_COLUMNS ; i++)
  {
    if (i / 10 > 0)
    {
      putchar('0' + (i / 10));
    }
    else
    {
      putchar(' ');
    }
  }
  putchar('\n');
  for (i = 0 ; i < MAX_OUTPUT_COLUMNS ; i++)
  {
    putchar('0' + (i % 10));
  }
  putchar('\n');
  
  // Output the text, word-wrapping at the maximum column size.
  lineStartIdx = 0;
  while (lineEndIdx < inputLength - 1)
  {
    lastWhitespace = -1;
    lineEndIdx = lineStartIdx;
    column = 0;
    while ((column < MAX_OUTPUT_COLUMNS - 1) && (lineEndIdx < inputLength - 1))
    {
      if (inputLine[lineEndIdx] == ' ')
      {
        lastWhitespace = lineEndIdx;
        column++;
      }
      else if (inputLine[lineEndIdx] == '\t')
      {
        lastWhitespace = lineEndIdx;
        column += (TAB_SIZE - (lineEndIdx % TAB_SIZE));
      }
      else
      {
        column++;
      }
      lineEndIdx++;
    }
    
    if (lineEndIdx < inputLength - 1)
    {
      if (lastWhitespace != -1)
      {
        lineEndIdx = lastWhitespace;
      }
      // else Line with no whitespace. Output the characters (nothing to do - variables are already correct to do this).
    }
    
#if 0
    if (lineStartIdx + MAX_OUTPUT_COLUMNS - 1 < inputLength)
    {
      lineEndIdx = lineStartIdx + MAX_OUTPUT_COLUMNS - 1;
      // Find the last space/tab in this "column"
      for (i = lineEndIdx ; i > lineStartIdx ; i--)
      {
        if (inputLine[i] == ' ' || inputLine[i] == '\t')
        {
          // Found!
          lineEndIdx = i;
          break;
        }
      }
      // No spaces/tabs found. Simply output all characters.
      if (lineEndIdx <= lineStartIdx)
      {
        lineEndIdx = lineStartIdx + MAX_OUTPUT_COLUMNS - 1;
      }
    }
    else
    {
      // Last line. Output everything remaining.
      lineEndIdx = inputLength - 1;
    }
#endif
    
    // Output the line.
    for (i = lineStartIdx ; i <= lineEndIdx ; i++)
    {
      putchar(inputLine[i]);
    }
    putchar('\n');
    lineStartIdx = lineEndIdx;
    // Eliminate leading spaces/tabs.Eliminate
    while (lineStartIdx < inputLength - 1)
    {
      if (inputLine[lineStartIdx] == ' ' || inputLine[lineEndIdx] == '\t')
      {
        lineStartIdx++;
      }
      else
      {
        break;
      }
    }
  }
}