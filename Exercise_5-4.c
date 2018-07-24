#include <stdio.h>
#include <string.h>

int strend(char *s, char *t)
{
  if (!s || !t) return 0;
  
  if ((strlen(t) > strlen(s)) || (strlen(t) == 0)) return 0;
  
  return strcmp(t, &s[strlen(s) - strlen(t)]) == 0;
}

#define MAXLINE 1000

main()
{
  int result = 0;
  char s[MAXLINE];
  char t[MAXLINE];
  
  printf("Enter string: ");
  _getline(s, MAXLINE);
  
  printf("Enter end: ");
  _getline(t, MAXLINE);
  
  result = strend(s, t);
  
  printf("<%s> %s the end of <%s>\n", t, (result ? "IS" : "is NOT"), s);
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