#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h" 
#include <string>
using namespace std;

class Queen : public Piece{
    public:

        Queen(bool color, string type, int row, int col);

        bool isMoveValid(int row, int col, Board& board);

    private:
        const int value;
};

#endif