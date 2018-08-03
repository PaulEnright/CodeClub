// Chapter 6 HW - very rudimentary linked list with add, delete, and print.
// - Use structures to implement a very rudimentary singly linked list for integers with an ability to add, delete, and print
// - UI can be like the following
// - a 5 to add 5 to the list
// - d 5 to delete 5 from the list (don’t worry about error reporting and only need to delete one occurrence)
// - p to print the list

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE
{
  int data;
  struct NODE *next;
} NODE;

#define MAXLINE 1000

void printList(NODE* list)
{
  printf("\nLIST: ");

  while (list != NULL)
  {
    printf("%d ", list->data);
    list = list->next;
  }
  printf("\n");
}

void insertNode(NODE** list, int data)
{
  NODE *newNode = malloc(sizeof(NODE));
  
  if (newNode == NULL)
  {
    printf("ERROR: OUT OF MEMORY\n");
  }
  
  newNode->data = data;
  newNode->next = *list;
  *list = newNode;
}

void deleteNode(NODE** list, int data)
{
  NODE *prevNode;
  NODE *currNode;
  
  prevNode = NULL;
  currNode = *list;
  for (prevNode = NULL, currNode = *list ; currNode != NULL ; currNode = currNode->next)
  {
    if (currNode->data == data)
    {
      // Node found. Remove it. Head of list is a special case.
      if (prevNode == NULL)
      {
        *list = currNode->next;
      }
      else
      {
        prevNode->next = currNode->next;
      }
      
      free(currNode);
      return;
    }
    
    prevNode = currNode;
  }
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

int getInteger(char *s, int *num)
{
  // Skip over whitespace.Skip
  while (*s == ' ' || *s == '\t')
  {
    s++;
  }
  
  if (isInteger(s))
  {
    *num = atoi(s);
    return 1;
  }
  
  return 0;
}

main()
{
  char s[MAXLINE];
  NODE *head = NULL;
  int num;

  while (1)
  {
    _getline(s, MAXLINE);
    
    switch(s[0])
    {
      case 'p':
        printList(head);
        break;
        
      case 'a':
        if (getInteger(&s[1], &num))
        {
          insertNode(&head, num);
        }
        break;
        
      case 'd':
        if (getInteger(&s[1], &num))
        {
          deleteNode(&head, num);
        }
        break;
        
      default:
        printf("ERROR: Invalid command\n");
        break;
    }
  }
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