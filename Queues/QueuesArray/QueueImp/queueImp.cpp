#include <iostream>
using namespace std;

class Queue
{
private:
  int front;
  int rear;
  int size;
  int *Q;

public:
  Queue()
  {
    front = rear = -1;
    size = 10;
    Q = new int[size];
  }
  Queue(int size)
  {
    front = rear = -1;
    this->size = 10;
    Q = new int[this->size];
  }
  void Enqueue(int x);
  int Dequeue();
  void display();
};

void Queue ::Enqueue(int x)
{
  if (rear == size - 1)
  {
    cout << "Queue is full" << endl;
  }
  rear++;
  Q[rear] = x;
}

int Queue ::Dequeue()
{
  int x = -1;
  if (front == rear)
  {
    cout << "Queue is Empty" << endl;
  }
  x = Q[front + 1];
  front++;

  return x;
}

void Queue ::display()
{
  int i;
  for (i = front + 1; i <= rear; i++)
  {
    cout << " " << Q[i];
  }
  cout << endl;
}

int main()
{

  Queue q(5);
  q.Enqueue(1);
  q.Enqueue(2);
  q.Enqueue(3);
  q.Enqueue(4);
  q.Enqueue(5);
  cout << "Queue Elements :";
  q.display();
  cout << endl;
  cout << "The Dequed Element : " << q.Dequeue() << endl
       << endl;
  cout << "Elements in Queue after Dequeue: ";
  q.display();
  return 0;
}