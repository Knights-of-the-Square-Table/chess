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
    std::vector<ChessPiece*> myPieces;

    Player(Color color);
    void addCapturedPiece(ChessPiece* piece);
    void addMyPiece(ChessPiece* piece);
    Color getColor();
    int getPoints();
    void resetScore();
};

#endif // PLAYER_H
