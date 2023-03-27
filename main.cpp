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


bool tryMove(ChessGame* g, int r1, int c1, int r2, int c2){
    cout << "Move: (" << c1 << ',' << r1 << ") - (" << c2 << ',' << r2 << ")";


    BoardCell* srcCell = g->topBoard->getCell(r1,c1);
    BoardCell* dstCell = g->topBoard->getCell(r2,c2);


    bool validMove = false;

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
    cout << "Move: (" << r1 << ',' << c1 << ") - (" << r2 << ',' << c2 << ")";
    cout << " - " << (validMove ? "VALID" : "INVALID") << endl;

    //move the piece if it is a valid move
    if (validMove){
        srcCell->piece->move(dstCell);
        g->printBoards();
    }
    return validMove;
}


int main(){

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
                if(tryMove( g, get<0>(fromPos), get<1>(fromPos), get<0>(toPos), get<1>(toPos))){
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
