#include <iostream>
#include <stdexcept>

class Node
{
public:
  int data;
  Node *next;
};

class Stack
{
private:
  Node *top;

public:
  Stack() : top(nullptr) {}

  void push(int x)
  {
    Node *t = new Node;
    if (t == nullptr)
    {
      throw std::runtime_error("Stack is Full");
    }
    t->data = x;
    t->next = top;
    top = t;
  }

  int pop()
  {
    if (isEmpty())
    {
      throw std::runtime_error("Stack is Empty");
    }

    int x = top->data;
    Node *t = top;
    top = top->next;
    delete t;
    return x;
  }

  bool isEmpty() const
  {
    return top == nullptr;
  }

  void display() const
  {
    Node *p = top;
    std::cout << "Elements are : ";
    while (p != nullptr)
    {
      std::cout << p->data << " ";
      p = p->next;
    }
    std::cout << std::endl;
  }
};

int main()
{
  Stack st;
  try
  {
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.display();
    std::cout << std::endl;
    std::cout << "Deleted element : " << st.pop() << std::endl;
    st.display();
  }
  catch (const std::exception &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}