#include "../include/Piece.h"  // Include all necessary headers for your chess game classes
#include "../include/Board.h"
#include "../include/Square.h"
#include "../include/Bishop.h"
#include "../include/Knight.h"
#include "../include/Rook.h"
#include "../include/Queen.h"
#include "../include/King.h"
#include "../include/Pawn.h"

#include <iostream>
#include <string>
using namespace std;

int main(){

    Board *gameBoard = new Board();
    gameBoard->setBoard();

    if(gameBoard->getBoard()[1][0].getPiece().isMoveValid(2,0,*gameBoard)){
        cout << "Pawn Moved Forward 1 square\n";
    }

    return 0;
}
