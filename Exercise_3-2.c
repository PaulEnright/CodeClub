#include <stdio.h>

void escape(char *s, const char *t)
{
  int tIndex = 0;
  int sIndex = 0;
  
  for (tIndex = 0 ; t[tIndex] != '\0' ; tIndex++)
  {
    switch(t[tIndex])
    {
      case '\t':
        s[sIndex++] = '\\';
        s[sIndex++] = 't';
        break;
        
      case '\n':
        s[sIndex++] = '\\';
        s[sIndex++] = 'n';
        break;
        
      default:
        s[sIndex++] = t[tIndex];
        break;
    }
  }
  
  s[sIndex] = '\0';
}

void unescape(char *s, const char *t)
{
  int tIndex = 0;
  int sIndex = 0;
  
  for (tIndex = 0 ; t[tIndex] != '\0' ; tIndex++)
  {
    if (t[tIndex] == '\\' && t[tIndex+1] == 't')
    {
      s[sIndex++] = '\t';
      tIndex++; // Remove second character.
    }
    else if (t[tIndex] == '\\' && t[tIndex+1] == 'n')
    {
      s[sIndex++] = '\n';
      tIndex++; // Remove second character.
    }
    else
    {
      s[sIndex++] = t[tIndex];
    }
  }
  
  s[sIndex] = '\0';
}

#define MAXLINE 1000

main()
{
  char s[MAXLINE * 2], t[MAXLINE];
  
  printf("ENTER LINE TO CONVERT ESCAPE CHARACTERS TO PRINTABLE ONES: ");
  _getline(t, MAXLINE);
  
  escape(s, t);
  
  printf("ORIGINAL: %s\n", t);
  printf("  RESULT: %s\n", s);

  printf("\n\nENTER LINE TO CONVERT PRINTABLE CHARACTERS TO ESCAPE CHARACTERS: ");
  _getline(t, MAXLINE);
  
  unescape(s, t);
  
  printf("ORIGINAL: %s\n", t);
  printf("  RESULT: %s\n", s);
}


/* getline: read a line into s, return length */
int _getline(char s[], int lim)
{
  int c, i;

  for (i = 0; (i < lim-1) && ((c = getchar()) != EOF) ; ++i)
  {
    s[i] = c;
  }

  s[i] = '\0';
  return i;
}