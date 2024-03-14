#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int length(char A[])
{
  int i;
  for (i = 0; A[i] != '\0'; i++)
    ;
  printf("The Lenght of a string : %d ", i);
  return 0;
}

void toUpper(char A[])
{
  int i;
  for (i = 0; A[i] != '\0'; i++)
  {
    A[i] -= 32; // Corrected to convert to uppercase
  }
  printf("%s", A); // Print the whole string
}

void toLower(char A[])
{
  int i;
  for (i = 0; A[i] != '\0'; i++)
  {
    A[i] += 32; // Corrected to convert to uppercase
  }
  printf("%s", A); // Print the whole string
}

void toggleAlpha(char A[])
{
  int i;
  for (i = 0; A[i] != '\0'; i++)
  {
    if (A[i] >= 'A' && A[i] <= 'Z')
    {
      A[i] += 32;
    }
    else if (A[i] >= 'a' && A[i] <= 'z')
    {
      A[i] -= 32;
    }
  }
  printf("%s", A);
}

void VCcount(char A[])
{
  int i, Vcount = 0, Ccount = 0, word = 1;

  for (i = 0; A[i] != '\0'; i++)
  {
    if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
    {
      Vcount++;
    }
    else if (A[i] >= 'A' && A[i] <= 'Z' || A[i] >= 'a' && A[i] <= 'z')
    {
      Ccount++;
    }
    if (A[i] == ' ' && A[i - 1] != ' ')
    { // white spaces also needed to be checked here
      word++;
    }
  }
  printf("The vowel count in a given string : %d\n", Vcount);
  printf("The consents count in a given string : %d\n", Ccount);
  printf("The total number of words in a given string is : %d", word);
}

bool validStr(char A[])
{
  for (int i = 0; A[i] != '\0'; i++)
  {
    if (!((A[i] >= 'A' && A[i] <= 'Z') || (A[i] >= 'a' && A[i] <= 'z') || (A[i] >= '1' && A[i] <= '9')))
    {
      return false;
    }
  }
  return true;
}

// fnx to reverse the string
void RevStr1(char A[])
{
  char t;
  int i, j;
  for (j = 0; A[j] != '\0'; j++)
    ;
  j = j - 1;

  for (i = 0; i < j; i++, j--)
  {
    t = A[i];
    A[i] = A[j];
    A[j] = t;
  }
  printf("The Reversed Str : %s\n", A);
}

// fnx for checking a palindrome

int isPalindrome(char A[])
{
  int i, j;
  for (i = 0; A[i] != '\0'; i++)
  {
  }
  i = i - 1;
  for (j = 0; i >= 0; i--, j++)
  {
    if (A[i] != A[j])
    {
      return 0;
    }
  }
  return 1;
}

// fnx to  check weather the 2 strings are equel or not independent of cases

void EqlStr(char A[], char B[])
{
  int i;
  for (i = 0; A[i] != '\0' && B[i] != '\0'; i++)
  {
    if (A[i] != B[i])
    {
      break;
    }
    if (A[i] == B[i])
    {
      printf("two strings are equal\n");
    }
    else if (A[i] < B[i])
    {
      printf("String A is Smaller\n");
    }
    else
    {
      printf("String A is Greater\n");
    }
  }
}

// fnx to remove the duplicates

void RemoveDup(char A[])
{
  int i, j;
  for (i = 0; A[i] != '\0'; i++)
  {
    for (j = i + 1; A[j] != '\0'; j++)
    {
      if (A[i] == A[j])
      {
        int k = j;
        while (A[k] != '\0')
        {
          A[k] = A[k + 1];
          k++;
        }
        j--;
      }
    }
  }
}

// void RemoveDup2(char A[])
// {
//   int H[26];
//   int i;
//   for (i = 0; A[i] != '\0'; i++)
//   {
//     H[A[i] - 97] += 1;
//   }
//   for (i = 0; i < 26; i++)
//   {
//     if (H[i] > 1)
//       printf("%c", i + 97);
//     printf("%d", H[i]);
//   }
// }

// void RemoveDup3(char A[])
// {
//   int H = 0;
//   int  x = 0;

//   for (int i = 0; A[i] != '\0'; i++)
//   {
//     x = 1;
//     x = x << A[i] - 97;
//     if (x & H > 0)
//     {
//       printf("%c is a duplicate\n", A[i]);
//     }
//     else
//     {
//       H = x | H;
//     }
//   }
// }

// fnx to check weather the string is a anagram or not

void anagramStr(char A[], char B[])
{
  int H[26] = {0};
  int i;

  for (i = 0; A[i] != '\0'; i++)
  {
    H[A[i] - 97] += 1;
  }
  for (i = 0; B[i] != '\0'; i++)
  {
    H[B[i] - 97] -= 1;

    if (H[B[i] - 97] < 0)
    {
      printf("String is not a angram\n");
 return;
    }
  }
  if (B[i] == '\0')
  {
    printf("its a Angram String\n");
  }
}

int main()
{
  // char A[] = "madam";

  // length(A);
  // printf("\n");
  // toUpper(A);
  // printf("\n");

  // char B[] = "finding";
  // toLower(B);
  // printf("\n");

  // char C[] = "Wel5CoMe";
  // toggleAlpha(C);
  // printf("\n");

  // char D[] = "Hi Guys How are     you all";
  // VCcount(D);
  // printf("\n");
  // if (validStr(C))
  // {
  //   printf("The string is valid.\n");
  // }
  // else
  // {
  //   printf("The string is not valid.\n");
  // }

  // RevStr1(D);
  // printf("\n");
  // EqlStr(A, B);
  // printf("\n\n\n");
  // if (isPalindrome(A))
  // {
  //   printf("its a palindrome\n");
  // }
  // else
  // {
  //   printf("not a palindrome\n");
  // }

  // RemoveDup3(B);
  char P[] = "decimal";
  char Q[] = "meddical";

  anagramStr(P, Q);
  return 0;
}
