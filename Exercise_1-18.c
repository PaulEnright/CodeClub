#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);

int main(void)
{
  int len;                  // current line length
  char line[MAXLINE];       // current input line
  int i;
  
  while ((len = _getline(line, MAXLINE)) > 0)
  {
    for (i = len - 1 ; i >= 0 ; i--)
    {
      if ((line[i] != ' ') && (line[i] != '\t'))
      {
        break;
      }
    }
    line[i+1] = 0;
    if (line[0] != '\0')
    {
      printf("TRIMMED LINE: <%s>\n", line);
    }
  }
  return 0;
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
