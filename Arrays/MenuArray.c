
#include <stdio.h>
#include <stdlib.h>

struct Array
{
  int *A;
  int size;
  int length;
};

// DISPLAY FUNCTION
void Display(struct Array arr)
{
  int i;
  printf("\nElements are\n");
  for (i = 0; i < arr.length; i++)
  {
    printf("%d ", arr.A[i]);
  }
}

// APPEND FNX TO ADD ELEMENT AT LAST
void Append(struct Array *arr, int x)
{
  if (arr->length < arr->size)
  {
    arr->A[arr->length++] = x;
  }
}

// FNX TO INSERT THE ELEMENT AT ANY POSITION
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

// FNX TO DELETE THE ELEMENT AT ANY POSITION
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

// LINEAR SEARCH METHOD
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

// fnx to swap the elements
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

// improvent of a linear search
// 1.transposition
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

// GET FNX TO OBTAIN THE ELEMENT AT ANY IDX
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

// FNX TO SET ANY VALUE AT A PARTICULAR INDEX
void set(struct Array *arr, int index, int x)
{
  if (index >= 0 && index < arr->length)
    arr->A[index] = x;
}

// FNX TO FIND THE MAX ELEMENT IN ARRAY
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

// FNX TO FIND THE MINIMUM OF AN ARRAY
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

// FNX TO FIND THE  SUM OF AN ARRAY
int sum(struct Array arr)
{
  int sum = 0;
  for (int i = 0; i < arr.length; i++)
  {
    sum += arr.A[i];
  }
  return sum;
}

// FNX TO FIND THE AVERAGE OF AN ARRAY ELEMENTS
float avg(struct Array arr)
{
  return (float)sum(arr) / arr.length;
}

// FNX TO REVERSE THE ARRAY ELEMENTS
void reverse(struct Array *arr)
{
  int *B;
  int i, j;

  B = (int *)malloc(arr->length * sizeof(int));

  for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
  {
    B[j] = arr->A[i];
  }

  for (i = 0; i < arr->length; i++)
  {
    arr->A[i] = B[i];
  }

  free(B);
}

// REVERSING THE ARRAY WITHOUT USING ANY EXTRA ARRAY
void reverse2(struct Array *arr)
{
  int i, j;
  for (i = 0, j = arr->length - 1; i < j; i++, j--)
  {
    swap(&arr->A[i], &arr->A[j]);
  }
}

// FNX TO LEFT SHIFT THE ARRAY ELEMNTS
void leftShift(struct Array *arr)
{
  int x = arr->A[0];
  for (int i = 0; i < arr->length; i++)
  {
    arr->A[i] = arr->A[i + 1];
  }
  arr->A[arr->length] = x;
}

// FNX TO LEFT ROTATION OF AN ARRAY ELEMNTS
void leftRotation(struct Array *arr)
{
  int x = arr->A[0];
  for (int i = 0; i < arr->length; i++)
  {
    arr->A[i] = arr->A[i + 1];
  }
  arr->A[arr->length - 1] = x;
}

// FNX TO INSERT THE ELEMENT IN A SORTED ARRAY AT <AFTER INSERTION OF ELEMENT THE ARRAY STILL REMAINS SORTED>
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

// FNX TO CHECK WEATHER THE ARRAY ELEMNTS ARE SORTED OR NOT
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

// SEGRETATING THE NEGATIVE ELEMENTS TO LEFT SIDE OF AN ARRAY
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

// FNX TO MERGE TWO SORTED ARRAY ELEMENTS
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
  arr3->size = 10;

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
  arr3->size = 10;

  return arr3;
}

// Difference of two sets
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
  arr3->size = 10;

  return arr3;
}

int main()
{

  struct Array arr1;
  printf("Enter the size of an Array\n");
  scanf("%d", &arr1.size);
  arr1.A = (int *)malloc(arr1.size * sizeof(int));

   int choice, x, index;

  do
  {
    printf("\nMenu:\n");
    printf("1. Display\n");
    printf("2. Append\n");
    printf("3. Insert at Position\n");
    printf("4. Delete at Position\n");
    printf("5. Linear Search\n");
    printf("6. Improved Linear Search\n");
    printf("7. Binary Search\n");
    printf("8. Reverse\n");
    printf("9. Left Shift\n");
    printf("10. Left Rotation\n");
    printf("11. Insert at Sorted Position\n");
    printf("12. Check if Sorted\n");
    printf("13. Segregate Negative Elements\n");
    printf("14. Merge Two Sorted Arrays\n");
    printf("15. Intersection of Two Arrays\n");
    printf("16. Union of Two Arrays\n");
    printf("17. Difference of Two Arrays\n");
    printf("18. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      Display(arr1);
      break;
    case 2:
      printf("Enter the element to append: ");
      scanf("%d", &x);
      Append(&arr1, x);
      break;
    case 3:
      printf("Enter the position and element to insert: ");
      scanf("%d %d", &index, &x);
      InsertAtPosition(&arr1, index, x);
      break;
    case 4:
      printf("Enter the position to delete: ");
      scanf("%d", &index);
      deleteAtposition(&arr1, index);
      break;
    case 5:
      printf("Enter the key to search: ");
      scanf("%d", &x);
      LinearSearch(arr1, x);
      break;
    case 6:
      // Call the function for Improved Linear Search
       printf("%d",LinearSearch2(&arr1,3));
      break;
    case 7:
      // Call the function for Binary Search
       printf("%d",LinearSearch2(&arr1,3));
      break;
    case 8:
      // Call the function for Reverse
      break;
    case 9:
      // Call the function for Left Shift
      break;
    case 10:
      // Call the function for Left Rotation
      break;
    case 11:
      // Call the function for Insert at Sorted Position
      break;
    case 12:
      // Call the function for Check if Sorted
      break;
    case 13:
      // Call the function for Segregate Negative Elements
      break;
    case 14:
      // Call the function for Merge Two Sorted Arrays
      break;
    case 15:
      // Call the function for Intersection of Two Arrays
      break;
    case 16:
      // Call the function for Union of Two Arrays
      break;
    case 17:
      // Call the function for Difference of Two Arrays
      break;
    case 18:
      freeMemory(&arr1);
      printf("Exiting program.\n");
      break;
    default:
      printf("Invalid choice! Please try again.\n");
      break;
    }
  } while (choice != 18);


  return 0;
}