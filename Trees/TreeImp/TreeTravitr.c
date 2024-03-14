#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *lchild;
  int data;
  struct Node *rchild;
};

struct Node *root = NULL;

struct Stack
{
  int size;
  int top;
  struct Node **S;
};

void Screate(struct Stack *st, int size)
{
  st->size = size;
  st->top = -1;
  st->S = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *val)
{
  if (st->top == st->size - 1)
  {
    printf("Stack is full\n");
    return;
  }
  st->top++;
  st->S[st->top] = val;
}

struct Node *pop(struct Stack *st)
{
  if (st->top == -1)
  {
    printf("Stack is empty\n");
  }
  struct Node *val = NULL;
  val = st->S[st->top];
  st->top--;
}

int SisEmpty(struct Stack st)
{
  if (st.top == -1)
    return 0;
  return 1;
}

int SisFull(struct Stack st)
{
  return st.top == st.size - 1;
}

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

void ItrpreOrder(struct Node *p)
{
  struct Stack stk;
  Screate(&stk, 100);

  while (p || !SisEmpty(stk))
  {
    if (p)
    {
      printf("%d ", p->data);
      push(&stk, p);
      p = p->lchild;
    }
    else
    {
      p = pop(&stk);
      p = p->rchild;
    }
  }
}

void ItrInOrder(struct Node *p)
{
  struct Stack stk;
  Screate(&stk, 100);

  while (p || !SisEmpty(stk))
  {
    if (p)
    {
      push(&stk, p);
      p = p->lchild;
    }
    else
    {
      p = pop(&stk);
      printf("%d ", p->data);
      p = p->rchild;
    }
  }
}


void ItrLevelOrder(struct Node *root)
{
  struct Queue q;
  Qcreate(&q, 100);
  printf("%d ", root->data);
  enqueue(&q, root);

  while (!isEmpty(q))
  {
    root = dequeue(&q);
    if (root->lchild)
    {
      printf("%d ", root->lchild->data);
      enqueue(&q, root->lchild);
    }
    if (root->rchild)
    {
      printf("%d ", root->rchild->data);
      enqueue(&q, root->rchild);
    }
  }
}

int main()
{

  Tcreate();
  printf("Pre-order\n");
  ItrpreOrder(root);
  printf("\nInorder \n");
  ItrInOrder(root);
  printf("\nLevel Order\n");
  ItrLevelOrder(root);
  return 0;
}