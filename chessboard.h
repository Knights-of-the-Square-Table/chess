#ifndef CHESSBOARD_H
#define CHESSBOARD_H

//#include "boardcell.h"
#include "level.h"
//#include "chessgame.h"

const int ROW_COUNT = 6;
const int COL_COUNT = 6;

class BoardCell;
class ChessGame;

class ChessBoard
{
    public:
    BoardCell* cells[ROW_COUNT][COL_COUNT];

    ChessGame* game;

    ChessBoard(ChessGame* game, Level level);

    BoardCell* getCell(int rowIndex, int colIndex);
    void print();
    Level level;
    ChessBoard* getMirrorBoard();



};

#endif // CHESSBOARD_H
