#ifndef KNIGHT_H
#define KNIGHT_H


#include "chesspiece.h"
#include "boardcell.h"

class Knight : public ChessPiece
{

    public:
    Knight(BoardCell* cell, Color color);

    char getNickName() {
        return color == WHITE ? 'K' : 'k';
    }

    bool isValidMove(BoardCell* target);

    bool isValidAttack(BoardCell* target);

    int getPointValue(){
        return 3;
    }

    bool isInCheck();
};

#endif // KNIGHT_H
