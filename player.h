#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "color.h"
#include "chesspiece.h"

class Player
{
    public:
    Color color;
    std::vector<ChessPiece*> capturedPieces;

    Player(Color color);
    void addCapturedPiece(ChessPiece* piece);
    Color getColor();
    int getPoints();
};

#endif // PLAYER_H
