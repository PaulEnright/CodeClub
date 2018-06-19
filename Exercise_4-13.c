#include <stdio.h>
#include <string.h>

void recursiveReverse(char *s, int startIndex, int endIndex)
{
  if (startIndex < endIndex)
  {
    char temp;
    recursiveReverse(s, startIndex + 1, endIndex - 1);
    temp = s[startIndex];
    s[startIndex] = s[endIndex];
    s[endIndex] = temp;
  }
}

void reverse(char *s)
{
  recursiveReverse(s, 0, strlen(s) - 1);
}

#define MAXLINE 1000

main()
{
  char s[MAXLINE];
  
  _getline(s, MAXLINE);
  
  printf("ORIGINAL: %s\n", s);

  reverse(s);
  
  printf("REVERSED: %s\n", s);
}


/* getline: read a line into s, return length */
int _getline(char s[], int lim)
{
  int c, i;

  for (i = 0; (i < lim-1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
    s[i] = c;
  s[i] = '\0';
  return i;
}