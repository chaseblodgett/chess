#include "../include/Board.h"
#include "../include/Piece.h"
#include "../include/Pawn.h"
#include "../include/Rook.h"
#include "../include/Queen.h"
#include "../include/King.h"
#include "../include/Knight.h"
#include "../include/Bishop.h"
#include <string>
using namespace std;

Board :: Board() : Squares(8, vector<Square>(8)){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8 ; j++){
            Squares[i][j] = Square();
        }
    }
    whiteChecked = false;
    blackChecked = false;
    whiteMove = true;
    checkmate = false;
    draw = false;
    enPassantAble = false;
    enPassantCol = -1;
    blackScore = 0;
    whiteScore = 0;
}

void Board :: setBoard(){
    Piece *blackPawn1 = new Pawn(false, "black-pawn", 6, 0);
    Piece *blackPawn2 = new Pawn(false, "black-pawn", 6, 1);
    Piece *blackPawn3 = new Pawn(false, "black-pawn", 6, 2);
    Piece *blackPawn4 = new Pawn(false, "black-pawn", 6, 3);
    Piece *blackPawn5 = new Pawn(false, "black-pawn", 6, 4);
    Piece *blackPawn6 = new Pawn(false, "black-pawn", 6, 5);
    Piece *blackPawn7 = new Pawn(false, "black-pawn", 6, 6);
    Piece *blackPawn8 = new Pawn(false, "black-pawn", 6, 7);
    Piece *blackKnight1 = new Knight(false, "black-knight", 7, 1);
    Piece *blackKnight2 = new Knight(false, "black-knight", 7, 6);
    Piece *blackRook1 = new Rook(false, "black-knight", 7, 0);
    Piece *blackRook2 = new Rook(false, "black-rook", 7, 7);
    Piece *blackBishop1 = new Bishop(false, "black-bishop", 7, 2);
    Piece *blackBishop2 = new Bishop(false,"black-bishop", 7, 5);
    Piece *blackKing = new King(false,"black-king", 7,4);
    Piece *blackQueen = new Queen(false,"black-queen", 7,3);

    Piece *whitePawn1 = new Pawn(true,"white-pawn", 1, 0);
    Piece *whitePawn2 = new Pawn(true, "white-pawn", 1, 1);
    Piece *whitePawn3 = new Pawn(true,"white-pawn",1, 2);
    Piece *whitePawn4 = new Pawn(true,"white-pawn", 1, 3);
    Piece *whitePawn5 = new Pawn(true, "white-pawn",1, 4);
    Piece *whitePawn6 = new Pawn(true, "white-pawn",1, 5);
    Piece *whitePawn7 = new Pawn(true, "white-pawn",1, 6);
    Piece *whitePawn8 = new Pawn(true, "white-pawn",1, 7);
    Piece *whiteKnight1 = new Knight(true, "white-knight", 0, 1);
    Piece *whiteKnight2 = new Knight(true, "white-knight",0, 6);
    Piece *whiteRook1 = new Rook(true, "white-rook", 0, 7);
    Piece *whiteRook2 = new Rook(true, "white-rook", 0, 0);
    Piece *whiteBishop1 = new Bishop(true,"white-bishop", 0, 2);
    Piece *whiteBishop2 = new Bishop(true, "white-bishop", 0, 5);
    Piece *whiteKing = new King(true, "white-king", 0, 4);
    Piece *whiteQueen = new Queen(true,"white-queen", 0, 3);

    Squares[6][0].setPiece(*blackPawn1);
    Squares[6][1].setPiece(*blackPawn2);
    Squares[6][2].setPiece(*blackPawn3);
    Squares[6][3].setPiece(*blackPawn4);
    Squares[6][4].setPiece(*blackPawn5);
    Squares[6][5].setPiece(*blackPawn6);
    Squares[6][6].setPiece(*blackPawn7);
    Squares[6][7].setPiece(*blackPawn8);

    Squares[7][0].setPiece(*blackRook1);
    Squares[7][1].setPiece(*blackKnight1);
    Squares[7][2].setPiece(*blackBishop1);
    Squares[7][3].setPiece(*blackQueen);
    Squares[7][4].setPiece(*blackKing);
    Squares[7][5].setPiece(*blackBishop2) ;
    Squares[7][6].setPiece(*blackKnight2);
    Squares[7][7].setPiece(*blackRook2);

    Squares[0][0].setPiece(*whitePawn1);
    Squares[0][1].setPiece(*whitePawn2) ;
    Squares[0][2].setPiece(*whitePawn2);
    Squares[0][3].setPiece(*whitePawn3) ;
    Squares[0][4].setPiece(*whitePawn4) ;
    Squares[0][5].setPiece(*whitePawn5) ;
    Squares[0][6].setPiece(*whitePawn6) ;
    Squares[0][7].setPiece(*whitePawn7) ;

    Squares[0][0].setPiece(*whiteRook1);
    Squares[0][1].setPiece(*whiteKnight1);
    Squares[0][2].setPiece(*whiteBishop1);
    Squares[0][3].setPiece(*whiteQueen);
    Squares[0][4].setPiece(*whiteKing);
    Squares[0][5].setPiece(*whiteBishop2) ;
    Squares[0][6].setPiece(*whiteKnight2);
    Squares[0][7].setPiece(*whiteRook2);

}

