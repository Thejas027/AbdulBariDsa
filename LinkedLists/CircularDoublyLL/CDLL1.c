#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = first;
    last = first;

    for (int i = 1; i < n; i++)
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
    } while (h != first);
    printf("\n");
}

void Insert(struct Node *p, int pos, int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (pos == 0)
    {
        t->next = first;
        t->prev = first->prev;
        first->prev = t;
        first->prev->next = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}
int main()
{

    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    Insert(first, 1, 222);

    display(first);
    return 0;
}