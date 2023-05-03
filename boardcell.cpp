#include "boardcell.h"
#include <iostream>
#include <vector>
#include "chesspiece.h"

using namespace std;
//Olga
BoardCell::BoardCell(ChessBoard* board, int rowIndex, int colIndex){
    this->board = board;
    this->rowIndex = rowIndex;
    this->colIndex = colIndex;
    this->piece = NULL;
    this->level = board->level;

}
//Olga
bool BoardCell::isEmpty(){
    return piece == NULL;
}

//Olga
void BoardCell::removePiece(){
    piece = NULL;
}
//Olga
void BoardCell::placePiece(ChessPiece* piece){
    this->piece = piece;
}
//Olga
bool BoardCell::hasPiece(Color color){
    return !isEmpty() && piece->color == color;
}
//Olga
ChessPiece *BoardCell::getPiece()
{
    return this->piece;
}
//Olga - for 2 board version, returns mirror cell
BoardCell *BoardCell::getMirrorCell(int rowIndex, int colIndex)
{
    return this->board->getMirrorBoard()->getCell(rowIndex, colIndex);
}

//Olga - returns mirror cells of the current cell
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


