#include "../include/Rook.h"
#include <string>
using namespace std;

Rook :: Rook(bool color, string type, int row , int col) : Piece(color, type , row, col), value(5){
    moved = false;
}

bool Rook :: isMoveValid(int row, int col, Board& board){
    // Out of bounds
    if (row < 0 || row >= 8 || col < 0 || col >= 8) {
        return false;
    }

    // If rook has moved both columns and rows
    if(row != currentRow && col != currentCol){
        return false;
    }

    // If ending square has same color piece
    if(color == board.getBoard()[row][col].getPiece().getColor()){
        return false;
    }

    int directionRow = (row > currentRow) ? 1 : (row < currentRow) ? -1 : 0;
    int directionCol = (col > currentCol) ? 1 : (col < currentCol) ? -1 : 0;
    for (int r = currentRow + directionRow, c = currentCol + directionCol;r != row || c != col;r += directionRow, c += directionCol) {
        if (!board.getBoard()[r][c].isEmpty()) {
            return false;  // There is a piece in the path
        }
    }

    // Check if king is under attack
    Board tmp_board = board;
    Rook tmp_piece = *this;
    board.makeMove(tmp_piece, row, col);

    if(tmp_board.checkBoard() == 1 && color){
        return false;
    }
    if(tmp_board.checkBoard() == 2 && !color){
        return false;
    }

    moved = true;
    return true;
    
}


