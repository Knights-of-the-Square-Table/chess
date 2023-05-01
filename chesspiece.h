#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <string>
#include "boardcell.h"
#include "color.h"
#include "chessgame.h"

class BoardCell;
class ChessGame;
enum Color;

class ChessPiece{

    public:
    BoardCell* cell;
    Color color;
    ChessPiece(BoardCell* cell, Color color);
    BoardCell * tempStartCell;
    ChessPiece* tempRemovedPiece;

    virtual bool isValidMove(BoardCell* target) = 0;
    virtual char getNickName() = 0;
    virtual int getPointValue() = 0;

    bool isInplay();
    void move(BoardCell* target);
    bool hasSameColor(ChessPiece* piece);
    void beCaptured();
    std::vector<BoardCell*> getMoves(ChessBoard* board);
    std::vector<int> getMovesInt(ChessBoard* board);

    //these methods are for if king is in check
    std::vector<ChessPiece*> getOpponentPieces();
    void tempMove(BoardCell* tempTarget);
    void undoTempMove();
    bool isValidNoCheck(BoardCell* target);



    std::vector<ChessPiece*> getMyPieces();
    std::vector<BoardCell*> getAllMoves();

};

#endif // CHESSPIECE_H
