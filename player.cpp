#include "player.h"
#include <iostream>

using namespace std;

Player::Player(Color color){
    this->color = color;
}

// Liam
void Player::addCapturedPiece(ChessPiece* piece){
    capturedPieces.push_back(piece);
}

void Player::addMyPiece(ChessPiece* piece){
    myPieces.push_back(piece);
}

Color Player::getColor(){
    return color;
}

// Liam - returns the point value of the piece
int Player::getPoints(){
    int total= 0;
    if (int(capturedPieces.size()) == 0){
        total=0;
    }
    else{
        for(int i=0; i<int(capturedPieces.size()); i++){
            total += capturedPieces[i]->getPointValue();
        }
    }
    return total;
}

//Chris
void Player::resetScore()
{
    capturedPieces.clear();
}
