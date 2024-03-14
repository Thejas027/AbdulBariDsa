// #include<stdio.h>
// #include<stdlib.h>

// struct Array{
//   int *A;
//   int size;
//   int lenght;
// };

// void Display(struct Array arr){
//   int i;
//   printf("\nElements are\n");
//   for(i=0; i<arr.lenght;i++){
//     printf("%d ",arr.A[i]);
//   }
// }

// int main(){

// // basic intialization
// struct Array arr;
// int n,i;
// printf("Enter the size of an Array: ");
// scanf("%d",&arr.size);       // taking an input of an desired size of an array

// arr.A = (int *) malloc (arr.size*sizeof(int));  // dynamically allocating the memeory of an array

// arr.lenght = 0; // intializing length of an array to zero at starting since no elements are present

// printf("Enter number of numbers: ");
// scanf("%d",&n);

// printf("Enter the array elements: ");
// for(i=0; i<n; i++)
// scanf("%d",&arr.A[i]);
// arr.lenght = n;

// Display(arr);
//   return 0;
// }

// by static memory allocation
#include <stdio.h>
#include <stdlib.h>

struct Array
{
  int A[20];
  int size;
  int length;
};

void Display(struct Array arr)
{
  int i;
  printf("\nElements are\n");
  for (i = 0; i < arr.length; i++)
  {
    printf("%d ", arr.A[i]);
  }
}

void Append(struct Array *arr, int x)
{
  if (arr->length < arr->size)
  {
    arr->A[arr->length++] = x;
  }
}

void InsertAtPosition(struct Array *arr, int index, int x)
{
  if (index >= 0 && index < arr->length)
  {
    for (int i = arr->length; i > index; i--)
    {
      arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = x;
    arr->length++;
  }
}

int deleteAtposition(struct Array *arr, int index)
{
  int x = 0;
  if (index >= 0 && index < arr->length)
  {
    x = arr->A[index];
    for (int i = index; i < arr->length; i++)
    {
      arr->A[i] = arr->A[i + 1];
      arr->length--;
      return x;
    }
  }
  return 0;
}

int LinearSearch(struct Array arr, int key)
{
  for (int i = 0; i < arr.length; i++)
  {
    if (key == arr.A[i])
    {
      printf("element found at %d : ", i);
      return i;
    }
  }
  printf("element not found ");
  return -1;
}

// improvent of a linear search
// 1.transposition
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int LinearSearch2(struct Array *arr, int key)
{
  for (int i = 0; i < arr->length; i++)
  {
    if (key == arr->A[i])
    {
      swap(&arr->A[i], &arr->A[i - 1]);
      return i;
    }
  }
  return -1;
}

// 2.Move to front
int LinearSearch3(struct Array *arr, int key)
{
  for (int i = 0; i < arr->length; i++)
  {
    if (key == arr->A[i])
    {
      swap(&arr->A[i], &arr->A[0]);
      return i;
    }
  }
  return -1;
}
// binary search through iteratrive process
int Bsearch(struct Array arr, int key)
{
  int l = 0;
  int mid;
  int h = arr.length - 1;
  while (l <= h)
  {
    mid = (l + h) / 2;
    if (key == arr.A[mid])
    {
      return mid;
    }
    else if (key < arr.A[mid])
    {
      h = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  return -1;
}
// binary search through in recurrisve manner

int RecBsearch(int arr[], int l, int h, int key)
{

  int mid;
  if (l <= h)
  {
    mid = (l + h) / 2;
    if (key == arr[mid])
    {
      return mid;
    }
    else if (key < arr[mid])
    {
      return RecBsearch(arr, l, mid - 1, key);
    }
    else
    {
      return RecBsearch(arr, mid + 1, h, key);
    }
  }

  return -1;
}

int get(struct Array arr, int index)
{
  if (index >= 0 && index < arr.length)
  {
    return arr.A[index];
  }
  else
  {
    return -1;
  }
}

void set(struct Array *arr, int index, int x)
{
  if (index >= 0 && index < arr->length)
    arr->A[index] = x;
}

int max(struct Array arr)
{
  int max = arr.A[0];
  int i;
  for (i = 1; i < arr.length; i++)
  {
    if (arr.A[i] > max)
      max = arr.A[i];
  }
  return max;
}

int min(struct Array arr)
{
  int min = arr.A[0];
  int i;
  for (i = 1; i < arr.length; i++)
  {
    if (arr.A[i] < min)
      min = arr.A[i];

    return min;
  }
}

int sum(struct Array arr)
{
  int sum = 0;
  for (int i = 0; i < arr.length; i++)
  {
    sum += arr.A[i];
  }
  return sum;
}

float avg(struct Array arr)
{
  return (float)sum(arr) / arr.length;
}

void reverse(struct Array *arr)
{
  int *B;
  int i, j;

  B = (int *)malloc(arr->length * sizeof(int));

  // Copy elements from the original array to the reversed array
  for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
  {
    B[j] = arr->A[i];
  }

  // Copy elements from the reversed array back to the original array
  for (i = 0; i < arr->length; i++)
  {
    arr->A[i] = B[i];
  }

  free(B); // Free the memory allocated for the reversed array
}

void reverse2(struct Array *arr)
{
  int i, j;
  for (i = 0, j = arr->length - 1; i < j; i++, j--)
  {
    swap(&arr->A[i], &arr->A[j]);
  }
}

void leftShift(struct Array *arr)
{
  int x = arr->A[0];
  for (int i = 0; i < arr->length; i++)
  {
    arr->A[i] = arr->A[i + 1];
  }
  arr->A[arr->length] = x;
}

void leftRotation(struct Array *arr)
{
  int x = arr->A[0];
  for (int i = 0; i < arr->length; i++)
  {
    arr->A[i] = arr->A[i + 1];
  }
  arr->A[arr->length - 1] = x;
}

void InsertAtSorted(struct Array *arr, int x)
{
  int i = arr->length - 1;
  if (arr->length == arr->size)
    return;
  while (i >= 0 && arr->A[i] > x)
  {
    arr->A[i + 1] = arr->A[i];
    i--;
  }
  arr->A[i + 1] = x;
  arr->length++;
}

int isSorted(struct Array arr)
{
  int i;
  for (i = 0; i < arr.length - 1; i++)
  {
    if (arr.A[i] > arr.A[i + 1])
      return 0;
  }

  return 1;
}

void ReArrange(struct Array *arr)
{
  int i, j;
  i = 0;
  j = arr->length - 1;

  while (i < j)
  {
    while (arr->A[i] < 0)
      i++;
    while (arr->A[j] > 0)
      j--;
    if (i < j)
      swap(&arr->A[i], &arr->A[i + 1]);
  }
}

struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
  int i = 0, j = 0, k = 0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length)
  {
    if (arr1->A[i] < arr2->A[j])
    {
      arr3->A[k++] = arr1->A[i++];
    }
    else
    {
      arr3->A[k++] = arr2->A[j++];
    }
  }

  while (i < arr1->length)
  {
    arr3->A[k++] = arr1->A[i++];
  }

  while (j < arr2->length)
  {
    arr3->A[k++] = arr2->A[j++];
  }

  arr3->length = k;
  arr3->size = 10; // Set the size accordingly

  return arr3;
}

// intersection function
struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
  int i = 0, j = 0, k = 0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length)
  {
    if (arr1->A[i] < arr2->A[j])
    {
      i++;
    }
    else if (arr2->A[j] < arr1->A[i])
    {
      j++;
    }
    else if (arr1->A[i] == arr2->A[i])
    {
      arr3->A[k++] = arr1->A[i++];
      j++;
    }
  }

  arr3->length = k;
  arr3->size = 10; // Set the size accordingly

  return arr3;
}

