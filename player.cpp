#include "player.h"

Player::Player(Color color){
    this->color = color;
}

void Player::addCapturedPiece(ChessPiece* piece){
    capturedPieces.push_back(piece);
}
