#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void processBoardAppearance(char FENString[], char finishedBoard[]);
void processGameState(char FENString[], int *whitePieceCount,
                      int *blackCountPiece, bool *whiteToMove);
void printBoard(char FENString[], int whitePieceCount, int blackPieceCount,
                bool whiteToMove);

int main() {
  int whitePieceCount = 0, blackPieceCount = 0;
  bool whiteToMove;
  char FENString[91];
  char finishedBoard[65];

  printf("Enter a FEN string: ");
  scanf("%s", FENString);

  processBoardAppearance(FENString, finishedBoard);
  processGameState(FENString, &whitePieceCount, &blackPieceCount, &whiteToMove);
  printBoard(finishedBoard, whitePieceCount, blackPieceCount, whiteToMove);

  return 0;
}

void processBoardAppearance(char FENString[], char finishedBoard[]) {
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

void processGameState(char FENString[], int *whitePieceCount,
                      int *blackPieceCount, bool *whiteToMove) {
  for (int i = 0; i < 91; i++) {
    if (isupper(FENString[i]) && isalpha(FENString[i])) {
      whitePieceCount++;
    } else if (!isupper(FENString[i]) && isalpha(FENString[i])) {
      blackPieceCount++;
    }
  }
}

void printBoard(char finishedBoard[], int whitePieceCount, int blackPieceCount,
                bool whiteToMove) {
  printf("%s", finishedBoard);
  printf("\n");

  printf("White has %d pieces \n", whitePieceCount);
  printf("Black has %d pieces \n", blackPieceCount);

  if (whiteToMove)
    printf("White to move \n");
  else
    printf("blackToMove \n");
}
