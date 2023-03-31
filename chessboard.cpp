#include <iostream>

#include "chessboard.h"
#include "boardcell.h"
#include "rook.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"


using namespace std;


ChessBoard::ChessBoard(ChessGame* game, Level level){
    this->game = game;

    this->level = level;

    // Create cells
    for(int ri = 0; ri < ROW_COUNT; ri++){
        for(int ci = 0; ci < COL_COUNT; ci++){
            cells[ri][ci] = new BoardCell(this, ri, ci);
        }
    }

    // Create and place Rocks

    if(level == TOP){
        new Rook(   getCell(0,0), WHITE );
        new Bishop( getCell(0,1), WHITE );
        new King(   getCell(0,2), WHITE );
        new Queen(  getCell(0,3), WHITE );
        new Bishop( getCell(0,4), WHITE );
        new Rook(   getCell(0,5), WHITE );
    }

    else{
        new Rook(   getCell(5,0), BLACK );
        new Bishop( getCell(5,1), BLACK );
        new King(   getCell(5,2), BLACK );
        new Queen(  getCell(5,3), BLACK );
        new Bishop( getCell(5,4), BLACK );
        new Rook(   getCell(5,5), BLACK );
    }










}

BoardCell* ChessBoard::getCell(int rowIndex, int colIndex){
    return cells[rowIndex][colIndex];
}

//void ChessBoard::print(){
//    for(int ri = 0; ri < ROW_COUNT; ri++){
//        for(int ci = 0; ci < COL_COUNT; ci++){
//            BoardCell* cell = getCell(ri,ci);
//            if(cell->isEmpty()) {
//                cout << " - ";
//            } else {
//                char nickName = cell->piece->getNickName();
//                cout << ' ' << nickName << ' ';
//            }
//        }
//        cout << endl;
//    }

//}

void ChessBoard::print(){
    string divider = "  _________________________";
    string empty = "   ";
    string center = "               ";
    cout << endl << endl;
//    cout << divider << endl;
    cout << center <<"  | a | b | c | d | e | f |" << endl;
    cout << center << divider << endl;
    for (int ri = 0; ri < ROW_COUNT; ri++){
        cout << center <<"|" << ri+1 << "|";
        for (int ci = 0; ci < COL_COUNT; ci++){
            BoardCell* cell = getCell(ri,ci);
            if(cell->isEmpty()){
                cout << empty << "|";
            } else {
                char nickName = cell->piece->getNickName();
            //    char nickName = '!';
                cout << " " << nickName << " |";
            }
        }
        cout << ri+1 << "|" << endl;
        cout << center << divider << endl;
    }
    cout << center << "  | a | b | c | d | e | f |" << endl;
        cout << endl << endl;

}

ChessBoard *ChessBoard::getMirrorBoard()
{
    if(this->level==TOP){
        return this->game->botBoard;
    }
    else{
        return this->game->topBoard;
    }
}



/*

___________________________
|_| a | b | c | d | e | f |
---------------------------
|1|   |   |   |   |   |   |
---------------------------
|2|   |   |   |   |   |   |
---------------------------
|3|   |   |   |   |   |   |
---------------------------
|4|   |   |   |   |   |   |
---------------------------
|5|   |   |   |   |   |   |
---------------------------
|6|   |   |   |   |   |   |
___________________________





*/
