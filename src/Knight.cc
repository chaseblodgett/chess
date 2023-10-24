#include "../include/Knight.h"

Knight :: Knight(bool color,string type, int row , int col) : Piece(color, type , row, col), value(3){}

bool Knight :: isMoveValid(int row, int col, Board &board){
     // Out of bounds
    if (row < 0 || row >= 8 || col < 0 || col >= 8) {
        return false;
    }
    // If ending square has same color piece
    if(this->color == board.getBoard()[row][col].getPiece().getColor()){
        return false;
    }

    Board tmp_board = board;
    Knight tmp_piece = *this;
    tmp_board.makeMove(tmp_piece,row,col);

    if(tmp_board.checkBoard() == 1 && this->color){
        return false;
    }
    if(tmp_board.checkBoard() == 2 && !this->color){
        return false;
    }

    int rowDiff = abs(row - this->getRow());
    int colDiff = abs(col - this->getCol());

    if ((rowDiff == 1 && colDiff == 2) || (rowDiff == 2 && colDiff == 1)){
        return true;
    }

    return false;

}