#include "chesspiece.h"
#include "chessgame.h"
#include "king.h"
#include <vector>
#include <iostream>

using namespace std;
ChessPiece::ChessPiece(BoardCell* cell, Color color){
    this->cell = cell;
    this->color = color;
    cell->placePiece(this);
}

bool ChessPiece::isInplay(){
    return cell != NULL;
}

//Olga - moves the piece to the target cell
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
    this->hasMoved = true;
}

//Olga - temp move to see if king is in check
void ChessPiece::tempMove(BoardCell* tempTarget){

    tempRemovedPiece = NULL;
    if(!tempTarget->isEmpty()){
        this->tempRemovedPiece = tempTarget->getPiece();
        tempTarget->removePiece();
        tempRemovedPiece->cell = NULL;
    }
    this->tempStartCell = cell;
    cell->removePiece();
    tempTarget->placePiece(this);
    this->cell = tempTarget;
}
//Olga - undos the temp move to check if king is in check
void ChessPiece::undoTempMove()
{
    //
    BoardCell* tempTarget = this->cell;
    cell->removePiece();
    tempStartCell->placePiece(this);
    this->cell = tempStartCell;
    if(tempRemovedPiece){
        tempTarget->placePiece(tempRemovedPiece);
        tempRemovedPiece->cell = tempTarget;
    }
    tempStartCell = NULL;
    tempRemovedPiece = NULL;

}


//Olga - checks to see if move is valid considering check
bool ChessPiece::isValidNoCheck(BoardCell *target)
{
    if(!this->isValidMove(target)){
        return false;
    }
//    cout << "----Inside isValidNoCheck:"<< target->rowIndex << "," << target->colIndex << endl;
    this->tempMove(target);
    char nickname = this->color == WHITE ? 'K':'k';
    King* king = (King*)this->cell->board->game->getKingLocation(nickname,this->color)->getPiece();
//    cout << "--King Location:" << king->cell->rowIndex << "," << king->cell->colIndex << endl;
    bool isCheck = king->isInCheck();
//    cout << "Is Check = " <<isCheck << endl;
    this->undoTempMove();
    return !isCheck;


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

//Olga - returns a vector with all possible moves across all boards
std::vector<BoardCell *> ChessPiece::getAllMoves()
{
    std::vector<BoardCell*> moves = {};
    BoardCell* tempTargetCell = nullptr;
    std::vector<ChessBoard*> boards = {
        this->cell->board->getBotBoard(),
        this->cell->board->getMidBoard(),
        this->cell->board->getTopBoard()
    };
    int sizeB = boards.size();
    for(int bi = 0; bi < sizeB; bi++){
        for(int ri=0; ri<ROW_COUNT;ri++){
            for(int ci=0; ci<COL_COUNT; ci++){
                tempTargetCell = boards.at(bi)->getCell(ri, ci);
                if(cell->getPiece()->isValidMove(tempTargetCell)){
                    moves.push_back(tempTargetCell);
                }
            }
        }
    }
    return moves;
}

// Olga - returns a vector with all the boardcells that are possible valid moves on a board
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

//Olga - returns a vector of 0,1 for each cell on a board depending on if a move is valid or not
std::vector<int> ChessPiece::getMovesInt(ChessBoard *board){
    std::vector<int> movesInt = {};
    int count = 0;
    BoardCell* tempTargetCell = nullptr;

    for(int ri=0; ri<ROW_COUNT; ri++){
        for(int ci=0; ci<COL_COUNT; ci++){
            tempTargetCell = board->getCell(ri, ci);

            if(cell->getPiece()->isValidNoCheck(tempTargetCell)){
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

//Olga - returns a vector of the opponents chesspieces from all boards
std::vector<ChessPiece *> ChessPiece::getOpponentPieces()
{
    std::vector<ChessBoard*> boards = {
        this->cell->board->getBotBoard(),
        this->cell->board->getMidBoard(),
        this->cell->board->getTopBoard()
    };
    int sizeB = boards.size();
    std::vector<ChessPiece*> opponentPieces = {};
    BoardCell* tempCell = nullptr;
    Color opponentColor;
    if(this->color == WHITE){
        opponentColor = BLACK;
    }else{
        opponentColor = WHITE;
    }
    for(int bi = 0; bi < sizeB; bi++){
        for(int ri = 0; ri < ROW_COUNT; ri++){
            for(int ci = 0; ci < COL_COUNT; ci++){
                tempCell = boards.at(bi)->getCell(ri, ci);
                if(tempCell->hasPiece(opponentColor)){
                    opponentPieces.push_back(tempCell->getPiece());
                }
            }
        }
    }
    return opponentPieces;
}

//Olga - returns a vector of same color pieces on all boards
std::vector<ChessPiece *> ChessPiece::getMyPieces()
{
    std::vector<ChessBoard*> boards = {
        this->cell->board->getBotBoard(),
        this->cell->board->getMidBoard(),
        this->cell->board->getTopBoard()
    };
    int sizeB = boards.size();
    std::vector<ChessPiece*> myPieces = {};
    BoardCell* tempCell = nullptr;
    for(int bi = 0; bi < sizeB; bi++){
        for(int ri = 0; ri < ROW_COUNT; ri++){
            for(int ci = 0; ci < COL_COUNT; ci++){
                tempCell = boards.at(bi)->getCell(ri, ci);
                if(tempCell->hasPiece(this->color)){
                    myPieces.push_back(tempCell->getPiece());
                }
            }
        }
    }
    return myPieces;

}







