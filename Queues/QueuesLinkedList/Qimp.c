#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
} *front = NULL, *rear = NULL;

void Enqueu(int x)
{
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));
  if (t == NULL)
  {
    printf("Queue is Full\n");
  }
  else
  {
    t->data = x;
    t->next = NULL;
    if (front == NULL)
      front = rear = t;
    else
    {
      rear->next = t;
      rear = t;
    }
  }
}

int Dequeue()
{
  int x = -1;
  struct Node *t;
  if (front == NULL)
  {
    printf("Queue is Empty\n");
  }
  else
  {
    x = front->data;
    t = front;
    front = front->next;
    free(t);
  }
  return x;
}

void display()
{
  struct Node *p = front;
  while (p != NULL)
  {
    printf("%d ", p->data);
    p=p->next;
  }
  printf("\n");
}

int main(){

Enqueu(10);
Enqueu(20);
Enqueu(30);
Enqueu(40);
Enqueu(50);
printf("Queue Elements : ");
display();

printf("\n");

printf("Deleted Element from Queue : %d",Dequeue());
printf("\n\n");
printf("Queue elements after dequeued : ");
display();
  return 0;
}