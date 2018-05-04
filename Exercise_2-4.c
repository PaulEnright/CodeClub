#include <stdio.h>

int hasChar(const char string[], int c)
{
  int i;
  
  // Returns 1 if character c is contained in the given string.
  for (i = 0 ; string[i] != '\0' ; i++)
  {
    if (string[i] == c) return 1;
  }
  return 0;
}

void squeeze(char s1[], const char s2[])
{
  int i, j;
  
  for (i = 0, j = 0 ; s1[i] != '\0' ; i++)
  {
    if (!hasChar(s2, s1[i]))
    {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
}

#define MAXLINE 1000

main()
{
  char s1[MAXLINE], s2[MAXLINE];
  
  _getline(s1, MAXLINE);
  _getline(s2, MAXLINE);
  
  squeeze(s1, s2);
  
  printf("RESULT: %s\n", s1);
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
