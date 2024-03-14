#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
} *Head;

void create(int A[], int n)
{
  int i;
  struct Node *t, *last;
  Head = (struct Node *)malloc(sizeof(struct Node));
  Head->data = A[0];
  Head->next = Head;
  last = Head;

  for (i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = last->next;
    last->next = t;
    last = t;
  }
}

void display(struct Node *h)
{
  do
  {
    printf("%d ", h->data);
    h = h->next;
  } while (h != Head);
  printf("\n");
}

void Rdisplay(struct Node *h)
{
  static int flag = 0;
  if (h != Head || flag == 0)
  {
    flag = 1;
    printf("%d ", h->data);
    Rdisplay(h->next);
  }
  flag = 0;
}

// fnx to find the length of a CL

int Length(struct Node *p)
{
  int len = 0;
  do
  {
    len++;
    p = p->next;
  } while (p != Head);
  return len;
}

void Insert(struct Node *p, int pos, int x)
{
  struct Node *t;
  if (pos < 0 || pos > Length(p))
    return;

  if (pos == 0)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (Head == NULL)
    {
      Head = t;
      Head->next = Head;
    }
    else
    {
      p = Head;
      while (p->next != Head)
      {
        p = p->next;
      }
      p->next = t;
      t->next = Head;
      Head = t;
    }
  }
  else
  {

    for (int i = 0; i < pos - 1; i++)
    {
      p = p->next;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = p->next;
    p->next = t;

    // Update Head if inserting at the end
    if (t->next == Head)
      Head = t;
  }
}

// fnx to delete the node
int Delete(struct Node *p, int pos)
{
  struct Node *q;
  int x = -1;
  if (pos == 1)
  {
    p = Head;
    while (p->next != Head)
    {
      p = p->next;
    }
    x = Head->data;
    if (Head == NULL)
    {
      free(Head);
      Head = NULL;
    }
    else
    {
      p->next = Head->next;
      free(Head);
      Head = p->next;
    }
  }
  else
  {
    p = Head;
    for (int i = 0; i < pos - 2; i++)
    {
      p = p->next;
    }
    q = p->next;
    x = q->data;
    p->next = q->next;
    free(q);
  }
  return x;
}

int main()
{
  int A[] = {1, 2, 3, 4, 5};
  create(A, 5);
  printf("\nBefore Insertion\n");
  Rdisplay(Head);

  Insert(Head, 5, 123);
  printf("\nAfter Insertion\n");
  display(Head);

  printf("\n\n%d", Delete(Head, 1));
  printf("\nAfter Deletion\n");
  display(Head);

  return 0;
}
