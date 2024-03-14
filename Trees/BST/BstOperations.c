// progam to create a BINARAY TREE  

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *lchild;
  int data;
  struct Node *rchild;
} *root = NULL;

void Insert(int key)
{
  struct Node *newnode = root;
  struct Node *prev, *temp;

  if (root == NULL)
  {
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = key;
    temp->lchild = temp->rchild = NULL;
    root = temp;
    return;
  }
  while (newnode != NULL)
  {
    prev = newnode;
    if (key < newnode->data)
      newnode = newnode->lchild;

    else if (key > newnode->data)
      newnode = newnode->rchild;

    else
      return;
  }
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = key;
  temp->lchild = temp->rchild = NULL;
  if (key < prev->data)
    prev->lchild = temp;
  else
    prev->rchild = temp;
}

void Inorder(struct Node *temp)
{
  if (temp != NULL)
  {
    Inorder(temp->lchild);
    printf("%d ", temp->data);
    Inorder(temp->rchild);
  }
}

struct Node *Search(int key)
{
  struct Node *temp = root;
  while (temp != NULL)
  {
    if (key == temp->data)
      return temp;
    else if (key < temp->data)
      temp = temp->lchild;
    else
      temp = temp->rchild;
  }
  return NULL;
}

int main()
{
  struct Node *TEMP;
  Insert(10);
  Insert(5);
  Insert(20);
  Insert(8);
  Insert(30);

  Inorder(root);
  printf("\n");

  TEMP = Search(10);
  if (TEMP != NULL)
    printf("element %d found  \n", TEMP->data);
  else
    printf("not found\n");
  return 0;
}