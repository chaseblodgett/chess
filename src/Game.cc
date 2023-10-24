#include "../include/Game.h"
#include <string>
#include <iostream>
using namespace std;

Game :: Game(){
    board = new Board();
    checkmate = false;
    draw = false;
    whiteChecked = false;
    blackChecked = false;
    whiteMove = true;
}

void Game :: start(){
    // Ready to play?
    // White goes first, black goes second

    board.SetBoard();
    int currRow, currCol, newRow, newCol;
  
    cout << "       WELCOME TO CHESS GAME\n";
    cout << "============================================================\n";
    while(!checkmate && !draw){
        cout << "WHITE TO MOVE \n";
        cout << "Enter row and column number of piece to move, followed by row and column number of new square\n";
        cin >> currRow;
        cin >> currCol;
        cin >> newRow;
        cin >> newCol;
        // if white move
            // get index of board piece and index of new square to go to
            // validate input ( i.e 0 <= nums <= 7)
            // initial square = Board.Squares [start][start] and newSquare = Board.Squares [start][start]
                // cases (not valid)

                // initial is empty
                // start piece is same color as end piece
                // if check and doesnt block check or move king
                // if piece cannot physically move to new square
    }
}