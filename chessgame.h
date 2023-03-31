#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "chessboard.h"
#include "player.h"

#include <tuple>

class ChessBoard;
class Player;
class ChessGame{
    public:
    ChessBoard* topBoard;
    ChessBoard* botBoard;

    Player* players[2];
    int currentPlayerIndex;


    ChessGame();
 //   void printBoard();
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

    //3d version stuff************
    void printBoards();
    void printBoard(ChessBoard* b);
    /****************************/
};

#endif // CHESSGAME_H
