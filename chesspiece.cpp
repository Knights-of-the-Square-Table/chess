#include "chesspiece.h"
#include "chessgame.h"

ChessPiece::ChessPiece(BoardCell* cell, Color color){
    this->cell = cell;
    this->color = color;
    cell->placePiece(this);
}


bool ChessPiece::isInplay(){
    return cell != NULL;
}

void ChessPiece::move(BoardCell* target){
    if( !isInplay() ){
        return;
    }
    cell->removePiece();


    if(!target->isEmpty()){
        target->piece->beCaptured();
    }
    target->placePiece(this);

    this->cell = target;
}

bool ChessPiece::hasSameColor(ChessPiece* piece){
    return color == piece->color;
}

//Liam
void ChessPiece::beCaptured(){
    this->cell->board->game->getCurrentPlayer()->addCapturedPiece(this);
    cell->removePiece();
    cell = NULL;
}

