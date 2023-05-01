#ifndef PAWN_H
#define PAWN_H

#include "chesspiece.h"
#include "boardcell.h"



class Pawn: public ChessPiece{

public:
    Pawn(BoardCell* cell, Color color);

    char getNickName() {
        return color == WHITE ? 'P' : 'p';
    }

    bool isValidMove(BoardCell* target);

    int getPointValue(){
        return 1;
    }

    bool isInCheck();
    bool pathClearDblMove();
    bool isValidAttack(BoardCell* target);
    bool isValidForward(BoardCell* target);
};

#endif // PAWN_H