bool Board :: inBounds(int i, int j){
  // Checking boundary conditions
  return i >= 0 && i < 8 && 
         j >= 0 && j < 8;
}
 
bool Board :: lookForKing(string type, int i, int j){
  // Store all possible moves 
  // of the king
  int x[] = {-1, -1, -1, 0, 
             0, 1, 1, 1};
  int y[] = {-1, 0, 1, -1,
             1, -1, 0, 1};
 
  for (int k = 0; k < 8; k++) {
    // incrementing index 
    // values
    int m = i + x[k];
    int n = j + y[k];
 
    // checking boundary 
    // conditions and 
    // character match
    if (inBounds(m, n) && Squares[m][n].getPieceType() == type){
        return true;
    }
  }
  return false;
}
 
// Function to check if bishop 
// can attack the king
bool Board :: lookForBishop(string type, int i, int j){
  // Check the lower right 
  // diagonal
  int k = 0;
  while (inBounds(i + (++k), j + k)) 
  {
    if (Squares[i + k][j + k].getPieceType() == type)
      return true;
    if (!Squares[i + k][j + k].isEmpty())
      break;
  }
 
  // Check the lower left diagonal
  k = 0;
  while (inBounds(i + (++k), j - k)) 
  {
    if (!Squares[i + k][j - k].isEmpty())
      break;
    if (Squares[i + k][j - k].getPieceType() == type)
      return true;
  }
 
  // Check the upper right 
  // diagonal
  k = 0;
  while (inBounds(i - (++k), j + k)) 
  {
    if (Squares[i - k][j + k].getPieceType() == type)
      return true;
    if (!Squares[i - k][j + k].isEmpty())
      break;
  }
 
  // Check the upper left 
  // diagonal
  k = 0;
  while (inBounds(i - (++k), j - k))
  {
    if (Squares[i - k][j - k].getPieceType() == type)
      return true;
    if (!Squares[i - k][j - k].isEmpty())
      break;
  }
 
  return false;
}
 
// Check if
bool Board :: lookForRook(string type, int i, int j){
  // Check downwards
  int k = 0;
  while (inBounds(i + ++k, j)) {
    if (Squares[i + k][j].getPieceType() == type)
      return true;
    if (!Squares[i + k][j].isEmpty())
      break;
  }
 
  // Check upwards
  k = 0;
  while (inBounds(i + --k, j)) 
  {
    if (Squares[i + k][j].getPieceType() == type)
      return true;
    if (!Squares[i + k][j].isEmpty())
      break;
  }
 
  // Check right
  k = 0;
  while (inBounds(i, j + ++k)) 
  {
    if (Squares[i][j + k].getPieceType() == type)
      return true;
    if (!Squares[i][j + k].isEmpty())
      break;
  }
 
  // Check left
  k = 0;
  while (inBounds(i, j + --k)) 
  {
    if (Squares[i][j + k].getPieceType() == type)
      return true;
    if (!Squares[i][j + k].isEmpty())
      break;
  }
  return false;
}
 
