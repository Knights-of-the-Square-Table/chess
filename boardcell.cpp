#include "boardcell.h"
#include <iostream>
#include <vector>
#include "chesspiece.h"

using namespace std;

BoardCell::BoardCell(ChessBoard* board, int rowIndex, int colIndex){
    this->board = board;
    this->rowIndex = rowIndex;
    this->colIndex = colIndex;
    this->piece = NULL;
    this->level = board->level;

}

bool BoardCell::isEmpty(){
    return piece == NULL;
}

void BoardCell::removePiece(){
    piece = NULL;
}

void BoardCell::placePiece(ChessPiece* piece){
    this->piece = piece;
}

bool BoardCell::hasPiece(Color color){
    return !isEmpty() && piece->color == color;
}

ChessPiece *BoardCell::getPiece()
{
    return this->piece;
}

BoardCell *BoardCell::getMirrorCell(int rowIndex, int colIndex)
{
    return this->board->getMirrorBoard()->getCell(rowIndex, colIndex);
}

std::vector<BoardCell*> BoardCell::getMirrorCells(int rowIndex, int colIndex){
    std::vector<BoardCell*> v = {};
    if(this->level == TOP){
        return v = {this->board->getMidBoard()->getCell(rowIndex, colIndex), this->board->getBotBoard()->getCell(rowIndex, colIndex)};
    }else if(this->level == MIDDLE){
        return v = {this->board->getTopBoard()->getCell(rowIndex, colIndex), this->board->getBotBoard()->getCell(rowIndex, colIndex)};
    }
    else{
        return v = {this->board->getTopBoard()->getCell(rowIndex, colIndex), this->board->getMidBoard()->getCell(rowIndex, colIndex)};
    }


}

