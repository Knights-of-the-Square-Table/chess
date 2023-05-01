#ifndef KING_H
#define KING_H

#include "chesspiece.h"
#include "boardcell.h"
enum Color;
class ChessPiece;

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

    bool isInCheck();

    bool isInCheckMate();
};

#endif // KING_H
