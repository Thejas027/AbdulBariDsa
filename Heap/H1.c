// program for max and heap sort

#include <stdio.h>
#include <stdlib.h>

void Insert(int A[], int n)
{
    int i = n, temp;
    temp = A[i];

    while (i > 1 && temp > A[i / 2]) // temo value is comopared to its parent value if its greater then swaping will be done
    {
        A[i] = A[i / 2];
        i = i / 2; // i is moved to its parent index for further checking...
    }
    A[i] = temp; // value of temp is copying to index i position where ever i is pointing
}

int delete(int A[], int n)
{
    int val = A[1];
    A[1] = A[n];
    A[n] = val;

    int i = 1, j = 2 * i;

    while (j < n - 1)
    {
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;

        if (A[i] < A[j])
        {
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }

    return val;
}

int main()
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    // 40,25,35,10,5,20,30   --->result should be
    int i;
    for (i = 2; i < 7; i++)
        Insert(H, i);

    printf("Deleted Element is : %d \n ", delete (H, 7));
    // printf("Deleted Element is : %d \n ", delete (H, 6));

    // for (i = 7; i >= 1; i--)
    //   delete (H, i);

    for (i = 1; i <= 7; i++)
        printf("%d ", H[i]);
    return 0;
}