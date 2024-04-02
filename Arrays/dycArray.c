// ARRAY OPERATION BY DYNAMIC MEMORY ALLOCATION

#include <stdio.h>
#include <stdlib.h>

void Read(int *arr, int size)
{
    printf("Enter array elements\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", (arr + i));
    }
}

void Display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void insertByPosition(int *arr, int *size, int pos, int val)
{
    if (pos >= 0 && pos <= *size)
    {
        for (int i = *size - 1; i >= pos; i--)
        {
            *(arr + i + 1) = *(arr + i);
        }
        *(arr + pos) = val;
        (*size)++;
    }
    else
    {
        printf("Position not found\n");
    }
}

int deleteByPosition(int *arr, int *size, int pos)
{
    if (pos >= 0 && pos < *size)
    {
        int val = *(arr + pos);
        for (int i = pos; i < *size - 1; i++)
        {
            *(arr + i) = *(arr + i + 1);
        }
        (*size)--;
        return val;
    }
    else
    {
        printf("Deletion cannot be done\n");
        return -1;
    }
}

int searchByElement(int *arr, int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) == key)
        {
            return i;
        }
    }
    return -1;
}

void insertByKey(int *arr, int *size, int key, int val)
{
    int pos = searchByElement(arr, *size, key);
    if (pos != -1)
    {
        insertByPosition(arr, size, pos, val);
    }
    else
    {
        printf("Key not found. Insertion not possible\n");
    }
}

void deletionByKey(int *arr, int *size, int key)
{
    int pos = searchByElement(arr, *size, key);
    if (pos != -1)
    {
        deleteByPosition(arr, size, pos);
        Display(arr, *size);
    }
    printf("Deletion cannot be done. Key not found.\n");
}

void insertByOrder(int *arr, int *size, int val)
{
    int i = *size - 1;
    while (i >= 0 && arr[i] > val)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = val;
    (*size)++;
}

int searchByKey(int *arr, int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) == key)
        {
            return i + 1;
        }
    }
    return -1;
}

int searchByPos(int *arr, int size, int pos)
{
    if (pos < 0 || pos >= size)
    {
        printf("Invalid position\n");
        return -1;
    }
    return *(arr + pos);
}

void reverseArray(int *arr, int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        // Swap elements at start and end indices
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int n;
    printf("Enter the size of an array\n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    Read(arr, n);

    int choice;
    do
    {
        printf("\nEnter your choice\n");
        printf("1. Insertion by position\n");
        printf("2. Deletion by position\n");
        printf("3. Insert by key\n");
        printf("4. Deletion by key\n");
        printf("5. Insert by order\n");
        printf("6. Search by key\n");
        printf("7. Search by position\n");
        printf("8. Reverse the contents\n");
        printf("9. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Insertion by position\n");
            insertByPosition(arr, &n, 0, 10);
            Display(arr, n);
            break;
        case 2:
            printf("Deletion by position\n");
            deleteByPosition(arr, &n, 0);
            Display(arr, n);
            break;
        case 3:
            insertByKey(arr, &n, 1, 212);
            Display(arr, n);
            break;
        case 4:
            deletionByKey(arr, &n, 1);
            break;
        case 5:
            printf("Insert by order\n");
            insertByOrder(arr, &n, 5);
            Display(arr, n);
            break;
        case 6:
            printf("The key element is present at position: %d\n", searchByKey(arr, n, 55));
            break;
        case 7:
            printf("Element found at a given position is: %d\n", searchByPos(arr, n, 1));
            break;
        case 8:
            printf("Reversing the contents\n");
            reverseArray(arr, n);
            Display(arr, n);
            break;
        case 9:
            printf("Exiting function\n");
            free(arr);
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 9);

    free(arr);
    return 0;
}
