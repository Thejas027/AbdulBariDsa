#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
  int i;
  struct Node *t, *last;

  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}
int midEle(struct Node *h)
{
  struct Node *p = h;
  struct Node *q = h;
  struct Node *prev = NULL;

  while (q != NULL)
  {
    q = q->next;
    if (q != NULL)
    {
      q = q->next;
      prev = p;
      p = p->next;
    }
  }

  if (prev != NULL)
  {
    return prev->next->data;
  }
  else if (p != NULL)
  {
    return p->data;
  }
  else
  {
    return -1;
  }
}

int main()
{

  int A[] = {1, 2, 3, 4, 5};
  create(A, 5);
  printf("%d", midEle(first));
}