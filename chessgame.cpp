#include <iostream>
#include "chessgame.h"
#include "chessboard.h"
#include "player.h"
#include <regex>
#include<array>
#include <cstring>
using namespace std;


ChessGame::ChessGame()
{
    board = new ChessBoard();

    players[0] = new Player(WHITE);
    players[1] = new Player(BLACK);
    currentPlayerIndex = 0;
    board->parentGame = this;
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
    this->gameLoop();

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


//Chris
std::tuple<int, int, int> ChessGame::convertInput(std::string input)
{
    //initialize the 3 int variables to store converted string
    int column, row, board;

    //construct a char pointer to convert the char to an int
    const char* str = &input.c_str()[ '\0'];

    //convert the letter to a number 0 -> 7
    char letter;
    letter = toupper(input[0]);

    //8 cases for 8x8 board.
    switch(letter){

    case 'A':
            column = 0;
            break;
        case 'B':
            column = 1;
            break;
        case 'C':
            column = 2;
            break;
        case 'D':
            column = 3;
            break;
        case 'E':
            column = 4;
            break;
        case 'F':
            column = 5;
            break;
        case 'G':
            column = 6;
            break;
        case 'H':
            column = 7;
            break;
        }

    //Converts string input of the number to a usable integer
    char stringInt;
    stringInt = str[1];

    row = atoi(&stringInt)-1;

    //thirdnum for when we add a 3rd dimension
    board = atoi(&str[2])-1;

    tuple<int, int, int> output(row, column, board);

    return output;
}

//Chris
bool ChessGame::validateInput(std::string input)
{

    char commandList[] = {'M', 'Q', 'E', 'S', '\0'};
    const std::regex chess2D("[a-h|A-H]?[1-6]");
    const std::regex chess3D("[a-h|A-H]?[1-6]?[1-3]");
    const int inputLength = input.size();
    char* inputArray = new char[inputLength + 1];
    char inputLetter;
//    input += '\0';

    //potentially in danger to abuse from buffer overflow
    //TODO find a better way
    strcpy(inputArray, input.c_str());

    if(inputLength == 0 || input.size() > 3){
        return false;
    }

    if(inputLength == 1){
        inputLetter = toupper(inputArray[0]);
        for(unsigned int i = 0; i < sizeof(commandList); i++){

            if(inputLetter != commandList[i]){
                continue;
            }else

            if(inputLetter == commandList[i]){
                return true;
            }else

            if(commandList[i] == '\0'){
                return false;
            }
        }
    }

    if(inputLength == 2){
        return regex_match(input, chess2D);
    }

    if(inputLength == 3){
        return regex_match(input, chess3D);
    }
    return false;
}

void ChessGame::gameLoop()
{

}

Player* ChessGame::getCurrentPlayer(){
    return players[currentPlayerIndex];
}




