#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "Board.h"
using namespace std;

class Piece{
    public: 
        Piece(bool color, string type, int row , int col);

        ~Piece();

        virtual bool isMoveValid(int row, int col, Board& board) = 0;

        void makeMove(int row, int col, Board& board);

        bool getColor();

        int getRow();

        int getCol();

        void setRow(int row);

        void setColumn(int row);

        string getType();

    protected: 
        bool color;
        string type;
        int currentRow;
        int currentCol; 
};

#endif 