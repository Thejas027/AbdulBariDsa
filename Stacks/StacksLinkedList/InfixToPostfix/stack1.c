#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  char data;
  struct Node *next;
} *top = NULL;

void push(char x)
{
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));
  if (t == NULL)
  {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  t->data = x;
  t->next = top;
  top = t;
}

char pop()
{
  if (top == NULL)
  {
    printf("stack is empty\n");
    exit(EXIT_FAILURE);
  }

  struct Node *p = top;
  char x = p->data;
  top = top->next;
  free(p);
  return x;
}

int isOperand(char x)
{
  return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

int precedence(char x)
{
  if (x == '+' || x == '-')
    return 1;
  if (x == '*' || x == '/')
    return 2;

  return 0;
}

char *InToPost(char *infix)
{
  int i = 0, j = 0;
  char *postfix;
  int len = strlen(infix);
  postfix = (char *)malloc(sizeof(char) * (len + 1));

  if (postfix == NULL)
  {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  while (infix[i] != '\0')
  {
    if (isOperand(infix[i]))
    {
      postfix[j++] = infix[i++];
    }
    else
    {
      if (top == NULL || precedence(infix[i]) > precedence(top->data))
      {
        push(infix[i++]);
      }
      else
      {
        postfix[j++] = pop();
      }
    }
  }

  while (top != NULL)
  {
    postfix[j++] = pop();
  }

  postfix[j] = '\0';
  return postfix;
}

int main()
{
  char *infix = "a+b*c-d/e";
  push('#');

  char *postfix = InToPost(infix);
  printf("Infix: %s\n", infix);
  printf("Postfix: %s\n", postfix);

  return 0;
}


