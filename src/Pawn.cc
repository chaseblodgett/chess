#include "../include/Pawn.h"

Pawn :: Pawn(bool color, string type, int row, int col) : Piece(color,type,row,col), value(3){
    firstMove = true;
}

bool Pawn :: isFirstMove(){
    return firstMove;
}

bool Pawn :: isMoveValid(int row, int col, Board &board){
    // Out of bounds
    if (row < 0 || row >= 8 || col < 0 || col >= 8) {
        return false;
    }

    // If ending square has same color piece
    if(color == board.getBoard()[row][col].getPiece().getColor()){
        return false;
    }

    int rowDiff = row - this->getRow();
    int colDiff = col - this->getCol();

    // Determine the direction the pawn is moving (up or down the board based on its color)
    int direction = (color) ? 1 : -1;

    // Check if the destination square is one square ahead of the current position
    if (colDiff == 0 && rowDiff == direction) {
        // Check if the destination square is unoccupied
        if (board.getBoard()[row][col].isEmpty()) {
            return true;
        }
    }

    // Check if it's the pawn's first move and it's trying to move two squares
    else if (colDiff == 0 && rowDiff == 2 * direction && isFirstMove()) {
        // Check if both squares in front of the pawn are unoccupied
        if (board.getBoard()[currentRow + direction][currentCol].isEmpty() && board.getBoard()[row][col].isEmpty()) {
            board.setEnpassant(true);
            board.setEnpassantCol(col);
            return true;
        }
    }

    // Check if it's a diagonal capture (one square forward and one square to the left or right)
    else if (abs(colDiff) == 1 && rowDiff == direction) {
        // Check if the destination square is occupied by an opponent's piece
        if (!board.getBoard()[row][col].isEmpty() && board.getBoard()[row][col].getPiece().getColor() != color) {
            return true;
        }
        // Check for en passant capture
        if (board.isEnpassantValid() && !board.getBoard()[row][col].isEmpty() && col == board.getEnpassantCol()) {
            board.setEnpassant(false);
            board.setEnpassantCol(-1);
            return true;
        }
    }

    return false;

}