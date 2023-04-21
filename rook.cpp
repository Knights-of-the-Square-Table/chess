#include <algorithm>
#include "rook.h"
#include "chessboard.h"
#include <iostream>

using namespace std;

Rook::Rook(BoardCell* cell, Color color) : ChessPiece(cell, color) {
}

bool Rook::isValidMove(BoardCell* target)
{

    // Check if the piece is still in play
    if( !isInplay()){
        return false;
    }

    //check to see if the move is to different board
    if(isMoveToDiffBoard(target))
    {
        if(cell->board->level == MIDDLE && abs(target->rowIndex - cell->rowIndex) > 1)
        {
            return false;
        }
        else if(cell->board->level == MIDDLE && abs(target->colIndex - cell->colIndex) > 1)
        {
            return false;
        }
        else if((abs(target->colIndex - cell->colIndex) == 0) && (abs(target->rowIndex - cell->rowIndex) == 0)){
            return true;
        }
        else if(cell->board->level != MIDDLE && abs(target->rowIndex - cell->rowIndex) > 2)
        {
            return false;
        }
        else if(cell->board->level != MIDDLE && abs(target->colIndex - cell->colIndex) > 2)
        {
            return false;
        }
        else {
            return true;
        }
    }

    // Check if the target cell has the chesspiece with the same color
    if(!target->isEmpty() && target->piece->hasSameColor(this) ){
        return false;
    }

    //check mirror board to see if target cell has piece on it
    if(!target->getMirrorCell(target->rowIndex, target->colIndex)->isEmpty())
    {
        return false;
    }




    if(!this->isPathClear(target))
    {
            return false;
    }


    bool clear = this->isPathClear(target);
    cout << &clear << endl;




   return true;
}

bool Rook::isPathClear(BoardCell *target)
{
    int srcRowIndex = cell->rowIndex;
    int srcColIndex = cell->colIndex;

    int dstRowIndex = target->rowIndex;
    int dstColIndex = target->colIndex;


    // Check if source and target are either on the same column or on the same row
    if ( srcRowIndex != dstRowIndex && srcColIndex != dstColIndex){
        return false;
    }




    //
    // Case 1 - vertical: both soruce and target have the same column index
    // - - - - - -
    // - S - - - -
    // - * - - - -
    // - * - - - -
    // - T - - - -
    // - - - - - -


   if(srcColIndex == dstColIndex){
        int minRowIndex = min(srcRowIndex, dstRowIndex) + 1;
        int maxRowIndex = max(srcRowIndex, dstRowIndex) - 1;

        int ci = srcColIndex;
        for(int ri = minRowIndex; ri <= maxRowIndex; ri++){
            BoardCell* c =  target->board->getCell(ri, ci);
            BoardCell* mirrorC = target->getMirrorCell(ri, ci);
            if(!c->isEmpty()){
                return false;
            }
            else if(!mirrorC->isEmpty()){
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
    if(srcRowIndex == dstRowIndex){
        int minColIndex = min(srcColIndex, dstColIndex) + 1;
        int maxColIndex = max(srcColIndex, dstColIndex) - 1;

        int ri = srcRowIndex;
        for(int ci = minColIndex; ci <= maxColIndex; ci++){
            BoardCell* c =  target->board->getCell(ri, ci);
            BoardCell* mirrorC = target->getMirrorCell(ri, ci);
            if(!c->isEmpty()){
                return false;
            }
            else if(!mirrorC->isEmpty()){
                return false;
            }
        }
    }

    return true;

}

bool Rook::isMoveToDiffBoard(BoardCell *target)
{
    if (this->cell->board->level == target->board->level)
    {
        cout << "same board";
        return false;
    }
    else{
        return true;
    }
}



//maltese falcom
