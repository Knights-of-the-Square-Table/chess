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
}

void ChessGame::nextTurn(){
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
}

void ChessGame::printStartText()
{
   cout << "|-------------------------------------------------------------|" << endl;
   cout << "|                 WELCOME TO TERMINAL CHESS                   |" << endl;
   cout << "|-------------------------------------------------------------|" << endl;
   cout << "|                       *** RULES ***                         |" << endl;
   cout << "|                                                             |" << endl;
   cout << "| 1. This game is a two player game [Player 0] and [Player 1] |" << endl;
   cout << "| 2. [Player 0] goes first and chess pieces are denoted by    |" << endl;
   cout << "|    the following characters: {R,B,K,Q} -> represent WHITE   |" << endl;
   cout << "| 3. [Player 1] chess pieces are denoted by the following     |" << endl;
   cout << "|    characters: {r,b,k,q} -> represent BLACK                 |" << endl;
   cout << "| 4. Each turn, player has to select what action they would   |" << endl;
   cout << "|    like to do by entering one of following options          |" << endl;
   cout << "| 5. If [M]move is chosen by player, the player has to enter  |" << endl;
   cout << "|    location of piece they want to move followed by a [SPACE]|" << endl;
   cout << "|    and then the target location, then hit [ENTER]           |" << endl;
   cout << "| 6. If the move is a valid one the board will reprint and    |" << endl;
   cout << "|    automatically switch to next player's turn               |" << endl;
   cout << "| 7. If move is not valid, it will prompt the user to enter   |" << endl;
   cout << "|    another move or give option to return to menu options    |" << endl;
   cout << "|-------------------------------------------------------------|" << endl;
   cout << "|                  GOOD LUCK AND HAVE FUN!                    |" << endl;
   cout << "|-------------------------------------------------------------|" << endl;

}

void ChessGame::run()
{
    this->printStartText();
    this->printOptionsMenu();


}

char ChessGame::printOptionsMenu()
{
    char action;
    int player = currentPlayerIndex;
    cout << "[Player " << player << "]: SELECT FROM THE FOLLOWING OPTIONS" << endl;
    cout << "[M]move    [Q]quit     [E]end game with a winner    [S]start over" << endl;
    cin >> action;
    return action;
}

void ChessGame::printStartOptionsMenu()
{

}

Player* ChessGame::getCurrentPlayer(){
    return players[currentPlayerIndex];
}


