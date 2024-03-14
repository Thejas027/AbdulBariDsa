#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *prev;
  int data;
  struct Node *next;
} *first = NULL;

void Create(int A[], int n)
{
  struct Node *t, *last;
  int i;

  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = A[0];
  first->prev = first->next = NULL;
  last = first;

  for (int i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = last->next;
    t->prev = last;
    last->next = t;
    last = t;
  }
}

void display(struct Node *p)
{
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
}

int length(struct Node *p)
{
  int l = 0;
  while (p)
  {
    l++;
    p = p->next;
  }
  return l;
}

// // fnx to insert before first

// void insertAtFirst(struct Node *p, int x)
// {
//   struct Node *t;
//   t = (struct Node *)malloc(sizeof(struct Node));
//   t->data = x;
//   t->prev = NULL;
//   t->next = first;
//   first->prev = t;
//   first = t;
// }

// // fnx to insert at any pos
// void insertAtPos(struct Node *p, int x, int pos)
// {
//   struct Node *t;
//   t = (struct Node *)malloc(sizeof(struct Node));
//   t->data = x;
//   for (int i = 0; i < pos - 1; i++)
//   {
//     p = p->next;
//   }
//   t->next = p->next;
//   t->prev = p;
//   if (p->next)
//   {
//     p->next->prev = t;
//   }
//   p->next = t;
// }

// singe fnx to insert at doubly linked list

void Insert(struct Node *p, int pos, int x)
{

  if (pos < 0 || pos > length(p))
  {
    return;
  }
  struct Node *t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;

  if (pos == 0)
  {
    t->next = first;
    t->prev = NULL;
    if (first)
    {
      first->prev = t;
    }
    first = t;
  }
  else
  {
    for (int i = 0; i < pos - 1 && p; i++)
    {
      p = p->next;
    }

    if (!p)
    {
      // Handle the case when p becomes NULL (end of the list)
      // You might want to add an error message or handle it according to your requirements.
      return;
    }

    t->next = p->next;
    t->prev = p;

    if (p->next)
    {
      p->next->prev = t;
    }

    p->next = t;
  }
}

void insert(struct Node *p, int pos, int x)
{

  if (pos < 0 || pos > length(p))
    return;

  if (pos == 0)
  {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = first;
    t->prev = NULL;
    if (first)
      first->prev = t;
    first = t;
  }
  else
  {
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    for (int i = 0; i < pos - 1; i++)
    {
      t->next = p->next;
      t->prev = t;
      if (p->next)
        p->next->prev = t;
      p->next = t;
    }
  }
}

// fnx to delete the node
void delete(struct Node *p, int pos)
{
  if (pos < 0 || pos >= length(p))
    return;

  if (pos == 0)
  {
    struct Node *temp = first;
    first = first->next;
    free(temp);
    if (first)
      first->prev = NULL;
  }
  else
  {
    p = first;
    for (int i = 0; i < pos; i++)
    {
      p = p->next;
    }

    if (p->prev)
      p->prev->next = p->next;

    if (p->next)
      p->next->prev = p->prev;

    free(p);
  }
}

// fnx to reverse the doubly linkedlist

void Reverse(struct Node *p)
{
  struct Node *temp;
  while (p != NULL)
  {
    temp = p->next;
    p->next = p->prev;
    p->prev = temp;
    p = p->prev;
    if (p != NULL && p->next == NULL)
    {
      first = p;
    }
  }
}

struct Node *Reverse2(struct Node *head)
{
  struct Node *temp;
  struct Node *p = head;

  while (p != NULL)
  {
    temp = p->next;
    p->next = p->prev;
    p->prev = temp;

    if (temp == NULL)
      head = p;

    p = temp;
  }

  return head;
}

int main()
{
  int A[] = {1, 2, 3, 4, 5};
  Create(A, 5);
  first = Reverse2(first);
  display(first);
  return 0;
}
