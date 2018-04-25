#include <stdio.h>

/* Remove all comments from C code (accounting for quoted strings and character constants). */

#define MAX_INPUT_LENGTH (1000)
#define MAX_OUTPUT_COLUMNS (50)

main()
{
  int c, i;
  char inputLine[MAX_INPUT_LENGTH];
  int isInCStyleComment, isInCPlusPlusStyleComment, isInQuotedString, isInCharacterConstant;
  
  // Read input until EOF found.
  i = 0;
  while (c = getchar())
  {
    if (c == EOF)
    {
      inputLine[i] = '\0';
      break;
    }

    inputLine[i] = c;
    i++;
  }

  i = 0;
  isInCStyleComment = 0;
  isInCPlusPlusStyleComment = 0;
  isInQuotedString = 0;
  isInCharacterConstant = 0;
  while (inputLine[i] != '\0')
  {
    if (isInCStyleComment)
    {
      if (inputLine[i] == '*' && inputLine[i+1] == '/')
      {
        isInCStyleComment = 0;
        i++; // Need to increment past both characters.
        // Do not output anything.
      }
    }
    else if (isInCPlusPlusStyleComment)
    {
      // Do not output anything.
      if (inputLine[i] == '\n')
      {
        putchar(inputLine[i]);
        isInCPlusPlusStyleComment = 0;
        i++;
      }
    }
    else if (isInQuotedString)
    {
      putchar(inputLine[i]);
      if (inputLine[i] == '"')
      {
        isInQuotedString = 0;
      }
    }
    else if (isInCharacterConstant)
    {
      putchar(inputLine[i]);
      if (inputLine[i] == '\'')
      {
        isInCharacterConstant = 0;
      }
    }
    else if (inputLine[i] == '"')
    {
      putchar(inputLine[i]);
      isInQuotedString = 1;
    }
    else if (inputLine[i] == '\'')
    {
      putchar(inputLine[i]);
      isInCharacterConstant = 1;
    }
    else if (inputLine[i] == '/' && inputLine[i+1] == '*')
    {
      // Do not output anything.
      isInCStyleComment = 1;
      i++; // Need to increment past both characters
    }
    else if (inputLine[i] == '/' && inputLine[i+1] == '/')
    {
      // Do not output anything.
      isInCPlusPlusStyleComment = 1;
      i++; // Need to increment past both characters
    }
    else
    {
      putchar(inputLine[i]);
    }
    i++;
  }
}