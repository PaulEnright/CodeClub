#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

#define NUMBER '0'

/* getop:  get next character or numeric operand */
int getop(char s[])
{
  static int leftoverChar = EOF;
  int i, c;
  
  if (leftoverChar != EOF && leftoverChar != ' ' && leftoverChar != '\t')
  {
    s[0] = leftoverChar;
  }
  else
  {
    while ((s[0] = c = getchar()) == ' ' || c == '\t');
  }
  leftoverChar = EOF;
  
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c; /* not a number */
  i = 0;
  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = getchar()));
  
  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getchar()));
      
  s[i] = '\0';
  if (c != EOF)
  {
    leftoverChar = c;
  }
  return NUMBER;
}


#define MAXLINE 1000

main()
{
  char s[50];
  int result;
  
  do
  {
    result = getop(s);
    if (s[0] != '\0' && s[0] != '\n')
    {
      if (result == '0')
      {
        printf("NUMBER: %s\n", s);
      }
      else
      {
        printf("OPERATOR: %s\n", s);
      }
    }
  } while (s[0] != '\0');
}
