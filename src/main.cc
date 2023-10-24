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

    // gameBoard->getBoard()[0][0].getPiece().isMoveValid(1, 0, *gameBoard);

    cout << gameBoard->getBoard()[0][1].getPieceType() << endl;
    cout << gameBoard->getBoard()[2][0].getPieceType() << endl;
    cout << gameBoard->getBoard()[0][2].getPieceType() << endl;

    // cout << "1" << endl;
    // cout << gameBoard->lookForKing("black-king", 0 , 4) << endl;
    //  cout << "2" << endl;
    // cout << gameBoard->lookForRook("black-rook", 0, 4) << endl;
    //  cout << "3\n";
    // cout << gameBoard->lookForQueen("black-queen", 0, 4) << endl;
    //  cout << "4\n";
    // cout << gameBoard->lookForKnight("black-knight", 0, 4) << endl;
    //  cout << "5\n";
    // cout << gameBoard->lookForPawn(0, 4, true) << endl;
    //  cout << "6\n";
    // cout << gameBoard->lookForBishop("black-bishop", 0 , 4);
    //  cout << "7\n";
    // cout <<  gameBoard->checkBoard() << endl;
    // cout << "8\n";

    if(!gameBoard->getBoard()[0][1].getPiece().isMoveValid(2,0,*gameBoard)){
        cout << "invalid move";
    }
    else{
        cout << "valid move\n";
    }

    delete gameBoard;
    return 0;
}
