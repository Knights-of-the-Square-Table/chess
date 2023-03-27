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

    //Define index for destination cell
    int dstRowIndex = target->rowIndex;
    int dstColIndex = target->colIndex;

    //Define variables to store difference between source and target cell
    int vertDifference = srcRowIndex - dstRowIndex;
    int horizDifference = srcColIndex - dstColIndex;

    //If the absolute value of the horizontal and vertical distance is the same amount, the move is diagonal
    if(abs(vertDifference) != abs(horizDifference)){
        return false;
    }

    //If the move is purely horizontal or vertical, it is not valid
    if(srcRowIndex == dstRowIndex || srcColIndex == dstColIndex){
        return false;
    }

    //Check that the diagonal path is clear
    if(srcColIndex != dstColIndex && srcRowIndex != dstRowIndex){
        int minRowIndex = min(srcRowIndex, dstRowIndex) + 1;
        int maxRowIndex = max(srcRowIndex, dstRowIndex) -1 ;

        int minColIndex = min(srcColIndex, dstColIndex) + 1;
        int maxColIndex = max(srcColIndex, dstColIndex) -1;

        //int ci = srcColIndex;
        //int ri = srcRowIndex;

        for(int ri = minRowIndex, ci = minColIndex; ri <= maxRowIndex; ri++, ci++){
            BoardCell* c = target->board->getCell(ri, ci);
            if(!c->isEmpty()){
                return false;
            }
        }

//        for(int ri = minRowIndex; ri <= maxRowIndex; ri++){
//            for(int ci = minColIndex; ci <= maxColIndex; ci++){
//                BoardCell* c = target->board->getCell(ri, ci);
//                if(!c->isEmpty()){
//                    return false;
//                }
//            }
//        }
    }

    //If all checks pass, the move is valid!
    return true;

}
