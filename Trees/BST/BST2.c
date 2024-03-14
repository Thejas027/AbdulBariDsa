#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

// insertion
void insert(int key)
{
    struct Node *t = root;
    struct Node *p, *r;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (root == NULL)
    {
        root = p;
        return;
    }

    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

// Inorder travesal  of a tree
void inOrder(struct Node *p)
{
    if (p != NULL)
    {
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}
// searching a key
struct Node *search(int key)
{
    struct Node *t = root;
    while (t != NULL)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

// Recursive insertion
struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);
    return p;
}

// to get to know the height of a tree
int Height(struct Node *p)
{
    int x, y;
    if (p == NULL)
        return -1;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

// inorder precessor of teree
struct Node *Inpre(struct Node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;

    return p;
}

// inorder succesor of a tree
struct Node *InSucc(struct Node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;

    return p;
}

// deleting a node tree value
struct Node *delete(struct Node *p, int key)
{
    struct Node *q;
    if (p == NULL)
        return NULL;

    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (key < p->data)
        p->lchild = delete (root->lchild, key);
    else if (key > p->data)
        p->rchild = delete (root->rchild, key);
    else
    {

        if (Height(p->lchild) > Height(p->rchild))
        {
            q = Inpre(p->lchild);
            p->data = q->data;
            p->lchild = delete (p->lchild, q->data);
        }

        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = delete (p->rchild, q->data);
        }
    }
    return p;
}

int main()
{
    struct Node *temp = NULL;
    root = RInsert(root, 10);
    RInsert(root, 5);
    insert(1);
    RInsert(root, 20);
    insert(8);

    printf("\nInorder travesal before deletion\n");
    inOrder(root);

    delete (root, 5);

    printf("\nIn Order Travesal after deletion\n");
    inOrder(root);
    printf("\n");
    temp = search(1);
    if (temp)
        printf("Element found\n");
    else
        printf("Element not found\n");
    return 0;
}