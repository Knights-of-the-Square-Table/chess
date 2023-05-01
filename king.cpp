//King class - Christian Liechty

#include <iostream>
#include <algorithm>
#include "king.h"
#include "chessboard.h"

using namespace std;

King::King(BoardCell* cell, Color color) : ChessPiece(cell, color){}


bool King::isValidMove(BoardCell* target) {

    //Check to see if the piece is still in play
    if(!isInplay()){
        return false;
    }

    //Check to see if target cell has chesspiece with the same color
    if(!target->isEmpty() && target->piece->hasSameColor(this)){
        return false;
    }

    //Define index for current King piece
    int srcRowIndex = cell->rowIndex;
    int srcColIndex = cell->colIndex;

    //Define index for destination cell
    int dstRowIndex = target->rowIndex;
    int dstColIndex = target->colIndex;

    //Define variables to store difference between source and target cell
    int vertDifference = abs(dstRowIndex - srcRowIndex);
    int horizDifference = abs(dstColIndex - srcColIndex);

    //Define the source and destination boards
    int srcBoardIndex = this->cell->board->level;
    int dstBoardIndex = target->board->level;

    //Define the number of boards that are being traveled across
    int boardMove = abs(dstBoardIndex - srcBoardIndex);

    if(boardMove > 1){
        return false;
    }

    //The distance of the King's move cannot be greater than 1
    if(vertDifference > 1 || horizDifference > 1){
        return false;
    }

    //The King can move directly up and down the boards as long as the prior conditions pass
    if((abs(dstColIndex - srcColIndex) == 0) && (abs(dstRowIndex - srcRowIndex) == 0)){
        return true;
    }

    //Define vector hold mirror cells of the target
    std::vector<BoardCell*> mirrorCells = target->getMirrorCells(target->rowIndex, target->colIndex);

    //Check the other boards to make sure a cell is not occupied
    if(!target->isEmpty() && target->piece->hasSameColor(this) ){
        return false;
    }else if(!mirrorCells[0]->isEmpty() && mirrorCells[0]->piece->hasSameColor(this)){
        return false;
    }else if(!mirrorCells[1]->isEmpty() && mirrorCells[1]->piece->hasSameColor(this)){
        return false;
    }

    //If all other checks pass, the move is valid!
    return true;

}



//Goal: at every turn in a game, if the king is in check,
//the move has to get the king out of check,
//if no move possible to get out of check, end of game other player wins

//how to check if king is in check at beginning of turn:
//go through all the opponents pieces and see if move from piece to the king is a valid one
//if it is, then the king is in check

//if king is in check, go through all your pieces and possible moves for those pieces
//and "pretend" to move them to that spot,
//then once again search the
//Olga - returns true if the king is in check
bool King::isInCheck(){
    std::vector<ChessPiece*> opponentPieces = this->getOpponentPieces();
    int size = opponentPieces.size();
    for(int i = 0; i < size; i++){
        ChessPiece* p = opponentPieces.at(i);
        if(p->isValidMove(this->cell)){
            cout << "KING IS IN CHECK";

            return true;
        }
    }
    return false;
}

//Olga - returns true if the king is in checkmate
bool King::isInCheckMate(){
    if(!this->isInCheck()){
        return false;
    }
    //iterate through all my pieces and try to do temp move by each of my pieces
    //and check to see if the king is still in check
    std::vector<ChessPiece*> myPieces = this->getMyPieces();

    for(int i = 0; i < myPieces.size(); i++){
        ChessPiece* p = myPieces.at(i);
        std::vector<BoardCell*> validMoves = p->getAllMoves();
        for(int j=0; j < validMoves.size(); j++){
            p->tempMove(validMoves.at(j));
            bool isCheck = this->isInCheck();
            p->undoTempMove();

            if(!isCheck){
                return false;
            }
        }
    }
    return true;
}


