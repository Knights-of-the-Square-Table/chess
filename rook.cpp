#include <algorithm>
#include "rook.h"
#include "chessboard.h"

using namespace std;

Rook::Rook(BoardCell* cell, Color color) : ChessPiece(cell, color) {
}

bool Rook::isValidMove(BoardCell* target){

    // Check if the figure is still in play
    if( !isInplay()){
        return false;
    }

    // Check if the target cell has the chesspiece with the same color
    if(!target->isEmpty() && target->piece->hasSameColor(this) ){
        return false;
    }


    int srcRowIndex = cell->rowIndex;
    int srcColIndex = cell->colIndex;

    int dstRowIndex = target->rowIndex;
    int dstColIndex = target->colIndex;

    // Check if source and target are either on the same column or on the same row
    if ( srcRowIndex != dstRowIndex && srcColIndex != dstColIndex){
        return false;
    }


    // Case 1 - vertical: both soruce and target have the same column index
    // - - - - - -
    // - S - - - -
    // - * - - - -
    // - * - - - -
    // - T - - - -
    // - - - - - -

    // Check that all cells between(!) source and target cells are empty
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

    // Case 2 - horizontal: both soruce and target have the same row index
    // - - - - - -
    // - S * * T -
    // - - - - - -
    // - - - - - -
    // - - - - - -
    // - - - - - -

    // Check that all cells between(!) source and target cells are empty
    if (srcColIndex == dstColIndex){
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

    return true;
}
