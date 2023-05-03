//Bishop class created by Christian Liechty

#include <algorithm>
#include "bishop.h"
#include "chessboard.h"

using namespace std;


Bishop::Bishop(BoardCell *cell, Color color): ChessPiece(cell, color){}


bool Bishop::isValidMove(BoardCell* target){

    //Check to see if the piece is still in play
    if(!isInplay()){
        return false;
    }

    //Check to see if target cell has chesspiece with the same color
    if(!target->isEmpty() && target->piece->hasSameColor(this)){
        return false;
    }

    //Define index for current Bishop piece
    int srcRowIndex = cell->rowIndex;
    int srcColIndex = cell->colIndex;

    //Define the source and destination boards
    int srcBoardIndex = this->cell->board->level;
    int dstBoardIndex = target->board->level;

    //Define index for destination cell
    int dstRowIndex = target->rowIndex;
    int dstColIndex = target->colIndex;

    //Define variables to store difference between source and target cell
    int vertDifference = dstRowIndex - srcRowIndex;
    int horizDifference = dstColIndex - srcColIndex;

    //If the absolute value of the horizontal and vertical distance is the same amount, the move is diagonal
    if(abs(vertDifference) != abs(horizDifference)){
        return false;
    }

    //If the move is purely horizontal or vertical, it is not valid
    if(srcRowIndex == dstRowIndex || srcColIndex == dstColIndex){
        return false;
    }

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

    //this condition will ensure that the Bishop cannot sit under/over pieces on different boards
    if((!mirrorCells[0]->isEmpty() && !mirrorCells[0]->hasPiece(this->color))
                || (!mirrorCells[1]->isEmpty() && !mirrorCells[1]->hasPiece(this->color))){

                return false;

            }

    //If the Bishop is moving between boards, the legal moves change
    if(srcBoardIndex != dstBoardIndex){
        int boardMove = abs(dstBoardIndex - srcBoardIndex);

        //if the Bishop moves one board level, it can move one cell away
        if (boardMove == 1){
            if(abs(vertDifference) > 1){
                return false;
            }
        }

        //if the Bishop moves two board levels, it can move two cells away
        else if(boardMove == 2){
            if(abs(vertDifference) > 2 || abs(vertDifference) < 2){
                return false;
            }
        }
    }

    //Check that the diagonal path is clear
    //If this condition passes the move is diagonal
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

bool Bishop::isValidAttack(BoardCell* target){
    return isValidMove(target);
}

