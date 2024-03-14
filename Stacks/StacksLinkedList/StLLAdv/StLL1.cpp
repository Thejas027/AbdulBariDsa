#include <iostream>
#include <stdexcept>
#include <memory>

class Node
{
public:
  int data;
  std::unique_ptr<Node> next;
};

class Stack
{
private:
  std::unique_ptr<Node> top;

public:
  Stack() : top(nullptr) {}

  void push(int x)
  {
    auto t = std::make_unique<Node>();
    if (!t)
    {
      throw std::runtime_error("Stack is Full");
    }
    t->data = x;
    t->next = std::move(top);
    top = std::move(t);
  }

  int pop()
  {
    if (isEmpty())
    {
      throw std::runtime_error("Stack is Empty");
    }

    int x = top->data;
    top = std::move(top->next);
    return x;
  }

  bool isEmpty() const
  {
    return top == nullptr;
  }

  void display() const
  {
    const Node *p = top.get();
    std::cout << "Elements are : ";
    while (p != nullptr)
    {
      std::cout << p->data << " ";
      p = p->next.get();
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
