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

    //Define the source and destination boards (1 or 2)
    int srcBoardIndex = cell->board->level;
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

    //If the Bishop tries to move more than 1 cell when moving between boards, the move is not valid
    if(srcBoardIndex != dstBoardIndex){
        if (abs(vertDifference) > 1){
            return false;
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
            BoardCell* d = target->board->getMirrorBoard()->getCell(srcRowIndex + (i*x), srcColIndex + (i*y));

            if(!c->isEmpty()){
                return false;
            }

            else if(!d->isEmpty()){
                return false;
            }

        }

    }

    //If all checks pass, the move is valid!
    return true;

}
