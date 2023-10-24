#ifndef ROOK_H
#define ROOK_H

#include "Piece.h" 
#include <string>
using namespace std;

class Rook : public Piece{
    public:

        Rook(bool color, string type, int row, int col);

        bool isMoveValid(int row, int col, Board& board); 

    private: 

        bool moved;
        const int value;
    
};

#endif