#ifndef CHESSBOARD_H
#define CHESSBOARD_H

//#include "boardcell.h"
#include "level.h"
//#include "chessgame.h"
#include <iostream>


const int ROW_COUNT = 8;
const int COL_COUNT = 8;

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
    ChessBoard* getTopBoard();
    ChessBoard* getBotBoard();
    ChessBoard* getMidBoard();
    std::string printBoardLevel(Level level);

};

#endif // CHESSBOARD_H
