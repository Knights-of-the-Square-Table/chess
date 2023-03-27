#include "boardcell.h"
#include <iostream>

using namespace std;

BoardCell::BoardCell(ChessBoard* board, int rowIndex, int colIndex){
    this->board = board;
    this->rowIndex = rowIndex;
    this->colIndex = colIndex;
    this->piece = NULL;
}

bool BoardCell::isEmpty(){
    return piece == NULL;
}

void BoardCell::removePiece(){
    piece = NULL;
}

void BoardCell::placePiece(ChessPiece* piece){
    this->piece = piece;
}

bool BoardCell::hasPiece(Color color){
    return !isEmpty() && piece->color == color;
}

ChessPiece *BoardCell::getPiece()
{
    return this->piece;
}


