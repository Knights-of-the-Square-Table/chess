//King class - Christian Liechty

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

//Checks all pieces on each board and see's if any of them are attacking the king -Liam
bool King::isInCheck(){

    ChessBoard* boards [3] = {this->cell->board->game->topBoard, this->cell->board->game->botBoard, this->cell->board->game->midBoard};
    for(int k = 0; k < 3; k++){
        for(int i = 0; i < ROW_COUNT; i++){
            for(int j = 0; j < COL_COUNT; j++){
                if(!(boards[k]->cells[i][j]->isEmpty()) && !(boards[k]->cells[i][j]->getPiece()->color == this->color)){
                    if(boards[k]->cells[i][j]->getPiece()->isValidMove(this->cell)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool King::isValidAttack(BoardCell* target){
    return false;
}
