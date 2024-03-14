#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *lchild;
  int data;
  int height;
  struct Node *rchild;
} *root = NULL;

// to get the heigth of a tree
int NodeHeight(struct Node *p)
{
  int hl, hr;
  hl = p && p->lchild ? p->lchild->height : 0;
  hr = p && p->rchild ? p->rchild->height : 0;
  return hl > hr ? hl + 1 : hr + 1;
}

// to get the balance factor of a tree
int balanceFactor(struct Node *p)
{
  int hl, hr;
  hl = p && p->lchild ? p->lchild->height : 0;
  hr = p && p->rchild ? p->rchild->height : 0;
  return hl - hr;
}

// fnx for LL Rotation
struct Node *LLRotation(struct Node *p)
{
  struct Node *pl = p->lchild;
  struct Node *plr = pl->rchild;

  pl->rchild = p;
  p->lchild = plr;

  p->height = NodeHeight(p);
  pl->height = NodeHeight(pl);

  if (root == p)
    root = pl;

  return pl;
}

// fnx for RR Rotation
struct Node *RRRotation(struct Node *p)
{
  struct Node *pr = p->rchild;
  struct Node *prl = pr->lchild;

  pr->lchild = p;
  p->rchild = prl;

  p->height = NodeHeight(p);
  pr->height = NodeHeight(pr);

  if (root == p)
    root = pr;

  return pr;
}

// fnx for LR Rotation
struct Node *LRRotation(struct Node *p)
{
  struct Node *pl = p->lchild;
  struct Node *plr = pl->rchild;

  pl->rchild = plr->lchild;
  p->lchild = plr->rchild;

  plr->lchild = pl;
  plr->rchild = p;

  pl->height = NodeHeight(pl);
  p->height = NodeHeight(p);
  plr->height = NodeHeight(plr);

  if (root == p)
    root = plr;

  return plr;
}

// fnx for RL Rotation
struct Node *RLRotation(struct Node *p)
{
  struct Node *pr = p->rchild;
  struct Node *prl = pr->lchild;

  pr->lchild = prl->rchild;
  p->rchild = prl->lchild;
  prl->lchild = p;
  prl->rchild = pr;

  pr->height = NodeHeight(pr);
  p->height = NodeHeight(p);
  prl->height = NodeHeight(prl);

  if (root == p)
    root = prl;
  return prl;
}

// Recursive insertion for AVL tree

struct Node *RInsert(struct Node *p, int key)
{
  struct Node *t = NULL;
  if (p == NULL)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->height = 1; // it can start from zero also
    t->lchild = t->rchild = NULL;
    return t;
  }
  if (key < p->data)
    p->lchild = RInsert(p->lchild, key);
  else if (key > p->data)
    p->rchild = RInsert(p->rchild, key);

  // adjustin the height of a tree after inserting <setting it for rotation>
  p->height = NodeHeight(p);

  if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
    return LLRotation(p);
  else if (balanceFactor(p) == 2 && balanceFactor(p->rchild) == -1)
    return LRRotation(p);
  else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
    return RRRotation(p);
  else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
    return RLRotation(p);

  return p;
}

// inorder travesal of a tree
void inOrder(struct Node *p)
{
  if (p != NULL)
  {
    inOrder(p->lchild);
    printf("%d ", p->data);
    inOrder(p->rchild);
  }
}

int main()
{
  root = RInsert(root, 10);
  root = RInsert(root, 5);
  root = RInsert(root, 20);
  root = RInsert(root, 8);
  printf("\nInorder travesal of a tree\n");
  inOrder(root);
  return 0;
}