#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include "Square.h"
using namespace std;

class Board{
    public: 

        Board();

        // ~Board();

        void setBoard();

        bool inBounds(int i, int j);

        bool lookForKing(string type, int i, int j);

        bool lookForBishop(string type, int i, int j);

        bool lookForRook(string type, int i, int j);

        bool lookForQueen(string type, int i, int j);

        bool lookForKnight(string type, int i, int j);

        bool lookForPawn(int i, int j, bool color);

        vector< vector< Square> > getBoard();

        void makeMove(Piece &piece, int row, int col);

        int checkBoard();

        bool isEnpassantValid();

        void setEnpassant(bool val);

        int getEnpassantCol();

        void setEnpassantCol(int col);

    private:

        vector<vector< Square> > Squares;
        bool whiteChecked;
        bool blackChecked;
        bool whiteMove;
        bool checkmate;
        bool draw;
        bool enPassantAble;
        int enPassantCol;
        int whiteScore;
        int blackScore;
};

#endif