#include <stdio.h>
#include <stdlib.h>

struct Queue
{
  int size;
  int front;
  int rear;
  int *Q;
};

void create(struct Queue *q, int size)
{
  q->size = size;
  q->front = q->rear = -1;
  q->Q = (int *)malloc(sizeof(int) * q->size);
}

void display(struct Queue q)
{
  for (int i = q.front + 1; i <= q.rear; i++)
  {
    printf("%d ", q.Q[i]);
  }
  printf("\n");
}

void Enqueue(struct Queue *q, int x)
{
  if (q->rear == q->size - 1)
  {
    printf("Queue is Full\n");
  }
  else
  {
    q->rear++;
    q->Q[q->rear] = x;
  }
}

int Dequeue(struct Queue *q)
{

  int x = -1;
  if (q->front == q->rear)
  {
    printf("Queue is empty\n");
  }
  else
  {

    q->front++;
    x = q->Q[q->front];
  }
  return x;
}

int main()
{
  struct Queue q;
  create(&q, 5);
  Enqueue(&q, 10);
  Enqueue(&q, 20);
  Enqueue(&q, 30);
  Enqueue(&q, 40);
  Enqueue(&q, 50);
  display(q);
  printf("Dequeued Element : %d \n", Dequeue(&q));
  printf("Dequeued Element : %d \n", Dequeue(&q));
  printf("Elements after Dequeue : ");
  display(q);
  return 0;
}