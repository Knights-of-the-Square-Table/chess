//Queen class - Christian Liechty

#include <algorithm>
#include "chessboard.h"
#include "queen.h"

using namespace std;

Queen::Queen(BoardCell* cell, Color color) : ChessPiece(cell, color){}

bool Queen::isValidMove(BoardCell* target){

    //Check to see if the piece is still in play
    if(!isInplay()){
        return false;
    }

    //Check to see if target cell has chesspiece with the same color
    if(!target->isEmpty() && target->piece->hasSameColor(this) ){
        return false;
    }

    //Define index for current Queen piece
    int srcRowIndex = cell->rowIndex;
    int srcColIndex = cell->colIndex;

    //Define index for destination cell
    int dstRowIndex = target->rowIndex;
    int dstColIndex = target->colIndex;

    //Define the source and destination boards
    int srcBoardIndex = this->cell->board->level;
    int dstBoardIndex = target->board->level;

    //Define variables to store difference between source and target cell
    int vertDifference = dstRowIndex - srcRowIndex;
    int horizDifference = dstColIndex - srcColIndex;

    //Create vector that holds the two cells mirroring the target cell
    std::vector<BoardCell*> mirrorCells = target->getMirrorCells(target->rowIndex, target->colIndex);

    // Check if the target cell has the chesspiece with the same color on every board
    if(!target->isEmpty() && target->piece->hasSameColor(this) ){
        //cout << "target cell empty or not";
        return false;
    }else if(!mirrorCells[0]->isEmpty() && mirrorCells[0]->piece->hasSameColor(this)){
        return false;
    }else if(!mirrorCells[1]->isEmpty() && mirrorCells[1]->piece->hasSameColor(this)){
        return false;
    }

    //Define the number of boards that are being traveled across
    int boardMove = abs(dstBoardIndex - srcBoardIndex);

    //Check to make sure the mirror of the target cell is clear on other boards
    if(boardMove == 0){
        if((!mirrorCells[0]->isEmpty() && !mirrorCells[0]->hasPiece(this->color))
                    || (!mirrorCells[1]->isEmpty() && !mirrorCells[1]->hasPiece(this->color))){

                    return false;

                }
    }

    //If the Queen is moving between boards, the legal moves change
    if(srcBoardIndex != dstBoardIndex){
        //the Queen can move directly up and down when moving between boards
        if((abs(dstColIndex - srcColIndex) == 0) && (abs(dstRowIndex - srcRowIndex) == 0)){
            return true;
        }

        //if the Queen moves one board level, it can move one cell away
        if(boardMove == 1){
            if(abs(vertDifference) > 1){
                return false;
            }

            else if(abs(horizDifference) > 1){
                return false;
            }

            //this condition will ensure that the Queen cannot sit between pieces on different boards
            if((!mirrorCells[0]->isEmpty() && !mirrorCells[0]->hasPiece(this->color))
                        || (!mirrorCells[1]->isEmpty() && !mirrorCells[1]->hasPiece(this->color))){

                        return false;

                    }

        }

        //if the Queen moves two board levels, it must move two cells away
        else if(boardMove == 2){
            if(abs(vertDifference) != 2 && abs(horizDifference) != 2){
                return false;
            }

        }

    }

    //Check to see if the move is diagonal, horizontal, or vertical
    if(abs(vertDifference) != abs(horizDifference) && srcRowIndex != dstRowIndex && srcColIndex != dstColIndex){
        return false;
    }

    // Check that the vertical path is clear
    if (srcColIndex == dstColIndex){
        int minRowIndex = min(srcRowIndex, dstRowIndex) + 1;
        int maxRowIndex = max(srcRowIndex, dstRowIndex) - 1;

        int ci = srcColIndex;
        for(int ri = minRowIndex; ri <= maxRowIndex; ri++){
            BoardCell* c =  target->board->getCell(ri, ci);
            std::vector<BoardCell*> mirrorCells = c->getMirrorCells(ri, ci);

            if(!c->isEmpty()){
                return false;
            }

            else if(!mirrorCells[0]->isEmpty()){
                return false;
            }

            else if(!mirrorCells[1]->isEmpty()){
                return false;
            }
        }
    }

    // Check that the horizontal path is clear
    if (srcRowIndex == dstRowIndex){
        int minColIndex = min(srcColIndex, dstColIndex) + 1;
        int maxColIndex = max(srcColIndex, dstColIndex) - 1;

        int ri = srcRowIndex;
        for(int ci = minColIndex; ci <= maxColIndex; ci++){
            BoardCell* c =  target->board->getCell(ri, ci);
            std::vector<BoardCell*> mirrorCells = c->getMirrorCells(ri, ci);

            if(!c->isEmpty()){
                return false;
            }

            else if(!mirrorCells[0]->isEmpty()){
                return false;
            }

            else if(!mirrorCells[1]->isEmpty()){
                return false;
            }
        }
    }

    //Check that the diagonal path is clear
    if(abs(vertDifference) == abs(horizDifference)){
        int moveLength = abs(vertDifference);

        //these values will be used to help check the diagonal pieces from src to dst
        int x = (dstRowIndex - srcRowIndex)/moveLength;
        int y = (dstColIndex - srcColIndex)/moveLength;

        //iterate through the diagonal pieces and make sure they are not occupied
        for(int i = 1; i < moveLength; i++){
            BoardCell* c = target->board->getCell(srcRowIndex + (i*x), srcColIndex + (i*y));
            std::vector<BoardCell*> mirrorCells = c->getMirrorCells(srcRowIndex + (i*x), srcColIndex + (i*y));

            if(!c->isEmpty()){
                return false;
            }

            else if(!mirrorCells[0]->isEmpty()){
                return false;
            }

            else if(!mirrorCells[1]->isEmpty()){
                return false;
            }

        }

    }

    //If all checks pass, the move is valid!
    return true;

}


bool Queen::isValidAttack(BoardCell* target){
    return isValidMove(target);
}


