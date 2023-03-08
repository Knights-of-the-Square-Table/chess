#include <iostream>
#include "chessgame.h"
#include "boardcell.h"

using namespace std;

void getUserInput(){
    //TODO: gets user input and return a list of coordinates to input into tryMove function
}

void tryMove(ChessGame* g, int r1, int c1, int r2, int c2){
    cout << "Move: (" << r1 << ',' << c1 << ") - (" << r2 << ',' << c2 << ")";

    BoardCell* srcCell = g->board->getCell(r1,c1);
    BoardCell* dstCell = g->board->getCell(r2,c2);

    bool validMove = srcCell->piece->isValidMove(dstCell);
    cout << " - " << (validMove ? "VALID" : "INVALID") << endl;

    if (validMove){
        srcCell->piece->move(dstCell);
        g->printBoard();
    }
}


int main(){
    cout << "CHESS GAME\n\n" << endl;

    ChessGame* g = new ChessGame();
    g->printBoard();

    tryMove( g, 0, 0, 1, 1);
    tryMove( g, 0, 0, 0, 0);

    tryMove( g, 0, 5, 3, 5);
    tryMove( g, 3, 5, 3, 0);
    tryMove( g, 0, 0, 5, 0);
    tryMove( g, 3, 0, 3, 1);

    tryMove( g, 0, 0, 5, 0);

    tryMove( g, 5, 5, 0, 5);
    tryMove( g, 0, 5, 0, 4);
    tryMove( g, 0, 4, 0, 3);
    tryMove( g, 0, 3, 0, 2);
    tryMove( g, 0, 2, 0, 1);

    return 0;
}
