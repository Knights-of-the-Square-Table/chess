#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "color.h"
#include "chesspiece.h"

class ChessPiece;
class Player
{
    public:
    Color color;
    std::vector<ChessPiece*> capturedPieces;

    Player(Color color);
    void addCapturedPiece(ChessPiece* piece);
};

#endif // PLAYER_H
