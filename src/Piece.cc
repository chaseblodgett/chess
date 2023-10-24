#include "../include/Piece.h"

Piece :: Piece(bool color, string type, int row, int col){
    this->color = color;
    this->type = type;
    currentRow = row;
    currentCol = col;
}

Piece :: ~Piece(){};

bool Piece:: getColor(){
    return color;
}

int Piece::getRow(){
    return currentRow;
}

int Piece::getCol(){
    return currentCol;
}

void Piece::setRow(int row){
    currentRow = row;
}

void Piece::setColumn(int col){
    currentCol = col;
}

string Piece :: getType(){
    return type;
}
