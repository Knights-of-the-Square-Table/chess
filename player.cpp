#include "player.h"
#include <iostream>

using namespace std;

Player::Player(Color color){
    this->color = color;
}

void Player::addCapturedPiece(ChessPiece* piece){
    cout << capturedPieces.size() << endl;
    capturedPieces.push_back(piece);
    cout << capturedPieces.size() << endl;
    cout << "piece added to player's captured pieces" << endl;
}
