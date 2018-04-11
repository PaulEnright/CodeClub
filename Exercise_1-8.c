#include <stdio.h>

/* count lines in input */
main()
{
  int c, nl, blanks, tabs;
  
  nl = 0;
  blanks = 0;
  tabs = 0;
  
 while ((c = getchar()) != EOF)
 {
   if (c == '\n') ++nl;
   if (c == '\t') ++tabs;
   if (c == ' ') ++blanks;
 }
  printf("\nBlanks: %d\n", blanks);
  printf("Tabs: %d\n", tabs);
  printf("Newlines: %d\n", nl);
}