#include <iostream>
#include "chessgame.h"
#include "chessboard.h"
#include "player.h"
#include <regex>
#include<array>
#include <cstring>
#include <stdlib.h>
using namespace std;


ChessGame::ChessGame()
{
    botBoard = new ChessBoard(this, BOTTOM);

    // 3d version stuff*******************

    topBoard = new ChessBoard(this, TOP);

    /*************************************/

    players[0] = new Player(WHITE);
    players[1] = new Player(BLACK);
    currentPlayerIndex = 0;
    botBoard->game = this;
    topBoard->game = this;
}


// 3d version stuff********new*********

void ChessGame::printBoards()
{
    printBoard(topBoard);

    printBoard(botBoard);
}
void ChessGame::printBoard(ChessBoard* b)
{
    b->print();

}
/*****************old******************/
//void ChessGame::printBoard(){
//    board->print();
//}
/**************************************/
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

void ChessGame::run(ChessGame *g)
{
   // ChessGame* g = new ChessGame();
    this->printStartText();
    this->gameLoop(g);

}

//Chris
void ChessGame::gameLoop(ChessGame *g)
{
    char input = printOptionsMenu();
    while(1){

        if(toupper(input) == 'P'){
             g->printBoards();
             string userInput = "";
             string userInput2 = "";
             string curPlayer;
             tuple<int,int,int> fromPos;
             tuple<int,int,int> toPos;
             while(true){

                 //Get the current player's turn
                 if(g->getCurrentPlayer()->getColor() == 0){
                     curPlayer = "White";
                 }else{
                     curPlayer = "Black";
                 }

                 cout << curPlayer << "'s turn, choose a menu option or move: ";

                 cin >> userInput ;
                 //check it the first input is valid
                 if(g->validateInput(userInput)){

                     //TEMPORARY if until we get option methods set up
                     if(userInput == "q" || userInput == "Q"){
                         cout << "You chose to quit" << endl;
                         exit(-1);
                     }
                     if(userInput == "M" || userInput == "m"){
                         cout << "you chose to display window" << endl;
                         input = 'm';
                         break;
                     }

                     cin >> userInput2;
                     //check if the second input is valid
                     if(g->validateInput(userInput2)){
                         //Convert both inputs from form " A3 " to (0,2).
                         fromPos = g->convertInput(userInput);
                         toPos = g->convertInput(userInput2);

                         //tries to move the pieces, if it succeeds, it increments the games turn counter
                         if(tryMove( g, get<0>(fromPos), get<1>(fromPos),get<2>(fromPos), get<0>(toPos), get<1>(toPos), get<2>(toPos))){
                             g->nextTurn();
                             cout << "player turn " << g->currentPlayerIndex << endl;
                         }
                     }
                 }else{
                      cout << "Input was invalid" << endl;

                 }
                 //clear the cin buffer in case 1 or more invalid inputs are given
                 cin.clear();
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
             }

        }else if(toupper(input) == 'M'){
            input = g->printOptionsMenu();


        }else if(toupper(input) == 'Q'){
            cout << "You have chosen to quit, application will exit" << endl;
            exit(0);

        }else if(toupper(input) == 'E'){
            g->getCurrentWinner();
            //TODO: potential reset/newGame method? exit for now
            exit(0);

        }else if(toupper(input) == 'S'){
            //TODO: add reset game/newGame method (may need a deconstructor for memory reasons(?)


        }else{
            cout << "Invalid input. ";
            //clear cin in for bad inputs
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Try again: " ;
            cin >> input;

        }
    }


}

char ChessGame::printOptionsMenu()
{
    char action;
    int player = currentPlayerIndex;
    cout << "[Player " << player << "]: SELECT FROM THE FOLLOWING OPTIONS" << endl;
    cout << "[M]Menu    [Q]quit     [E]end game with a winner    [S]start over    or [P]Play" << endl;
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

Player* ChessGame::getCurrentPlayer(){
    return players[currentPlayerIndex];
}

void ChessGame::getCurrentWinner(){
    if (this->players[0]->getPoints() == this->players[1]->getPoints()){
        cout << "It's a tie, both players have equal points" << endl;
    }
    else if (this->players[0]->getPoints() > this->players[1]->getPoints()){
        cout << "Player 0 wins!" << endl;
    }
    else { //Player 1 has more points
        cout << "Player 1 wins!" << endl;
    }
}

//Olga  + some minor modifycations by Chris for additional boards
bool ChessGame::tryMove(ChessGame *g, int r1, int c1, int level1, int r2, int c2, int level2){

    bool validMove = false;
    BoardCell* srcCell;
    BoardCell* dstCell;

    //first attempt at adding 2nd board
    if(level1 == 0){
        srcCell = g->botBoard->getCell(r1, c1);
    }else{
        srcCell =   g->topBoard->getCell(r1, c1);
    }
    if(level2 == 0){
        dstCell = g->botBoard->getCell(r2, c2);
    }else{
        dstCell = g->topBoard->getCell(r2, c2);
    }

    //check that there is a piece in the cell
    if( srcCell->piece ==NULL){
        validMove = false;
    }
            //check that the current player is trying to move their pieces and not enemy pieces
    else if(srcCell->getPiece()->color !=  g->getCurrentPlayer()->color){
            cout << "You cannot move other players pieces" << endl;
            validMove = false;
        }
    else{
        validMove = srcCell->piece->isValidMove(dstCell);
    }

    cout << "Move: (" << c1 << ',' << r1 <<',' <<level1 << ") - (" << c2 << ',' << r2 << ',' << level2 << ")";
    cout << " - " << (validMove ? "VALID" : "INVALID") << endl;

    //move the piece if it is a valid move
    if (validMove){
        srcCell->piece->move(dstCell);
        g->printBoards();
    }
    return validMove;
}

