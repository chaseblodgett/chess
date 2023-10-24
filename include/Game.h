#include <string>
#include "Piece.h"
#include "Board.h"
using namespace std;

class Game{

    public:

        Game();

        void Start();
    
    private:

        Board board;
        Player white;
        Player black;

};