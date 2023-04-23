#ifndef BISHOP_H
#define BISHOP_H


#include "chesspiece.h"
#include "boardcell.h"


class Bishop : public ChessPiece
{
    public:
    Bishop(BoardCell* cell, Color color);

    char getNickName() {
        return color == WHITE ? 'B' : 'b';
    }

    bool isValidMove(BoardCell* target);

    int getPointValue(){
        return 3;
    }

    bool isInCheck();
};
#endif // BISHOP_H
