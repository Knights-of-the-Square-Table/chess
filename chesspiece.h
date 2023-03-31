#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <string>
#include "boardcell.h"
#include "color.h"

class BoardCell;
class ChessGame;

class ChessPiece{

    public:
    BoardCell* cell;
    Color color;
    ChessPiece(BoardCell* cell, Color color);

    virtual bool isValidMove(BoardCell* target) = 0;
    virtual char getNickName() = 0;
    virtual int getPointValue() = 0;

    bool isInplay();
    void move(BoardCell* target);
    bool hasSameColor(ChessPiece* piece);
    void beCaptured();
};

#endif // CHESSPIECE_H
