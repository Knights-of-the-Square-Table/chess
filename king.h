#ifndef KING_H
#define KING_H

#include "chesspiece.h"
#include "boardcell.h"

class King: public ChessPiece{
    public:
    King(BoardCell* cell, Color color);

    char getNickName() {
        return color == WHITE ? 'K' : 'k';
    }


    bool isValidMove(BoardCell* target);
};

#endif // KING_H
