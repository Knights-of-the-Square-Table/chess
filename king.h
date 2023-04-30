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

    int getPointValue(){
        return 100;
    }

    bool isValidAttack(BoardCell* target);
    bool isInCheck();

    bool isInCheck(BoardCell* mockTarget);
};

#endif // KING_H
