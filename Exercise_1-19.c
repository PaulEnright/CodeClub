#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
  int len;                  // current line length
  char line[MAXLINE];       // current input line

  while ((len = _getline(line, MAXLINE)) > 0)
  {
    int front, back;
    char temp;

    for (front = 0, back = len - 1 ; front < back ; front++, back--)
    {
      temp = line[front];
      line[front] = line[back];
      line[back] = temp;
    }
    printf("Reversed string: %s\n", line);
  }
  return 0;
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}