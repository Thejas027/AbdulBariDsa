#include <stdio.h>
#include <stdlib.h>

struct Node
{
  char data;
  struct Node *next;
} *top = NULL;

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

void push(char x)
{

  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));
  if (t == NULL)
  {
    printf("Stack is full\n");
  }
  t->data = x;
  t->next = top;
  top = t;
}

char pop()
{
  int x = -1;
  struct Node *p = top;
  if (top == NULL)
  {
    printf("Stack is empty\n");
  }
  top = top->next;
  x = p->data;
  free(p);
  return x;
}

int isMatched(char a, char b)
{
  if (a == '{' && b == '}')
    return 1;
  if (a == '(' && b == ')')
    return 1;
  if (a == '[' && b == ']')
    return 1;

  return 0;
}

int isBalance(char *exp)
{
  int i;
  char poppedchar;
  for (i = 0; exp[i] != '\0'; i++)
  {
    if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
      push(exp[i]);
    else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
    {
  if (top == NULL)
        return 0;
      poppedchar = pop();
      if (!isMatched(poppedchar, exp[i]))
        return 0;
    }
  }

  if (top == NULL)
    return 1;
  else
    return 0;
}

int main()
{

  char *exp = "{({})}";
  if (isBalance(exp))
  {
    printf("parenthesies are matched\n");
  }
  else
  {
    printf("parenthesies are not matched\n");
  }
  return 0;
}