// Function to check if Queen 
// can attack the King
bool Board :: lookForQueen(string type, int i, int j){
  // Queen's moves are a combination
  // of both the Bishop and the Rook
  if (lookForBishop(type, i, j) || lookForRook(type, i, j))
    return true;
 
  return false;
}

// Check if the knight can 
// attack the king
bool Board :: lookForKnight(string type,int i, int j){
  // All possible moves of
  // the knight
  int x[] = {2, 2, -2, -2, 
             1, 1, -1, -1};
  int y[] = {1, -1, 1, -1, 
             2, -2, 2, -2};
 
  for (int k = 0; k < 8; k++) 
  {
    // Incrementing index 
    // values
    int m = i + x[k];
    int n = j + y[k];
 
    // Checking boundary conditions
    // and character match
    if (inBounds(m, n) && Squares[m][n].getPieceType() == type)
      return true;
  }
  return false;
}
 
// Function to check if pawn 
// can attack the king
bool Board :: lookForPawn(int i, int j, bool color){
  string lookFor;
  if (!color) 
  {
    // Check for white pawn
    lookFor = "white-pawn";
    if (inBounds(i + 1, j - 1) && Squares[i + 1][j - 1].getPieceType() == lookFor)
      return true;
 
    if (inBounds(i + 1, j + 1) && Squares[i + 1][j + 1].getPieceType() == lookFor)
      return true;
  }
  else
  {
    // Check for black pawn
    lookFor = "black-pawn";
    if (inBounds(i - 1, j - 1) && Squares[i - 1][j - 1].getPieceType() == lookFor)
      return true;
    if (inBounds(i - 1, j + 1) && Squares[i - 1][j + 1].getPieceType() == lookFor)
      return true;
  }
  return false;
}
 
// Function to check if any 
// of the two kings is unsafe
// or not
int Board :: checkBoard()
{
  // Find the position of both 
  // the kings
  for (int i = 0; i < 8; i++) 
  {
    for (int j = 0; j < 8; j++) 
    {
      // Check for all pieces which
      // can attack White King
      if (Squares[i][j].getPieceType() == "white-king") 
      {
        // Check for Knight
        if (lookForKnight("black-knight", i, j))
          return 1;
 
        // Check for Pawn
        if (lookForPawn(i, j, true))
          return 1;
 
        // Check for Rook
        if (lookForRook("black-rook", i, j))
          return 1;
 
        // Check for Bishop
        if (lookForBishop("black-bishop", i, j))
          return 1;
 
        // Check for Queen
        if (lookForQueen("black-queen", i, j))
          return 1;
 
        // Check for King
        if (lookForKnight("black-king", i, j))
          return 1;
      }
 
      // Check for all pieces which
      // can attack Black King
      if (Squares[i][j].getPieceType() == "black-king") 
      {
        // Check for Knight
        if (lookForKnight("white-knight", i, j))
          return 2;
 
        // Check for Pawn
        if (lookForPawn(i, j, false))
          return 2;
 
        // Check for Rook
        if (lookForRook("white-rook", i, j))
          return 2;
 
        // Check for Bishop
        if (lookForBishop("white-bishop", i, j))
          return 2;
 
        // Check for Queen
        if (lookForQueen("white-queen", i, j))
          return 2;
 
        // Check for King
        if (lookForKing("white-king", i, j))
          return 2;
      }
    }
  }
  return 0;
}

vector< vector<Square> > Board :: getBoard(){
    return Squares;
}

void Board :: makeMove(Piece &piece, int row, int col){
    if(!Squares[row][col].isEmpty()){
        Squares[row][col].removePiece();
    }
    Squares[row][col].setPiece(piece);
    Squares[piece.getRow()][piece.getCol()].setEmpty();
    piece.setRow(row);
    piece.setColumn(col);
    return;
}

bool Board :: isEnpassantValid(){
    return enPassantAble;
}

void Board :: setEnpassant(bool val){
    enPassantAble = val;
}

void Board :: setEnpassantCol(int col){
    enPassantCol = col;
}

int Board :: getEnpassantCol(){
    return enPassantCol;
}
