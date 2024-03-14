#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void length(char A[]) {
  int i;
  for (i = 0; A[i] != '\0'; i++)
    ;
  printf("The Length of a string: %d ", i);
}

void toUpper(char A[]) {
  for (int i = 0; A[i] != '\0'; i++) {
    A[i] = toupper(A[i]);
  }
  printf("%s", A);
}

void toLower(char A[]) {
  for (int i = 0; A[i] != '\0'; i++) {
    A[i] = tolower(A[i]);
  }
  printf("%s", A);
}

void toggleAlpha(char A[]) {
  for (int i = 0; A[i] != '\0'; i++) {
    if (isalpha(A[i])) {
      A[i] ^= 32; // Toggle case using XOR
    }
  }
  printf("%s", A);
}

void VCcount(char A[]) {
  int Vcount = 0, Ccount = 0, word = 0;

  for (int i = 0; A[i] != '\0'; i++) {
    if (strchr("aeiouAEIOU", A[i]) != NULL) {
      Vcount++;
    } else if (isalpha(A[i])) {
      Ccount++;
    }

    if (A[i] == ' ' && A[i - 1] != ' ') {
      word++;
    }
  }

  printf("The vowel count in a given string: %d\n", Vcount);
  printf("The consonants count in a given string: %d\n", Ccount);
  printf("The total number of words in a given string is: %d", word);
}

bool validStr(char A[]) {
  for (int i = 0; A[i] != '\0'; i++) {
    if (!(isalnum(A[i]) || isspace(A[i]))) {
      return false;
    }
  }
  return true;
}

int main() {
  char A[] = "welcome";
  length(A);
  printf("\n");

  char B[] = "WELCOME";
  toLower(B);
  printf("\n");

  char C[] = "Wel5CoMe";
  toggleAlpha(C);
  printf("\n");

  char D[] = "Hi Guys How are     you all";
  VCcount(D);
  printf("\n");

  if (validStr(C)) {
    printf("The string is valid.\n");
  } else {
    printf("The string is not valid.\n");
  }

  return 0;
}
