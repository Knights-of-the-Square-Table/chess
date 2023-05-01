#ifndef KNIGHT_H
#define KNIGHT_H


#include "chesspiece.h"
#include "boardcell.h"
#include "color.h"

class Knight : public ChessPiece
{

    public:
    Knight(BoardCell* cell, Color color);

    char getNickName() {
        return color == WHITE ? 'N' : 'n';
    }

    bool isValidMove(BoardCell* target);

    int getPointValue(){
        return 3;
    }

};

#endif // KNIGHT_H
