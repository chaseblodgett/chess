#include "Piece.h"
#include <string>
using namespace std;

class Knight : public Piece{
    public:

        Knight(bool color, string type, int row, int col);

        bool isMoveValid(int row, int col, Board& board); 
    
    private:    
        const int value;

};