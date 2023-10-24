#ifndef SQUARE_H
#define SQUARE_H

#include <string>
class Piece;
using namespace std;

class Square{
    public: 
    Square();

        void setPiece(Piece &newPiece);

        Piece& getPiece();

        bool isEmpty();

        void setEmpty();

        string getPieceType();

        void removePiece();
    private:
        bool empty;
        Piece *piece;

};

#endif