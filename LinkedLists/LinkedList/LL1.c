#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

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

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;

    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
}

// Recursive display gives in normal order
void Display2(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        Display2(p->next);
    }
}

// Recursive displya fnx gives values in reverse reverse
void Display3(struct Node *p)
{
    if (p != NULL)
    {
        Display3(p->next);
        printf("%d ", p->data);
    }
}

int Count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}
// Recursive fnx to count the elements
int Rcount(struct Node *p)
{
    if (p == 0)
    {
        return 0;
    }
    else
    {
        return Rcount(p->next) + 1;
    }
}

int add(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}
// Recursive fnx to find the sum of a ll
int Radd(struct Node *p)
{
    if (p == 0)
    {
        return 0;
    }
    return Radd(p->next) + p->data;
}

int max(struct Node *p)
{
    int m = -1;
    while (p)
    {
        if (p->data > m)
        {
            m = p->data;
            p = p->next;
        }
    }
    return m;
}

// Recursive fnx to find the max element in ll
int Rmax(struct Node *p)
{
    int x = -1;
    if (p == 0)
    {
        return -1;
    }
    x = Rmax(p->next);
    return x > p->data ? x : p->data;
}

struct Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)

            return (p);
        p = p->next;
    }
    return NULL;
}

// Recursive fnx to search the element in ll
struct Node *Rsearch(struct Node *p, int key)
{
    if (p == 0)
    {
        return NULL;
    }
    if (key == p->data)
    {
        return (p);
    }
    return Rsearch(p->next, key);
}

// improvement in a searching in ll by move to head method

struct Node *Isearch(struct Node *p, int key)
{
    struct Node *q;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
}

// fnx to insert at first in LL
void InsertAtfirst(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = first;
    first = t;
}

// INSERTING AN ELEMENT IN A LINKED LIST AT ANY POSITION
void InsertAtPos(int x, int pos)
{
    struct Node *p, *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    p = first;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    t->next = p->next;
    p->next = t;
}

// insertion  at last

void inserAtLast(int val)
{

    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = val;
    t->next = NULL;

    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

// Insert in Linked fnx
void InsertInLL(struct Node *p, int x, int pos)
{
    struct Node *t;
    if (pos < 0 || pos > Count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (pos == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

// insertion in sorted linked list
void sortedInsertion(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

// delete at first

int deleteAtFirst(struct Node *p)
{
    int x = -1;
    p = first;
    first = first->next;
    x = p->data;
    free(p);
    return x;
}

// delete at last
int deleteAtLast(struct Node *first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return -1;
    }

    struct Node *p = first;
    struct Node *last = NULL;

    if (p->next == NULL)
    {
        int x = p->data;
        free(p);
        return x;
    }

    while (p->next != NULL)
    {
        last = p;
        p = p->next;
    }

    int x = p->data;
    free(p);
    last->next = NULL;
    return x;
}

// deletion of a node at any position including deletion at first

int delete(struct Node *p, int pos)
{
    struct Node *q = NULL;
    int x = -1;

    if (pos < 0 || pos > Count(p))
    {
        return -1;
    }
    else if (pos == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

// fnx to check weather the linked list is sorted or not

int isSorted(struct Node *p)
{
    int x = -1;

    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

// fnx to remove the duplicates

void RemoveDuplicates(struct Node *p)
{
    struct Node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

// reversing the linked list by swaping the elements

void ReverseLL1(struct Node *p)
{
    int *A;
    int i = 0;
    struct Node *q = p;

    A = (int *)malloc(sizeof(int) * Count(p));

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

// reversing a linked list BY SLIDING POINTER METHOD

void ReverseLL2(struct Node *p)
{
    struct Node *q = NULL;
    struct Node *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// fnx to rverse the ll by recursion

void ReverseLL3(struct Node *q, struct Node *p)
{
    if (p)
    {
        ReverseLL3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

// concatation of 2 strings

void ConcatLL(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next != NULL)
    {
        p = p->next;
        p->next = q;
    }
}

// merging 2 linked lists

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

// fnx to check weather the linked list is a loop or linear

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : q;
    } while (p && q && p != NULL);
    if (p == q)
        return 1;
    else
        return 0;
}

int main()
{
    struct Node *temp;
    int A[] = {1, 20, 30, 40, 50};
    // create(A, 5);
    inserAtLast(12);
    // InsertAtfirst(123);
    // printf("deleted First element : %d \n", deleteAtLast(first));

    // Display(first);
    printf("deleted First element : %d \n", deleteAtLast(first));

    // printf("Elements are : ");
    // Display(first);
    // printf("Length is %d \n", Count(first));
    // printf("Length of ll using rec fnx : %d \n", Rcount(first));
    // printf("Sum of LL : %d\n", add(first));
    // printf("Sum of LL using recurive fnx : %d\n", add(first));
    // printf("Max element in ll: %d \n", max(first));
    // printf("Max element in ll by rec fnx: %d \n", max(first));

    // temp = Isearch(first, 15);
    // if (temp)
    // {
    //   printf("key found \n");
    // }
    // else
    // {
    //   printf("not found");
    // }
    // printf("\n");

    // // InsertAtfirst(123456);
    // // InsertAtfirst(1);
    // // InsertAtfirst(400);
    // // InsertAtfirst(300);
    // // InsertAtfirst(200);
    // // InsertAtfirst(100);
    // // InsertAtPos(6789, 3);
    // InsertInLL(first, 10, 0);
    // inserAtLast(143);

    // sortedInsertion(first, 45);
    // sortedInsertion(first, 1);
    // inserAtLast(11233);

    // delete (first, 3);
    // if(isSorted(first)){
    //   printf("sorted\n");
    // } else {
    //   printf("not sorted\n");
    // }

    // RemoveDuplicates(first);
    //   printf("\n\n");
    // printf("\nLinked list Elements before Reversing\n");
    //   Display(first);
    //   printf("\n\n");
    //   printf("Linked list after Reversing \n");
    //   ReverseLL3(NULL,first);
    //   Display(first);

    //   int B[] = {5,15,25,35};
    //   create2(B, 4);

    // Merge(first,second);
    //   Display(third);

    // // to check weather the linked list is a loop or linear
    // struct Node *t1,*t2;
    // t1=first->next->next;
    // t2=first->next->next->next->next;
    // t2->next=t1;
    // printf("%d\n",isLoop(first));

    return 0;
}
