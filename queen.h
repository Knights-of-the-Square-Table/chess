#ifndef QUEEN_H
#define QUEEN_H


#include "chesspiece.h"
#include "boardcell.h"

class Queen: public ChessPiece{
    public:
    Queen(BoardCell* cell, Color color);

    char getNickName() {
        return color == WHITE ? 'Q' : 'q';
    }

    bool isValidMove(BoardCell* target);

    int getPointValue(){
        return 9;
    }
};

#endif // QUEEN_H
