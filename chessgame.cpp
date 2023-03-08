#include <iostream>
#include "chessgame.h"
#include "chessboard.h"
#include "player.h"

using namespace std;


ChessGame::ChessGame()
{
    board = new ChessBoard();

    players[0] = new Player(WHITE);
    players[1] = new Player(BLACK);
    currentPlayerIndex = 0;
}

void ChessGame::printBoard(){
    board->print();
};

void ChessGame::nextTurn(){
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
};

Player* ChessGame::getCurrentPlayer(){
    return players[currentPlayerIndex];
}
