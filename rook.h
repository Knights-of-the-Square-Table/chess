#ifndef ROOK_H
#define ROOK_H

#include "chesspiece.h"
#include "boardcell.h"

class Rook: public ChessPiece
{
    public:
    Rook(BoardCell* cell, Color color);

    char getNickName() {
        return color == WHITE ? 'R' : 'r';
    }

    bool isValidMove(BoardCell* target);

    int getPointValue(){
        return 5;
    }
};

#endif // ROOK_H
