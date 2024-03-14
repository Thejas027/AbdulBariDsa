#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *lchild;
  int data;
  struct Node *rchild;
};

struct Queue
{
  int size;
  int front;
  int rear;
  struct Node **Q;
};

void Qcreate(struct Queue *q, int size)
{
  q->size = size;
  q->front = q->rear = 0;
  q->Q = (struct Node **)malloc(sizeof(struct Node *) * q->size);
}

void enqueue(struct Queue *q, struct Node *x)
{
  if (q->rear == q->front == -1)
    printf("Queue is full\n");
  else
  {
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
  }
}

struct Node *dequeue(struct Queue *q)
{

  struct Node *x = NULL;
  if (q->front == q->rear)
  {
    printf("Queue is empty\n");
  }
  else
  {
    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front];
  }
  return x;
}

int isEmpty(struct Queue q)
{
  return q.front == q.rear;
}

struct Node *root = NULL;

void Tcreate()
{
  struct Node *p, *t;
  int x;
  struct Queue q;
  Qcreate(&q, 100);

  printf("Enter root value : ");
  scanf("%d", &x);
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = x;
  root->lchild = root->rchild = NULL;
  enqueue(&q, root);

  while (!isEmpty(q))
  {
    p = dequeue(&q);
    printf("Enter left child value of %d : ", p->data);
    scanf("%d", &x);
    if (x != -1)
    {
      t = (struct Node *)malloc(sizeof(struct Node));
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      enqueue(&q, t);
    }

    printf("Enter right child val of %d : ", p->data);
    scanf("%d", &x);
    if (x != -1)
    {
      t = (struct Node *)malloc(sizeof(struct Node));
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      enqueue(&q, t);
    }
  }
}

void preOrder(struct Node *p)
{

  if (p)
  {
    printf("%d ", p->data);
    preOrder(p->lchild);
    preOrder(p->rchild);
  }
}

void postOrder(struct Node *p)
{

  if (p)
  {
    postOrder(p->lchild);
    postOrder(p->rchild);
    printf("%d ", p->data);
  }
}

void inOrder(struct Node *p)
{

  if (p)
  {
    inOrder(p->lchild);
    printf("%d ", p->data);
    inOrder(p->rchild);
  }
}



int main()
{
  Tcreate();
  printf("\nPRE ORDER travesal of a tree\n");
  preOrder(root);
  printf("\nPOST ORDER travesal of a tree\n");
  postOrder(root);
  printf("\nINORDER travesal of a tree\n");
  inOrder(root);
  return 0;
}

