#include "../include/King.h"

King :: King(bool color,string type, int row , int col) : Piece(color, type , row, col){
    moved = false;
    underCheck = false;
}

bool King :: isMoveValid(int row, int col, Board &board){
    // Out of bounds
    if (row < 0 || row >= 8 || col < 0 || col >= 8) {
        return false;
    }

    // If ending square has same color piece
    if(color == board.getBoard()[row][col].getPiece().getColor()){
        return false;
    }

    int rowDiff = abs(row - currentRow);
    int colDiff = abs(col - currentCol);

    // If king moved more than one square
    if ((rowDiff > 1) || (colDiff > 1)){
        return false;
    }

    // Check if still in check after move
    Board tmp_board = board;
    King tmp_piece = *this;
    tmp_board.makeMove(tmp_piece,row,col);

    if(tmp_board.checkBoard() == 1 && this->color){
        return false;
    }
    if(tmp_board.checkBoard() == 2 && !this->color){
        return false;
    }
    return true;

}