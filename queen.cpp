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

    //Define variables to store difference between source and target cell
    int vertDifference = dstRowIndex - srcRowIndex;
    int horizDifference = dstColIndex - srcColIndex;

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
            if(!c->isEmpty()){
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
            if(!c->isEmpty()){
                return false;
            }
        }
    }

    //Check that the diagonal path is clear
    if(srcColIndex != dstColIndex && srcRowIndex != dstRowIndex){
        int minRowIndex = min(srcRowIndex, dstRowIndex) + 1;
        int maxRowIndex = max(srcRowIndex, dstRowIndex) -1 ;

        int minColIndex = min(srcColIndex, dstColIndex) + 1;
        int maxColIndex = max(srcColIndex, srcColIndex) -1;

        for(int ri = minRowIndex; ri <= maxRowIndex; ri++){
            for(int ci = minColIndex; ci <= maxColIndex; ci++){
                BoardCell* c = target->board->getCell(ri, ci);
                if(!c->isEmpty()){
                    return false;
                }
            }
        }
    }

    //If all checks pass, the move is valid!
    return true;


}

