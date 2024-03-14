#include <stdio.h>
#include <stdlib.h>

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
    printf("stack is full\n");

  t->data = x;
  t->next = top;
  top = t;
}

char pop()
{
  struct Node *t = top;
  char x = -1;
  if (top == NULL)
    printf("stack is empty\n");

  top = top->next;
  x = t->data;
  free(t);

  return x;
}

void display()
{
  struct Node *p = top;
  while (p != NULL)
  {
    printf("%c ", p->data);
    p = p->next;
  }
  printf("\n");
}

int isBalance(char *exp)
{
  int i;
  for (i = 0; exp[i] != '\0'; i++)
  {
    if (exp[i] == '(' )
      push(exp[i]);

    else if (exp[i] == ')')
    {
      if (top == NULL)
        return -1;
      pop();
    }
  }
  if (top == NULL)
    return 1;
  else
    return 0;
}

int main()
{
  char *exp = "((a+c)*(a-q))}";
  if (isBalance(exp))
  {
    printf("Paraenthesies are balanced (matched)\n");
  }
  else
  {
    printf("Paraenthesies are not matched");
  }
  return 0;
}