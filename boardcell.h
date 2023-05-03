#ifndef BOARDCELL_H
#define BOARDCELL_H

#include "color.h"
#include "chessboard.h"
#include <vector>

class ChessBoard;
class ChessPiece;

class BoardCell {

    public:
    ChessBoard* board;
    int rowIndex;
    int colIndex;
    Level level;

    ChessPiece* piece;


    BoardCell(ChessBoard* board, int rowIndex, int colIndex);

    bool isEmpty();
    void removePiece();
    void placePiece(ChessPiece* piece);
    bool hasPiece(Color color);
    ChessPiece* getPiece();
    BoardCell* getMirrorCell(int rowIndex, int colIndex);
    std::vector<BoardCell*> getMirrorCells(int rowIndex, int colIndex);
};

#endif // BOARDCELL_H
