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
    int vertDifference = dstRowIndex - srcRowIndex;
    int horizDifference = dstColIndex - srcColIndex;

    //The distance of the King's move cannot be greater than 1
    if(vertDifference > 1 || horizDifference > 1){
        return false;
    }

    //Need to check if the King is in check or checkmate

    //If all other checks pass, the move is valid!
    return true;

}

bool King::isInCheck(){
    bool result = false;
    ChessBoard* brd = this->cell->board;


    //For all cells on the board that the king is on
    for(int i = 0; i < ROW_COUNT; i++){
        for(int j = 0; j < COL_COUNT; j++){
            if(!brd->cells[i][j]->isEmpty()){
                result = brd->cells[i][j]->getPiece()->isValidMove(this->cell);
                if(result == true){break;}
            }
        }
    }
    //for(int k = 0; k< )

    return result;
}
