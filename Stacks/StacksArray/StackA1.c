#include <stdio.h>
#include <stdlib.h>

struct Stack
{
  int size;
  int top;
  int *S;
};

void create(struct Stack *st)
{
  printf("Enter the size of an array\n");
  scanf("%d", &st->size);
  st->top = -1;
  st->S = (int *)malloc(st->size * sizeof(int));
}

void display(struct Stack st)
{
  int i;
  printf("STACK ELEMENTS ARE\n");
  for (i = st.top; i >= 0; i--)
  {
    printf("%d\n", st.S[i]);
  }
  printf("\n");
}

// push operation

void push(struct Stack *st, int x)
{
  if (st->top == st->size)
  {
    printf("stack overflow\n");
  }
  else
  {
    st->top++;
    st->S[st->top] = x;
  }
}

// pop operation

int pop(struct Stack *st)
{
  int x = -1;
  if (st->top == -1)
    printf("stack underflow\n");
  else
  {
    x = st->S[st->top];
    st->top--;
  }
  return x;
}

// peek operation

int peek(struct Stack *st, int pos)
{
  int x = -1;
  if (st->top - pos + 1 < 0)
  {
    printf("invalid position \n");
    return -1;
  }
  else

    x = st->S[st->top - pos + 1];

  return x;
}

// fnx to check weather the stack is empty or not

int isEmpty(struct Stack st)
{
  if (st.top == -1)
    return 1;
  return 0;
}

// fnx to check weather the stack is full or not

int isFull(struct Stack st)
{
  if (st.top == st.size - 1)
    return 1;
  return 0;
}

// fnx to remove the top most element

int stackTop(struct Stack st)
{
  if (!isEmpty)
    return st.S[st.top];
  return -1;
}

int main()
{

  struct Stack st;
  create(&st);
  push(&st, 1);
  push(&st, 10);
  push(&st, 20);
  push(&st, 30);
  push(&st, 40);
  printf("\n");
  display(st);
  printf("poped element is : %d", pop(&st));
  printf("\n");
  printf("\nElements in stack after poped from stack\n");
  display(st);
  printf("Element at pos : %d", peek(&st, 1));
  return 0;
}