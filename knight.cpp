//Knight class created by Christian Liechty

#include <algorithm>
#include "color.h"
#include "knight.h"
#include "chessboard.h"
#include <iostream>

using namespace std;

Knight::Knight(BoardCell *cell, Color color): ChessPiece(cell, color){}


bool Knight::isValidMove(BoardCell* target){

    //Check to see if the piece is still in play
    if(!isInplay()){
        return false;
    }

    //Check to see if target cell has chesspiece with the same color
    if(!target->isEmpty() && target->piece->hasSameColor(this)){
        return false;
    }

    //Define index for current Knight piece
    int srcRowIndex = cell->rowIndex;
    int srcColIndex = cell->colIndex;

    //Define index for destination cell
    int dstRowIndex = target->rowIndex;
    int dstColIndex = target->colIndex;

    //Define the source and destination boards
    int srcBoardIndex = this->cell->board->level;
    int dstBoardIndex = target->board->level;

    //Define variables to store difference between source and target cell
    int vertDifference = abs(dstRowIndex - srcRowIndex);
    int horizDifference = abs(dstColIndex - srcColIndex);

    //Move validation for Knight
    if(vertDifference == 2 && horizDifference != 1){
        return false;
    }

    //Move validation for Knight
    if(horizDifference == 2 && vertDifference != 1){
        return false;
    }

    //Move validation for Knight
    if(horizDifference > 2 || vertDifference > 2){
        return false;
    }

    //Create vector that holds the two cells mirroring the target cell
    std::vector<BoardCell*> mirrorCells = target->getMirrorCells(target->rowIndex, target->colIndex);

    // Check if the target cell has the chesspiece with the same color
    if(!target->isEmpty() && target->piece->hasSameColor(this) ){
        return false;
    }else if(!mirrorCells[0]->isEmpty() && mirrorCells[0]->piece->hasSameColor(this)){
        return false;
    }else if(!mirrorCells[1]->isEmpty() && mirrorCells[1]->piece->hasSameColor(this)){
        return false;
    }

    //this condition will ensure that the Knight cannot sit over/under pieces on different boards
    if((!mirrorCells[0]->isEmpty() && !mirrorCells[0]->hasPiece(this->color))
                || (!mirrorCells[1]->isEmpty() && !mirrorCells[1]->hasPiece(this->color))){

                return false;

            }


   //If the Knight is moving between boards, the legal moves change
    if(srcBoardIndex != dstBoardIndex){
        int boardMove = abs(dstBoardIndex - srcBoardIndex);

        //if the Knight moves one board level, it can move two cells horizontal or vertical
        if(boardMove == 1){
            if(vertDifference != 2){
                return false;
            }

            else if(horizDifference != 2){
                return false;
            }

            //checks to make sure the move is not diagonal
            else if(vertDifference == horizDifference){
                return false;
            }
        }

        else if(boardMove == 2){
            if(vertDifference != 1){
                return false;
            }

            else if(horizDifference != 1){
                return false;
            }

            //checks to make sure the move is not diagonal
            else if(vertDifference == horizDifference){
                return false;
            }
        }

    }


    //If all checks pass, the move is valid!
    return true;
}

bool Knight::isValidAttack(BoardCell* target){
    return isValidMove(target);
}

bool Knight::isInCheck(){
    return false;
}
