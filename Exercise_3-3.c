#include <stdio.h>

void expand(const char *s1, char *s2)
{
  int s1Index = 0;
  int s2Index = 0;
  char arg1 = '\0';
  char arg2 = '\0';
  int dashFound = 0;
  
  // Skip over any leading -.
  for (s1Index = 0 ; s1[s1Index] == '-' ; s1Index++)
  {
    s2[s2Index++] = '-';
  }
  
  //??? STILL NEED TO HANDLE a-b-c
  
  arg1 = '\0';
  dashFound = 0;
  for ( ; s1[s1Index] != '\0' ; s1Index++)
  {
    if (arg1 == '\0')
    {
      if (isalpha(s1[s1Index]) || isdigit(s1[s1Index]))
      {
        arg1 = s1[s1Index];
        dashFound = 0;
      }
      else
      {
        // Output as literal.
        s2[s2Index++] = s1[s1Index];
      }
    }
    else if (!dashFound)
    {
      if (s1[s1Index] == '-')
      {
        dashFound = 1;
      }
      else
      {
        // No dash. Output arg1 as a literal.
        s2[s2Index++] = arg1;
        arg1 = s1[s1Index];
      }
    }
    else
    {
      // Dash has been found and we have the first argument.
      arg2 = s1[s1Index];
      if ((isalpha(arg1) && islower(arg1) && isalpha(arg2) && islower(arg2)) || // Valid lower-case letter range
          (isalpha(arg1) && isupper(arg1) && isalpha(arg2) && isupper(arg2)) || // Valid upper-case letter range
          (isdigit(arg1) && isdigit(arg2)))
      {
        char c;
        for (c = arg1 ; c <= arg2 ; c++)
        {
          s2[s2Index++] = c;
        }
      }
      else
      {
        // Improper syntax (such as a-8). Output as literals.
        s2[s2Index++] = arg1;
        s2[s2Index++] = '-';
        s2[s2Index++] = arg2;
      }
        
      arg1 = '\0';
      dashFound = 0;
    }
  }
  
  if (arg1)
  {
    s2[s2Index++] = arg1;
    
    if (dashFound)
    {
      s2[s2Index++] = '-';
    }
  }
  
  s2[s2Index] = '\0';
}

#define MAXLINE 1000

main()
{
  char s1[50], s2[MAXLINE];
  
  _getline(s1, MAXLINE);
  
  expand(s1, s2);
  
  printf("ORIGINAL: %s\n", s1);
  printf("  RESULT: %s\n", s2);
}


/* getline: read a line into s, return length */
int _getline(char s[], int lim)
{
  int c, i;

  for (i = 0; (i < lim-1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
    s[i] = c;
  if (c == '\n')
  {
      s[i] = c;
      ++i;
  }
  s[i] = '\0';
  return i;
}