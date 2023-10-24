#include "../include/Square.h"
#include "../include/Piece.h"
#include <string>
using namespace std;

Square :: Square() {
    empty = true;
    piece = NULL;
}

void Square :: setPiece(Piece &piece){
    this->piece = &piece;
    empty = false;
}

Piece& Square :: getPiece(){
    return *(this->piece);
}

bool Square :: isEmpty(){
    return empty;
}

void Square :: setEmpty(){
    empty = true;
}

string Square :: getPieceType(){
    if(piece == NULL){
        return "none";
    }
    return piece->getType();
}

void Square :: removePiece(){
    piece = NULL;
    return;
}