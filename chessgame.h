#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "chessboard.h"
#include "player.h"
#include "qobject.h"

#include <tuple>

class ChessBoard;
class Player;
class ChessGame : public QObject{

    Q_OBJECT

public:
    ChessBoard* topBoard;
    ChessBoard* botBoard;
    ChessBoard* midBoard;

    Player* players[2];
    int currentPlayerIndex;


    ChessGame();
 //   void printBoard();
    void nextTurn();
    void printStartText();
    void run();
    bool tryMove(int sr, int sc,int slevel, int tr, int tc, int tlevel);
    void getUserInput();
    void gameLoop();
    void getCurrentWinner();

    char printOptionsMenu();
    void printStartOptionsMenu();
    BoardCell * getCell(int row,int col,int level);
    std::tuple<int,int,int> convertGUIinput(std::string input);
    std::tuple<int,int,int> convertInput(std::string input);
    bool validateInput(std::string input);

    QString guimove;
    std::string move1 = "";
    std::string move2 = "";
    Color guiTurn = WHITE;
    void switchGuiTurn();
    void resetMoves();

    Player* getCurrentPlayer();

    //3d version stuff************
    void printBoards();
    void printBoard(ChessBoard* b);
    /****************************/

    // Qt Signaling
public slots:
    void getInput(QString input);

signals:
    void sendResponse(QString response);
};

#endif // CHESSGAME_H
