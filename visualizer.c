#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void processFEN(char FENString[], char finishedBoard[]);
void printBoard(char FENString[]);

int main() {
  char FENString[91];
  char finishedBoard[65];

  printf("Enter a FEN string: ");
  scanf("%s", FENString);

  processFEN(FENString, finishedBoard);
  printBoard(finishedBoard);
  return 0;
}

void processFEN(char FENString[], char finishedBoard[]) {
  int i = 0, j = 0;
  while (FENString[i] != '\0') {
    if (isdigit(FENString[i])) {
      int numSpaces = FENString[i] - '0';
      for (int k = 0; k < numSpaces; k++) {
        finishedBoard[j] = 'X';
        ++j;
      }
    } else if (isalpha(FENString[i])) {
      finishedBoard[j] = FENString[i];
      ++j;
    } else if (FENString[i] == '/') {
      finishedBoard[j] = '\n';
      ++j;
    }
    ++i;
  }
  finishedBoard[j] = '\0';
}

void printBoard(char finishedBoard[]) {
  printf("%s", finishedBoard);
  printf("\n");
}
