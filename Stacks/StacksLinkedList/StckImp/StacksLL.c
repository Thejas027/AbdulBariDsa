#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
} *top = NULL;

void display()
{
  struct Node *p;
  p = top;
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

void push(int x)
{
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));
  if (t == NULL)
  {
    printf("Stack overflow: Unable to push %d\n", x);
    return;
  }
  else
  {
    t->data = x;
    t->next = top;
    top = t;
  }
}

int pop()
{
  struct Node *t;
  int x = -1;
  if (top == NULL)
  {
    printf("Stack underflow: Unable to pop\n");
  }
  else
  {
    t = top;
    top = top->next;
    x = t->data;
    free(t);
  }
  return x;
}

int peek(int pos)
{
  struct Node *t = top;
  for (int i = 0; (i < pos - 1 && t != NULL); i++)
  {
    t = t->next;
  }
  if (t != NULL)
  {
    return t->data;
  }
  else
  {
    return -1;
  }
}

int isEmpty()
{
  return top == NULL;
}

int main()
{
  push(10);
  push(20);
  push(30);
  push(40);

  display();

  if (!isEmpty())
  {
    printf("Popped element: %d\n", pop());
  }
  display();
  printf("peek Element At req Position : %d ", peek(1));

  return 0;
}
