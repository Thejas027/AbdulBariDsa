#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **H, int x)
{
    struct Node *t, *q = NULL, *p = *H;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

struct Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int Hash(int key)
{
    return key % 10;
}

void insert(struct Node *H[], int key)
{
    int index = Hash(key);
    SortedInsert(&H[index], key);
}

int main()
{
    struct Node *HT[10];
    struct Node *temp;
    int i;

    for (i = 0; i < 10; i++)
        HT[i] = NULL;
    insert(HT, 12);
    insert(HT, 42);
    insert(HT, 32);
    insert(HT, 52);
    temp = Search(HT[Hash(32)], 32);

    if (temp)
    {
        printf("%d found\n", temp->data);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}
