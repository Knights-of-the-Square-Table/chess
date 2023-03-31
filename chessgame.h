#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "chessboard.h"
#include "player.h"

#include <tuple>

class ChessGame{
    public:
    ChessBoard* board;

    Player* players[2];
    int currentPlayerIndex;


    ChessGame();
    void printBoard();
    void nextTurn();
    void printStartText();
    void run();
    void tryMove(ChessBoard*, int sr, int sc, int tr, int tc);
    void getUserInput();
    void gameLoop();
    void getCurrentWinner();

    char printOptionsMenu();
    void printStartOptionsMenu();

    std::tuple<int,int,int> convertInput(std::string input);
    bool validateInput(std::string input);


    Player* getCurrentPlayer();
};

#endif // CHESSGAME_H
