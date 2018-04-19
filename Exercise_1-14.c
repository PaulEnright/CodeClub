#include <stdio.h>

#define NUM_LETTERS 26

/* Creates two histograms of the frequency of each letter in the input (ignoring case). */
main()
{
  int c;
  int i, j;
  int letterCounts[NUM_LETTERS];
  int maxCount = 0;
  
  for (i = 0 ; i < NUM_LETTERS + 1 ; i++)
  {
    letterCounts[i] = 0;
  }
  
  while (c = getchar())
  {
    if (isalpha(c))
    {
      letterCounts[tolower(c) - 'a']++;
    }
    if (c == EOF)
    {
      break;
    }
  }
  
  // Horizontal
  printf("\n\n");
  for (i = 0 ; i <= NUM_LETTERS ; i++)
  {
    printf("%c ", 'a' + i);
    for (j = 0 ; j < letterCounts[i] ; j++)
    {
      printf("X");
    }
    printf("\n");
  }
  
  // Vertical
  printf("\n\n");
  for (i = 0, maxCount = 0 ; i <= NUM_LETTERS ; i++)
  {
    if (letterCounts[i] > maxCount)
    {
      maxCount = letterCounts[i];
    }
  }
  for (j = maxCount ; j > 0 ; j--)
  {
    for (i = 0 ; i <= NUM_LETTERS ; i++)
    {
      if (letterCounts[i] >= j)
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
  for (i = 0 ; i < NUM_LETTERS ; i++)
  {
    printf("  %c", 'a' + i);
  }
  printf ("\n");
}