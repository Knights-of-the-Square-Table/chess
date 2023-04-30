#include "chesspiece.h"
#include "chessgame.h"
#include "qdebug.h"
#include <vector>


ChessPiece::ChessPiece(BoardCell* cell, Color color){
    this->cell = cell;
    this->color = color;
    cell->placePiece(this);
}


bool ChessPiece::isInplay(){
    return cell != NULL;
}

void ChessPiece::move(BoardCell* target){
    if( !isInplay() ){
        return;
    }
    cell->removePiece();


    if(!target->isEmpty()){
        target->piece->beCaptured();
    }
    target->placePiece(this);

    this->cell = target;
}

bool ChessPiece::hasSameColor(ChessPiece* piece){
    return color == piece->color;
}

//Liam
void ChessPiece::beCaptured(){
    this->cell->board->game->getCurrentPlayer()->addCapturedPiece(this);
    cell->removePiece();
    //cell = NULL;




}

std::vector<BoardCell *> ChessPiece::getMoves(ChessBoard *board)
{
    std::vector<BoardCell*> moves = {};
    BoardCell* tempTargetCell = nullptr;
    for(int ri=0; ri<ROW_COUNT;ri++){
        for(int ci=0; ci<COL_COUNT; ci++){
            tempTargetCell = board->getCell(ri, ci);
            if(cell->getPiece()->isValidMove(tempTargetCell)){
                moves.push_back(tempTargetCell);
            }
        }
    }
    return moves;
}

std::vector<int> ChessPiece::getMovesInt(ChessBoard *board){
    std::vector<int> movesInt = {};
    int count = 0;
    BoardCell* tempTargetCell = nullptr;

    for(int ri=0; ri<ROW_COUNT; ri++){
        for(int ci=0; ci<COL_COUNT; ci++){
            tempTargetCell = board->getCell(ri, ci);

            if(cell->getPiece()->isValidMove(tempTargetCell)){
                if(board->level == TOP){
                    movesInt.push_back(ri * COL_COUNT + ci);
                }else if(board->level == MIDDLE){
                    movesInt.push_back(ri *COL_COUNT + ci + 64);
                }else if(board->level == BOTTOM){
                    movesInt.push_back(ri * COL_COUNT + ci + 128);
                }

            }

            count++;
        }
    }
    return movesInt;
}

std::vector<ChessPiece *> ChessPiece::getOpponentPieces(ChessBoard *board)
{
    std::vector<ChessPiece*> opponentPieces = {};
    for(int ri = 0; ri < ROW_COUNT; ri++){
        for(int ci = 0; ci < COL_COUNT; ci++){

        }
    }
}

