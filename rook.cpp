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

//    ChessBoard *middleB = NULL;
//    ChessBoard *topB = NULL;
//    ChessBoard *bottomB = NULL;
//    BoardCell *middleCell = NULL;
//    BoardCell *topCell = NULL;
//    BoardCell *bottomCell = NULL;
//    if(target->board->level == MIDDLE){
//        middleB = target->board->getMidBoard();
//        topCell = target->board->getCell(target->rowIndex, target->colIndex);
//        bottomCell = target->board->getCell(target->rowIndex, target->colIndex);
//    }

//    else if(target->board->level == TOP){
//        topB = target->board->getTopBoard();
//        middleCell = target->board->getCell(target->rowIndex, target->colIndex);
//        bottomCell = target->board->getCell(target->rowIndex, target->colIndex);
//    }
//    else if(target->board->level == BOTTOM){
//        bottomB = target->board->getBotBoard();
//        topCell = target->board->getCell(target->rowIndex, target->colIndex);
//        middleCell = target->board->getCell(target->rowIndex, target->colIndex);

//    }

//    //check to see if the move is to different board
//    if(isMoveToDiffBoard(target))
//    {
//        if(middleB && abs(target->rowIndex - cell->rowIndex) > 1)
//        {
//            return false;
//        }
//        else if(middleB && abs(target->colIndex - cell->colIndex) > 1)
//        {
//            return false;
//        }
//        else if((abs(target->colIndex - cell->colIndex) == 0) && (abs(target->rowIndex - cell->rowIndex) == 0)){
//            return true;
//        }
//        else if(!middleB && abs(target->rowIndex - cell->rowIndex) > 2)
//        {
//            return false;
//        }
//        else if(!middleB && abs(target->colIndex - cell->colIndex) > 2)
//        {
//            return false;
//        }
//        else {
//            return true;
//        }
//    }

//    // Check if the target cell has the chesspiece with the same color
//    if(!target->isEmpty() && target->piece->hasSameColor(this) ){
//        return false;
//    }

//    if(topB && !middleCell->isEmpty()
//            && !bottomCell->isEmpty()
//            && middleCell->piece->hasSameColor(this)
//            && bottomCell->piece->hasSameColor(this)){
//        return false;
//    }

//    if(middleB && !topCell->isEmpty()
//            && !bottomCell->isEmpty()
//            && topCell->piece->hasSameColor(this)
//            && bottomCell->piece->hasSameColor(this)){
//        return false;
//    }

//    if(bottomB && !middleCell->isEmpty()
//            && !topCell->isEmpty()
//            && middleCell->piece->hasSameColor(this)
//            && topCell->piece->hasSameColor(this)){
//        return false;
//    }

    int srcRowIndex = cell->rowIndex;
    int srcColIndex = cell->colIndex;
    int dstRowIndex = target->rowIndex;
    int dstColIndex = target->colIndex;

    int srcBoardIndex = cell->board->level;
    int dstBoardIndex = target->board->level;

    int rowDistance = abs(srcRowIndex - dstRowIndex);
    int colDistance = abs(srcColIndex - dstColIndex);
    int boardDistance = abs(srcBoardIndex - dstBoardIndex);

    //check to see if the move is to different board
    if(boardDistance > 0)
    {
        if(boardDistance == 1){
            if(rowDistance > 1 || colDistance > 1){
                return false;
            }
        }
        if(boardDistance == 2){
            if((rowDistance > 2 || rowDistance < 2 )|| colDistance > 2){
                return false;
            }
        }
    }

    cout << "got here!";

    std::vector<BoardCell*> mirrorCells = target->getMirrorCells(target->rowIndex, target->colIndex);


    // Check if the target cell has the chesspiece with the same color
    if(!target->isEmpty() && target->piece->hasSameColor(this) ){
        cout << "target cell empty or not";
        return false;
    }else if(!mirrorCells[0]->isEmpty() && mirrorCells[0]->piece->hasSameColor(this)){
        return false;
    }else if(!mirrorCells[1]->isEmpty() && mirrorCells[1]->piece->hasSameColor(this)){
        return false;
    }


    if(boardDistance == 0) {
        if((!mirrorCells[0]->isEmpty() && !mirrorCells[0]->hasPiece(this->color))
            || (!mirrorCells[1]->isEmpty() && !mirrorCells[1]->hasPiece(this->color))){

            return false;

        }

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
            std::vector<BoardCell*> mc = c->getMirrorCells(ri, ci);
//            BoardCell* mirrorC = target->getMirrorCell(ri, ci);
            if(!c->isEmpty()){
                return false;
            }
            else if(!mc[0]->isEmpty()){
                return false;
            }
            else if(!mc[1]->isEmpty()){
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
             std::vector<BoardCell*> mc = c->getMirrorCells(ri, ci);

//            BoardCell* mirrorC = target->getMirrorCell(ri, ci);
            if(!c->isEmpty()){
                return false;
            }
            else if(!mc[0]->isEmpty()){
                return false;
            }
            else if(!mc[1]->isEmpty()){
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

bool Rook::isValidAttack(BoardCell* target){
    return isValidMove(target);
}

bool Rook::isInCheck(){
    return false;
}


//maltese falcom
