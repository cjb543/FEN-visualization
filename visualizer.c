#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processBoardAppearance(char FENString[], char finishedBoard[]);
void processGameState(char FENString[], int *whitePieceCount,
                      int *blackCountPiece, int *whiteFiftyMoveTracker,
                      int *blackFiftyMoveTracker, bool *whiteToMove,
                      bool *whiteCanCastle, bool *blackCanCastle,
                      bool *hasEnPassant);
void printBoard(char finishedBoard[], int whitePieceCount, int blackPieceCount,
                bool whiteToMove, bool whiteCanCastle, bool blackCanCastle,
                int whiteFiftyMoveTracker, int blackFiftyMoveTracker,
                bool hasEnPassant);

int main(int argc, char *argv[]) {
  int whitePieceCount = 0, blackPieceCount = 0, whiteFiftyMoveTracker = 0,
      blackFiftyMoveTracker = 0;
  bool whiteToMove = false, whiteCanCastle = false, blackCanCastle = false,
       hasEnPassant = false;
  char FENString[91] = "";
  char finishedBoard[65];

  if (argc < 2 || argc > 7) {
    printf("Usage: %s <FEN string>\n", argv[0]);
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    strncat(FENString, argv[i], 90 - strlen(FENString));
    if (i < argc - 1) {
      strncat(FENString, " ", 90 - strlen(FENString));
    }
  }

  processBoardAppearance(FENString, finishedBoard);
  processGameState(FENString, &whitePieceCount, &blackPieceCount,
                   &whiteFiftyMoveTracker, &blackFiftyMoveTracker, &whiteToMove,
                   &whiteCanCastle, &blackCanCastle, &hasEnPassant);
  printBoard(finishedBoard, whitePieceCount, blackPieceCount, whiteToMove,
             whiteCanCastle, blackCanCastle, whiteFiftyMoveTracker,
             blackFiftyMoveTracker, hasEnPassant);

  return 0;
}

void processBoardAppearance(char FENString[], char finishedBoard[]) {
  int i = 0, j = 0;
  while (FENString[i] != '\0') {
    if (isdigit(FENString[i])) {
      int numSpaces = FENString[i] - '0';
      for (int k = 0; k < numSpaces; k++) {
        finishedBoard[j] = '0';
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
                      int *blackPieceCount, int *whiteFiftyMoveTracker,
                      int *blackFiftyMoveTracker, bool *whiteToMove,
                      bool *whiteCanCastle, bool *blackCanCastle,
                      bool *hasEnPassant) {
  for (int i = 0; i < 91; i++) {
    printf("%c", FENString[i]);
  }
  printf("%s", "\n");
}

void printBoard(char finishedBoard[], int whitePieceCount, int blackPieceCount,
                bool whiteToMove, bool whiteCanCastle, bool blackCanCastle,
                int whiteFiftyMoveTracker, int blackFiftyMoveTracker,
                bool hasEnPassant) {
  // Print actual board
  printf(" ");
  int i = 0;
  while (finishedBoard[i] != '\0') {
    printf("%c ", finishedBoard[i]);
    i++;
  }
  printf("\n");

  // Handle piece counts
  printf("White has %d pieces. \n", whitePieceCount);
  printf("Black has %d pieces. \n", blackPieceCount);

  // Handle move turn
  if (whiteToMove)
    printf("White to move. \n");
  else
    printf("Black to move. \n");

  // Handle castling
  if (whiteCanCastle)
    printf("White has castling rights.\n");
  else if (!whiteCanCastle)
    printf("White does not have castling rights.\n");
  if (blackCanCastle)
    printf("Black has castling rights.\n");
  else if (!blackCanCastle) {
    printf("Black does not have castling rights.\n");
  }

  // Handle 50-move-rule tracking
  printf("White has %d moves until 50-move rule.\n", whiteFiftyMoveTracker);
  printf("Black has %d moves until 50-move rule.\n", blackFiftyMoveTracker);
}
