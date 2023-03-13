#ifndef CHESSBOARD_H
#define CHESSBOARD_H

//#include "boardcell.h"

const int ROW_COUNT = 6;
const int COL_COUNT = 6;

class BoardCell;

class ChessBoard
{
    public:
    BoardCell* cells[ROW_COUNT][COL_COUNT];

    ChessBoard();
    BoardCell* getCell(int rowIndex, int colIndex);
    void print();

};

#endif // CHESSBOARD_H
