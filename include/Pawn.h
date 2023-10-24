#ifndef PAWN_H
#define PAWN_H

#include "Piece.h" 
#include <string>
using namespace std;

class Pawn : public Piece{
    public:

        Pawn(bool color, string type, int row, int col);

        bool isMoveValid(int row, int col, Board& board);
        
        bool isFirstMove();

    private: 

        bool firstMove;
        const int value;

};

#endif