#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <string>
#include "boardcell.h"
#include "color.h"
#include "chessgame.h"

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
    virtual bool isInCheck() = 0;

    bool isInplay();
    void move(BoardCell* target);
    bool hasSameColor(ChessPiece* piece);
    void beCaptured();
    std::vector<BoardCell*> getMoves(ChessBoard* board);
    std::vector<int> getMovesInt(ChessBoard* board);

};

#endif // CHESSPIECE_H
