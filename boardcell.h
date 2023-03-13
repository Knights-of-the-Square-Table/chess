#ifndef BOARDCELL_H
#define BOARDCELL_H

#include "color.h"
#include "chesspiece.h"
#include "chessboard.h"

class ChessBoard;
class ChessPiece;

class BoardCell {

    public:
    ChessBoard* board;
    int rowIndex;
    int colIndex;

    ChessPiece* piece;

    BoardCell(ChessBoard* board, int rowIndex, int colIndex);

    bool isEmpty();
    void removePiece();
    void placePiece(ChessPiece* piece);
    bool hasPiece(Color color);
    ChessPiece* getPiece();

};

#endif // BOARDCELL_H
