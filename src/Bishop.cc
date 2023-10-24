#include "../include/Bishop.h"

Bishop :: Bishop(bool color,string type, int row , int col) : Piece(color, type , row, col), value(3){}

bool Bishop :: isMoveValid(int row, int col, Board &board){
    // Out of bounds
    if (row < 0 || row >= 8 || col < 0 || col >= 8) {
        return false;
    }
    // If ending square has same color piece
    if(this->color == board.getBoard()[row][col].getPiece().getColor()){
        return false;
    }

    int rowDiff = abs(row - this->getRow());
    int colDiff = abs(col - this->getCol());

    // A Bishop can only move diagonally, so the row and column differences must be equal
    if (rowDiff != colDiff) {
        return false;
    }

    // Check if there are any pieces blocking the path of the Bishop
    int directionRow = (row > this->getRow()) ? 1 : -1;
    int directionCol = (col > this->getCol()) ? 1 : -1;

    for (int r = this->getRow() + directionRow, c = this->getCol() + directionCol; r != row;r += directionRow, c += directionCol) {
        if (!board.getBoard()[row][col].isEmpty()) {
            return false;  // There is a piece in the path
        }
    }

    Board tmp_board = board;
    Bishop tmp_piece = *this;
    tmp_board.makeMove(tmp_piece,row,col);

    if(tmp_board.checkBoard() == 1 && this->color){
        return false;
    }
    if(tmp_board.checkBoard() == 2 && !this->color){
        return false;
    }

    return true;
}