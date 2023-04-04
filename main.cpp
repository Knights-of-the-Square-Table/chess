#include <iostream>
#include <sstream>
#include "chessgame.h"
#include "boardcell.h"
#include <string.h>
#include <limits>
#include "chessgame.h"


using namespace std;


void getUserInput(){
    //TODO: gets user input and return a list of coordinates to input into tryMove function  
}


bool tryMove(ChessGame* g, int r1, int c1, int level1, int r2, int c2, int level2){

    bool validMove = false;
    BoardCell* srcCell;
    BoardCell* dstCell;

    //first attempt at adding 2nd board
    if(level1 == 0){
        srcCell = g->botBoard->getCell(r1, c1);
    }else{
        srcCell = g->topBoard->getCell(r1, c1);
    }
    if(level2 == 0){
        dstCell = g->botBoard->getCell(r2,c2);
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


int main(){
    cout << "Game starting" << endl;
    ChessGame* g = new ChessGame();
    g->run();
    g->printBoards();


// Testing game with input/moving pieces
    //Chris
    //TODO Get this out of main into its own method or 2
    //ASAP
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
                cout << "you chose to quit" << endl;
                return 0;
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
                }
            }
        }else{
             cout << "Input was invalid" << endl;
        }

        //clear the cin buffer in case 1 or more invalid inputs are given
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}