// union of sets
struct Array *Union(struct Array *arr1, struct Array *arr2)
{
  int i = 0, j = 0, k = 0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length)
  {
    if (arr1->A[i] < arr2->A[j])
    {
      arr3->A[k++] = arr1->A[i++];
    }
    else if (arr2->A[j] < arr1->A[i])
    {
      arr3->A[k++] = arr2->A[j++];
    }
    else
    {
      arr3->A[k++] = arr1->A[i++];
      j++;
    }
  }

  while (i < arr1->length)
  {
    arr3->A[k++] = arr1->A[i++];
  }

  while (j < arr2->length)
  {
    arr3->A[k++] = arr2->A[j++];
  }

  arr3->length = k;
  arr3->size = 10; // Set the size accordingly

  return arr3;
}

// Difference
struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
  int i = 0, j = 0, k = 0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length)
  {
    if (arr1->A[i] < arr2->A[j])
    {
      arr3->A[k++] = arr1->A[i++];
    }
    else if (arr2->A[j] < arr1->A[i])
    {
      j++;
    }
    else
    {
      i++;
      j++;
    }
  }

  while (i < arr1->length)
  {
    arr3->A[k++] = arr1->A[i++];
  }

  arr3->length = k;
  arr3->size = 10; // Set the size accordingly

  return arr3;
}

int main()
{

  // struct Array arr = {{1, 2, 3, 4, 55}, 20, 5};
  // Append(&arr,987);
  // InsertAtPosition(&arr,0,123);
  // printf("%d",deleteAtposition(&arr,4));
  // printf("%d",LinearSearch(arr,4));
  // printf("%d",LinearSearch2(&arr,3));
  // printf("%d",LinearSearch3(&arr,3));
  // printf("%d",Bsearch(arr,5));
  // printf("%d", RecBsearch(arr.A, 0, arr.length, 3));

  // printf("%d ",get(arr,2));
  // set(&arr,1,45);
  // printf("%d\n \n", max(arr));
  // printf("%d\n \n", min(arr));
  // printf("%d\n \n", sum(arr));
  // printf("%f\n \n", avg(arr));
  // reverse(&arr);
  //   reverse2(&arr);
  // leftShift(&arr);
  // Display(arr);
  // leftRotation(&arr);

  // InsertAtSorted(&arr, 12);
  // printf("%d",isSorted(arr));

  // struct Array arr = {{1, 2, -3, 4, 55, -7, 20, -12}, 20, 5};

  // ReArrange(&arr);

  // merging of two sortewd array.......
  //  struct Array arr1 = {{1, 12, 33, 44,155}, 20, 5};
  //   struct Array arr2 = {{11, 28, 39, 48, 55}, 20, 5};
  //   struct Array *arr3;
  //   arr3= Merge(&arr1,&arr2);

  //  union of sets
  //  struct Array arr1 = {{1, 12, 33, 44,155}, 20, 5};
  //   struct Array arr2 = {{11, 12, 33, 48, 55}, 20, 5};
  //   struct Array *arr3;
  //   arr3= Union(&arr1,&arr2);

  // // intersection of sets
  //    struct Array arr1 = {{1, 12, 33, 44,155}, 20, 5};
  //     struct Array arr2 = {{11, 12, 33, 48, 55}, 20, 5};
  //     struct Array *arr3;
  //     arr3= Intersection (&arr1,&arr2);

  // Difference f two sets
  struct Array arr1 = {{2, 5, 10, 15, 25}, 20, 5};
  struct Array arr2 = {{3, 6, 7, 15, 20}, 20, 5};
  struct Array *arr3;
  arr3 = Difference(&arr1, &arr2);

  Display(*arr3);
  return 0;
}