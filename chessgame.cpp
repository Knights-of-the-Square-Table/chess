#include <iostream>
#include "chessgame.h"
#include "chessboard.h"
#include "player.h"
#include "qdebug.h"
#include <limits>
#include <regex>
#include<array>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <limits>
#include <list>
using namespace std;


ChessGame::ChessGame()
{
    botBoard = new ChessBoard(this, BOTTOM);

    // 3d version stuff*******************

    topBoard = new ChessBoard(this, TOP);

    midBoard = new ChessBoard(this, MIDDLE);

    /*************************************/

    players[0] = new Player(WHITE);
    players[1] = new Player(BLACK);
    currentPlayerIndex = 0;
    botBoard->game = this;
    topBoard->game = this;
    midBoard->game = this;
    qDebug() << "game started";
}


// 3d version stuff********new*********

void ChessGame::printBoards()
{
    printBoard(topBoard);

    printBoard(midBoard);

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

void ChessGame::run()
{

  //  this->printStartText();
    //this->gameLoop();

}

//Chris
void ChessGame::gameLoop()
{
    char input = printOptionsMenu();
    //menu loop
    while(1){

        if(toupper(input) == 'P'){
             this->printBoards();
             string userInput;
             string userInput2;
             string curPlayer;
             tuple<int,int,int> fromPos;
             tuple<int,int,int> toPos;
             //game loop
             while(1){

                 //Get the current player's turn
                 if(this->getCurrentPlayer()->getColor() == 0){
                     curPlayer = "White";
                 }else{
                     curPlayer = "Black";
                 }

                 cout << curPlayer << "'s turn, choose a menu option or move: ";

                 cin >> userInput ;
                 //check it the first input is valid
                 if(this->validateInput(userInput)){

                     //kicks back out to menu loop
                     if(userInput == "M" || userInput == "m"){
                         cout << "you chose to display window" << endl;
                         input = 'm';
                         break;
                     }

                     cin >> userInput2;
                     //check if the second input is valid
                     if(this->validateInput(userInput2)){
                         //Convert both inputs from form " A3 " to (0,2).
                         fromPos = this->convertInput(userInput);
                         toPos = this->convertInput(userInput2);

                         //tries to move the pieces, if it succeeds, it increments the games turn counter
                         if(tryMove(get<0>(fromPos), get<1>(fromPos),get<2>(fromPos), get<0>(toPos), get<1>(toPos), get<2>(toPos))){
                             this->nextTurn();
                             cout << "player turn " << this->currentPlayerIndex << endl;
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
            input = this->printOptionsMenu();


        }else if(toupper(input) == 'Q'){
            cout << "You have chosen to quit, application will exit" << endl;
            exit(0);

        }else if(toupper(input) == 'E'){
            this->getCurrentWinner();
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
//Converts input from cin into a tuple for tryMove() method
std::tuple<int, int, int> ChessGame::convertInput(std::string input)
{
    //initialize the 3 int variables to store converted string
    int column, row, board;

    //convert the letter to a number 0 -> 7
    char holder;
    holder = toupper(input[0]);

    //8 cases for up to 8x8 board.
    switch(holder){

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
    holder = input[1];
    row = atoi(&holder)-1;

    //thirdnum for when we add a 3rd dimension
    holder = input[2];
    board = atoi(&holder)-1;

    tuple<int, int, int> output(row, column, board);

    return output;
}

//Chris
//Method validates the CLI inputs from cin
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

std::vector<int> ChessGame::getPossibleMoves(BoardCell *cell)
{
 //   qDebug() << "got into getpossiblemoves";
 //   qDebug() << cell->getPiece()->getMovesInt(topBoard);
    std::vector<int> topB = cell->getPiece()->getMovesInt(topBoard);
//    qDebug() << "got top cell board";
    std::vector<int> midB = cell->piece->getMovesInt(midBoard);
//    qDebug() << "got mid board";
    std::vector<int> botB = cell->piece->getMovesInt(botBoard);
    std::vector<int> allMoves = {};
 //   qDebug() << "initialized topb, midb, botb";
    std::copy(topB.begin(), topB.end(), std::back_inserter(allMoves));
    std::copy(midB.begin(), midB.end(), std::back_inserter(allMoves));
    std::copy(botB.begin(), botB.end(), std::back_inserter(allMoves));

//    for(auto &i: allMoves){
//        cout << i;
//    }

    return allMoves;
}

//Chris
//Method to reset string input for moves
void ChessGame::resetMoves()
{
    move1 = "";
    move2 = "";
}

Player* ChessGame::getCurrentPlayer(){
    return players[currentPlayerIndex];
}

void ChessGame::resetGame()
{
    //free board memory
    free(topBoard);
    free(midBoard);
    free(botBoard);
    //create 3 new boards
    topBoard = new ChessBoard(this, TOP);
    midBoard = new ChessBoard(this, MIDDLE);
    botBoard = new ChessBoard(this, BOTTOM);
    players[0]->resetScore();
    players[1]->resetScore();
    currentPlayerIndex = 0;
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

//Olga  + some minor modifycations by Chris for additional boards and abstracting from main.cpp
bool ChessGame::tryMove(int r1, int c1, int level1, int r2, int c2, int level2){
    bool validMove = false;
    BoardCell* srcCell;
    BoardCell* dstCell;

    //first attempt at adding 2nd board
    if(level1 == 0){
        srcCell = this->botBoard->getCell(r1, c1);
    }else if(level1 ==1){
        srcCell = this->midBoard->getCell(r1,c1);
    }else{
        srcCell = this->topBoard->getCell(r1, c1);
    }

    if(level2 == 0){
        dstCell = this->botBoard->getCell(r2, c2);
    }else if(level2 == 1){
        dstCell = this->midBoard->getCell(r2,c2);
    }else{
        dstCell = this->topBoard->getCell(r2, c2);
    }

    //check that there is a piece in the cell
    if( srcCell->piece ==NULL){
        qDebug() << "first cell clicked had no piece";
        validMove = false;
    }
            //check that the current player is trying to move their pieces and not enemy pieces
    else if(srcCell->getPiece()->color !=  this->getCurrentPlayer()->color){
            cout << "You cannot move other players pieces" << endl;
           // qDebug() << "move not valid";
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

        this->printBoards();
    }

    //print statement for checking currentPlayerCheck()
    //cout << "is current player in check? " << currentPlayerCheck() << endl;
    return validMove;

}


//Chris
//Method to get cell for chessGameGUI
BoardCell* ChessGame::getCell(int row, int col, int level)
{
    BoardCell * cell = nullptr;
    if(level ==0){
        cell = this->botBoard->getCell(row, col);
    }else if(level == 1){
        cell = this->midBoard->getCell(row, col);
    }else if(level ==2){
        cell = this->topBoard->getCell(row, col);
    }

    return cell;
}

//Chris
//Method to convert string inputs from clicking into tuple that can be used for tryMove()
std::tuple<int, int, int> ChessGame::convertGUIinput(std::string input)
{

    int row, col, level;

    level = input[2]-48;
    row = input[1]-48;
    col = input[0]-'a';

    std::tuple<int,int,int> converted(row, col, level);
    return converted;

}


//Chris

//This method takes inputs from a click and sends a response string
void ChessGame::getInput(QString input)
{

    std::tuple<int,int,int> fromPos;
    std::tuple<int,int,int> toPos;
    //Check if anything has been clicked, if not, store cell clicked in move1
    if(move1 == ""){
        move1 = input.toStdString();
        //Convert move1 to check if the cell has a piece or now
        fromPos = convertGUIinput(move1);

        //resets moves if no piece in the cell
        if(this->getCell(get<0>(fromPos), get<1>(fromPos),get<2>(fromPos))->isEmpty()){
            qDebug() << "No piece selected";
            emit sendResponse("Invalid");
            resetMoves();
        }else
            if(this->getCell(get<0>(fromPos), get<1>(fromPos),get<2>(fromPos))->getPiece()->color == this->getCurrentPlayer()->getColor()){
            standardMoves = getPossibleMoves(this->getCell(get<0>(fromPos), get<1>(fromPos),get<2>(fromPos)));
            possibleMoves = QVector<int>(standardMoves.begin(), standardMoves.end());
            emit sendMoves(possibleMoves);
            emit sendResponse("Paint moves");


        }

    //If first click is stored, wait for second cell click, convert to tuples and attempt move
    }else{
        move2 = input.toStdString();
        fromPos = convertGUIinput(move1);
        toPos = convertGUIinput(move2);
        if(tryMove(get<0>(fromPos), get<1>(fromPos),get<2>(fromPos), get<0>(toPos), get<1>(toPos), get<2>(toPos))){
            this->nextTurn();
            QString sendStr = "";
            QString part1 = QString::fromStdString(move1);
            QString part2 = QString::fromStdString(move2);
            sendStr += part1;
            sendStr += part2;
            emit sendResponse(sendStr);
        }else{
            emit sendResponse("Invalid");
            resetMoves();
        }
        //after move is tried, reset moves again
        resetMoves();
    }

}

// Method for determining whether the current player is in check -Liam
bool ChessGame::currentPlayerCheck(){
    bool result = false;
    ChessBoard* boards [3] = {this->topBoard, this->botBoard, this->midBoard};
    for(int k = 0; k < 3; k++){
        for(int i = 0; i < ROW_COUNT; i++){
            for(int j = 0; j < COL_COUNT; j++){
                if(!boards[k]->cells[i][j]->isEmpty()){
                    if(boards[k]->cells[i][j]->getPiece()->getNickName() == 'K' && getCurrentPlayer()->color == WHITE){
                        result = boards[k]->cells[i][j]->getPiece()->isInCheck();
                    }
                    else if (boards[k]->cells[i][j]->getPiece()->getNickName() == 'k' && getCurrentPlayer()->color == BLACK){
                        result = boards[k]->cells[i][j]->getPiece()->isInCheck();
                    }
                    if(result == true){goto end;}
                }
            }
        }
    }
    end:
    return result;
}
//Liam



