#include "pawn.h"

using namespace std;

Pawn::Pawn(BoardCell* cell, Color color) : ChessPiece(cell, color){}

    //Liam
    bool Pawn::isValidMove(BoardCell* target){
        if(isValidAttack(target) || isValidForward(target)){
            return true;
        }
        return false;
    }

    // Liam
    bool Pawn::isInCheck(){
        return false;
    }

    // Liam
    bool Pawn::isValidForward(BoardCell* target){
        //Define index for current pawn
        int srcRowIndex = cell->rowIndex;
        int srcColIndex = cell->colIndex;

        //Define index for destination cell
        int dstRowIndex = target->rowIndex;
        int dstColIndex = target->colIndex;


        //Define the source and destination boards
        int srcBoardIndex = this->cell->board->level;
        int dstBoardIndex = target->board->level;

        //Check to see if the piece is still in play
        if(!isInplay()){return false;}

        //Check to see if target cell is occupied
        if(!target->isEmpty()){return false;}

        //Check to see if pawn is trying to move past more than 1 board
        if(abs(dstBoardIndex - srcBoardIndex) > 1){return false;}

        //moving straight up/down
        if((srcRowIndex == dstRowIndex) && (srcColIndex == dstColIndex) && ((srcBoardIndex + 1 == dstBoardIndex) || (srcBoardIndex - 1 == dstBoardIndex))){
            return true;
        }

        if (this->color == WHITE){
            if(srcRowIndex == ROW_COUNT-1 && srcBoardIndex == 0){return false;} //If piece is at the end of the board (White side)

            if((this->hasMoved == false) && (srcRowIndex + 1 == dstRowIndex || srcRowIndex + 2 == dstRowIndex) && (srcColIndex == dstColIndex)){
                this->hasMoved = true;
                return true;
            }

            if((this->hasMoved == true) && (srcRowIndex + 1 == dstRowIndex)){
                return true;
            }
        }

        else if(this->color == BLACK){ //
            if(srcRowIndex == ROW_COUNT-1 && srcBoardIndex == 2){return false;} //If piece is at the end of the board

            if((this->hasMoved == false) && (srcRowIndex - 1 == dstRowIndex || srcRowIndex - 2 == dstRowIndex) && (srcColIndex == dstColIndex)){
                this->hasMoved = true;
                return true;
            }

            if((this->hasMoved == true) && (srcRowIndex - 1 == dstRowIndex)){
                return true;
            }
        }
        return false;
    }

    // Liam
    bool Pawn::isValidAttack(BoardCell* target){
        //Define index for current pawn
        int srcRowIndex = cell->rowIndex;
        int srcColIndex = cell->colIndex;

        //Define index for destination cell
        int dstRowIndex = target->rowIndex;
        int dstColIndex = target->colIndex;


        //Define the source and destination boards
        int srcBoardIndex = this->cell->board->level;
        int dstBoardIndex = target->board->level;

        //Check to see if the piece is still in play
        if(!isInplay()){return false;}

        //Check to see if target cell has chesspiece with the same color
        if(!target->isEmpty() && target->piece->hasSameColor(this) ){return false;}

        //Check to see if pawn is trying to attack past more than 1 board
        if(abs(dstBoardIndex - srcBoardIndex) > 1){return false;}

        if(!target->isEmpty() && !target->piece->hasSameColor(this)){
            if (this->color == WHITE){
                if(srcRowIndex == ROW_COUNT-1 && srcBoardIndex == 0){return false;} //If piece is at the end of the board (White side)

                //indices for the two possible cells that can be attacked
                int atkRow = srcRowIndex + 1;
                int atkCol1 = srcColIndex + 1;
                int atkCol2 = srcColIndex - 1;

                //case for left side of board
                if(srcColIndex == 0){
                    if((dstRowIndex == atkRow) && (dstColIndex == atkCol1)){
                        return true;
                    }
                }

                //case for right side of board
                if(srcColIndex == COL_COUNT-1){
                    if((dstRowIndex == atkRow) && (dstColIndex == atkCol2)){
                        return true;
                    }
                }

                //case for if pawn is not on the sides
                if((dstRowIndex == atkRow) && (dstColIndex == atkCol1 || dstColIndex == atkCol2)){
                    return true;
                }
            }

            else if(this->color == BLACK){ //
                if(srcRowIndex == ROW_COUNT-1 && srcBoardIndex == 2){return false;} //If piece is at the end of the board

                //indices for the two possible cells that can be attacked (Black side)
                int atkRow = srcRowIndex - 1;
                int atkCol1 = srcColIndex + 1;
                int atkCol2 = srcColIndex - 1;

                //case for left side of board
                if(srcColIndex == 0){
                    if((dstRowIndex == atkRow) && (dstColIndex == atkCol1)){
                        return true;
                    }
                }

                //case for right side of board
                if(srcColIndex == COL_COUNT-1){
                    if((dstRowIndex == atkRow) && (dstColIndex == atkCol2)){
                        return true;
                    }
                }

                //case for if pawn is not on the sides
                if((dstRowIndex == atkRow) && (dstColIndex == atkCol1 || dstColIndex == atkCol2)){
                    return true;
                }
            }
        }

        return false;
    }

