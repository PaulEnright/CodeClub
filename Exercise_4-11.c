#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

#define NUMBER '0'

/* getop:  get next character or numeric operand */
int getop(char s[])
{
  int i, c;
  
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c; /* not a number */
  i = 0;
  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = getch()));
  
  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()));
      
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}


#define MAXLINE 1000

char buf[MAXLINE];
int bufp = 0;

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if (bufp >= MAXLINE)
  {
    printf("ungetch: too many characters\n");
  }
  else
  {
    buf[bufp++] = c;
  }
}

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
