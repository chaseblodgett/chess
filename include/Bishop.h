#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h" 
#include <string>
using namespace std;

class Bishop : public Piece{
    public:

        Bishop(bool color, string type, int row, int col);

        bool isMoveValid(int row, int col, Board& board); 
    
    private:

        const int value;

};

#endif