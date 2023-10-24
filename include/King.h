#ifndef KING_H
#define KING_H

#include "Piece.h" 
#include <string>
using namespace std;

class King : public Piece{
    public:

        King(bool color, string type, int row, int col);

        bool isMoveValid(int row, int col, Board& board); 

    private:

        bool moved;
        bool underCheck;

};

#endif
