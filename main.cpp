#include <iostream>
#include <sstream>
#include "chessgame.h"
#include "boardcell.h"
#include <string.h>

#include "chessgame.h"


using namespace std;


void getUserInput(){
    //TODO: gets user input and return a list of coordinates to input into tryMove function
}

void tryMove(ChessGame* g, int r1, int c1, int r2, int c2){
    cout << "Move: (" << c1 << ',' << r1 << ") - (" << c2 << ',' << r2 << ")";


    BoardCell* srcCell = g->topBoard->getCell(r1,c1);
    BoardCell* dstCell = g->topBoard->getCell(r2,c2);

    bool validMove = srcCell->piece->isValidMove(dstCell);
    cout << " - " << (validMove ? "VALID" : "INVALID") << endl;

    if (validMove){
        srcCell->piece->move(dstCell);
        g->printBoards();
    }
}


int main(){
//    cout << "CHESS GAME\n\n" << endl;
//    int in;
//    cout << "Enter a char:";
//    cin>>in;
//    cout << "char inputted is: " << in;




    ChessGame* g = new ChessGame();
    g->run();
    g->printBoards();


// Testing game with input/moving pieces
    string userInput = "";
    string userInput2 = "";

    tuple<int,int,int> fromPos;
    tuple<int,int,int> toPos;
    while(true){
        cout << "Choose your piece and where to move: ";
        cin >> userInput ;


        if(userInput == "q"){
            return 0;
        }

        cin >> userInput2;

        fromPos = g->convertInput(userInput);
        toPos = g->convertInput(userInput2);

//        tryMove( g, 0, 0, 1, 0);
        tryMove( g, get<1>(fromPos), get<0>(fromPos), get<1>(toPos), get<0>(toPos));
    }






//    ChessGame* g = new ChessGame();
//    g->run();
//    char input;
//    cin >> input;
//    g->printBoard();


//    tryMove( g, 0, 0, 1, 1);
//    tryMove( g, 0, 0, 0, 0);

//    tryMove( g, 0, 5, 3, 5);
//    tryMove( g, 3, 5, 3, 0);
//    tryMove( g, 0, 0, 5, 0);
//    tryMove( g, 3, 0, 3, 1);

//    tryMove( g, 0, 0, 5, 0);

//    tryMove( g, 5, 5, 0, 5);
//    tryMove( g, 0, 5, 0, 4);
//    tryMove( g, 0, 4, 0, 3);
//    tryMove( g, 0, 3, 0, 2);
//    tryMove( g, 0, 2, 0, 1);


//    return 0;
}
