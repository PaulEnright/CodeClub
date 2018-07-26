#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE (100)

int R_Stack[MAX_STACK_SIZE];
int R_StackCount = 0;

int push(int n)
{
  if (R_StackCount < MAX_STACK_SIZE - 1)
  {
    R_Stack[R_StackCount++] = n;
    return 0;
  }
  
  printf("ERROR: Stack Overflow\n");
  return -1;
}

int pop(void)
{
  if (R_StackCount > 0)
  {
    return R_Stack[--R_StackCount];
  }
  
  printf("ERROR: Stack Underflow\n");
  return 0;
}

int isOperator(char *s)
{
  if ((strlen(s) == 1) && ((s[0] == '+') || (s[0] == '-') || (s[0] == '/') || (s[0] == 'x') || (s[0] == '%')))
  {
    return 1;
  }
  return 0;
}

int isInteger(char *s)
{
  if (*s == '-')
  {
    s++;
  }
  
  if (*s == '\0')
  {
    return 0;
  }
  
  while (*s != '\0')
  {
    if (!isdigit(*s)) return 0;
    s++;
  }
  
  return 1;
}

main(int argc, char *argv[])
{
  int i = 0;
  
  if (argc == 1)
  {
    printf("usage: a.out <postfix arguments separated by spaces>\n");
    exit(1);
  }
  
  for (i = 1 ; i < argc ; i++)
  {
    if (isInteger(argv[i]))
    {
      if (push(atoi(argv[i])) < 0)
      {
        exit(1);
      }
    }
    else if (isOperator(argv[i]))
    {
      if (R_StackCount < 2)
      {
        printf("ERROR: Insufficient operands\n");
        exit(1);
      }
      else
      {
        int arg2 = R_Stack[--R_StackCount];
        int arg1 = R_Stack[--R_StackCount];
        
        switch(argv[i][0])
        {
          case '+':
            push(arg1 + arg2);
            break;
            
          case '-':
            push(arg1 - arg2);
            break;
            
          case 'x':
            push(arg1 * arg2);
            break;
            
          case '/':
            if (arg2 == 0)
            {
              printf("ERROR: Divide By Zero\n");
              exit(1);
            }
            push(arg1 / arg2);
            break;
            
          case '%':
            if (arg2 == 0)
            {
              printf("ERROR: Divide By Zero\n");
              exit(1);
            }
            push(arg1 % arg2);
            break;
        }
      }
    }
    else
    {
      printf("ERROR: Unrecognized operator %s\n", argv[i]);
      exit(1);
    }
  }
  
  // Result is on the stack.
  if (R_StackCount == 1)
  {
    printf("Result is %d\n", R_Stack[0]);
  }
  else
  {
    printf("ERROR: Insufficient operators\n");
  }
}