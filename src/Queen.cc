#include "../include/Queen.h"

Queen :: Queen(bool color, string type, int row, int col) : Piece(color,type,row,col), value(9){
}

bool Queen :: isMoveValid(int row, int col, Board &board){
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

    // A Queen can move either like a Rook (horizontally or vertically) or like a Bishop (diagonally)
    if ((rowDiff == 0 && colDiff != 0) || (rowDiff != 0 && colDiff == 0) || (rowDiff == colDiff)) {
        // Check if there are any pieces blocking the path if the move is like a Rook
        if (rowDiff == 0) {
            int directionCol = (col > currentCol) ? 1 : -1;
            for (int c = currentCol + directionCol; c != col; c += directionCol) {
                if (!board.getBoard()[row][c].isEmpty()) {
                    return false;  // There is a piece in the path
                }
            }
        } else if (colDiff == 0) {
            int directionRow = (row > currentRow) ? 1 : -1;
            for (int r = currentRow + directionRow; r != row; r += directionRow) {
                if (!board.getBoard()[r][col].isEmpty()) {
                    return false;  // There is a piece in the path
                }
            }
        }
        
        // Check if there are any pieces blocking the path if the move is like a Bishop
        if (rowDiff == colDiff) {
            int directionRow = (row > currentRow) ? 1 : -1;
            int directionCol = (col > currentCol) ? 1 : -1;
            for (int r = currentRow + directionRow, c = currentCol + directionCol;
                 r != row;
                 r += directionRow, c += directionCol) {
                if (!board.getBoard()[r][c].isEmpty()) {
                    return false;  // There is a piece in the path
                }
            }
        }
    }

    Board tmp_board = board;
    Queen tmp_piece = *this;
    tmp_board.makeMove(tmp_piece,row,col);

    if(tmp_board.checkBoard() == 1 && this->color){
        return false;
    }
    if(tmp_board.checkBoard() == 2 && !this->color){
        return false;
    }

    return true;
}