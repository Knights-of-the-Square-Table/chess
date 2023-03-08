#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "chessboard.h"
#include "player.h"

class ChessGame{
    public:
    ChessBoard* board;

    Player* players[2];
    int currentPlayerIndex;


    ChessGame();
    void printBoard();
    void nextTurn();


    Player* getCurrentPlayer();
};

#endif // CHESSGAME_H
