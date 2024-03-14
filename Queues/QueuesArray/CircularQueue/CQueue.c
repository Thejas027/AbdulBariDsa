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
  q->front = q->rear = 0;
  q->Q = (int *)malloc(sizeof(int) * q->size);
}

void display(struct Queue q)
{
  int i = q.front + 1;
  do
  {
    printf("%d ", q.Q[i]);
    i = (i + 1) % q.size;
  } while (i != (q.rear + 1) % (q.size));
}

void Enqueue(struct Queue *q, int x)
{
  if ((q->rear + 1) % q->size == q->front)
    printf("Queue is full\n");
  else
  {
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
  }
}

int Dequeue(struct Queue *q)
{
  int x = -1;
  if (q->front == q->rear)
    printf("Queue is empty\n");
  else
  {
    q->front = (q->front + 1) % q->size;
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
    Enqueue(&q, 60);

  printf("\n");
  printf("Elements of Queue are : ");
  display(q);
  // printf("\n");
  // printf("Dequeued Element : %d \n", Dequeue(&q));
  // printf("\n");
  // printf("Elements after Dequeue : ");
  // display(q);
  printf("\n");
}