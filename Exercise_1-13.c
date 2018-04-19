#include <stdio.h>

#define MAX_WORD_LENGTH 20

/* Creates two histograms showing the word lengths of the input data. */
main()
{
  int c;
  int i, j;
  int prevCharWasSpace = 0;
  int wordLengthCounts[MAX_WORD_LENGTH + 1];  // All words >= 20 characters go into the last entry.
  int charCount = 0;
  int maxCount = 0;
  
  for (i = 0 ; i < MAX_WORD_LENGTH + 1 ; i++)
  {
    wordLengthCounts[i] = 0;
  }
  
  while (c = getchar())
  {
    if ((c == '\t') || (c == ' ') || (c == EOF) || (c == '\n'))
    {
      if (!prevCharWasSpace)
      {
        if (charCount == 0)
        {
          // Do nothing.
        }
        else if (charCount <= MAX_WORD_LENGTH)
        {
          wordLengthCounts[charCount]++;
        }
        else
        {
          wordLengthCounts[MAX_WORD_LENGTH]++;
        }
      }
      prevCharWasSpace = 1;
      charCount = 0;
    }
    else
    {
      charCount++;
      prevCharWasSpace = 0;
    }
    
    if (c == EOF)
    {
      break;
    }
  }
  
  // Horizontal
  printf("\n\n");
  for (i = 0 ; i <= MAX_WORD_LENGTH ; i++)
  {
    printf("%02u", i);
    for (j = 0 ; j < wordLengthCounts[i] ; j++)
    {
      printf("X");
    }
    printf("\n");
  }
  
  // Vertical
  printf("\n\n");
  for (i = 0, maxCount = 0 ; i <= MAX_WORD_LENGTH ; i++)
  {
    if (wordLengthCounts[i] > maxCount)
    {
      maxCount = wordLengthCounts[i];
    }
  }
  for (j = maxCount ; j > 0 ; j--)
  {
    for (i = 0 ; i <= MAX_WORD_LENGTH ; i++)
    {
      if (wordLengthCounts[i] >= j)
      {
        printf("  X");
      }
      else
      {
        printf("   ");
      }
    }
    printf("\n");
  }
  // Footer
  for (i = 0 ; i < MAX_WORD_LENGTH ; i++)
  {
    printf(" %2d", i);
  }
  printf (">20\n");
}