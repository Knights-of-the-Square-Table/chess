#include <iostream>

#include "chessboard.h"
#include "boardcell.h"
#include "rook.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"


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
        new Rook(getCell(0, 0), WHITE);
     //   new Knight(getCell(0, 1), WHITE);
        new Bishop(getCell(0, 2), WHITE);
        new King(getCell(0, 3), WHITE);
        new Queen(getCell(0, 4), WHITE);
        new Bishop(getCell(0, 5), WHITE);
    //    new Knight(getCell(0, 6), WHITE);
        new Rook(getCell(0, 7), WHITE);
//        new Rook(   getCell(0,0), WHITE );
//        new Bishop( getCell(0,1), WHITE );
//        new King(   getCell(0,2), WHITE );
//        new Queen(  getCell(0,3), WHITE );
//        new Bishop( getCell(0,4), WHITE );
//        new Rook(   getCell(0,5), WHITE );

      /*new Pawn(   getCell(1,0), WHITE );
        new Pawn(   getCell(1,1), WHITE );
        new Pawn(   getCell(1,2), WHITE );
        new Pawn(   getCell(1,3), WHITE );
        new Pawn(   getCell(1,4), WHITE );
        new Pawn(   getCell(1,5), WHITE );*/
    }

    else if(level == BOTTOM){
        new Rook(   getCell(7,0), BLACK );
  //      new Knight(getCell(7,1), BLACK);
        new Bishop( getCell(7,2), BLACK );
        new King(   getCell(7,3), BLACK );
        new Queen(  getCell(7,4), BLACK );
        new Bishop( getCell(7,5), BLACK );
    //    new Knight(getCell(7,6), BLACK);
        new Rook(   getCell(7,7), BLACK );
//        new Rook(   getCell(5,0), BLACK );
//        new Bishop( getCell(5,1), BLACK );
//        new King(   getCell(5,2), BLACK );
//        new Queen(  getCell(5,3), BLACK );
//        new Bishop( getCell(5,4), BLACK );
//        new Rook(   getCell(5,5), BLACK );

      /*new Pawn(   getCell(4,0), BLACK );
        new Pawn(   getCell(4,1), BLACK );
        new Pawn(   getCell(4,2), BLACK );
        new Pawn(   getCell(4,3), BLACK );
        new Pawn(   getCell(4,4), BLACK );
        new Pawn(   getCell(4,5), BLACK );*/
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
    string divider = "  _________________________________";
    string empty = "       ";
    string center = "                   ";
    string boardLevelFrontSpace = "     ";
    string boardLevelEndSpace = "    ";
    string boardLevel = this->printBoardLevel(this->level);
    cout << endl << endl;
//    cout << divider << endl;
    cout << center <<"  | a | b | c | d | e | f | g | h |" << endl;
    cout << center << divider << endl;
    for (int ri = 0; ri < ROW_COUNT; ri++){
        if(ri==2){
            cout << boardLevelFrontSpace << boardLevel << boardLevelEndSpace << "|" << ri+1 << "|";
        }
        else
        {
            cout << center <<"|" << ri+1 << "|";
        }

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
    cout << center << "  | a | b | c | d | e | f | g | h |" << endl;
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

ChessBoard *ChessBoard::getTopBoard()
{
    return this->game->topBoard;
}

ChessBoard *ChessBoard::getBotBoard()
{
    return this->game->botBoard;
}

ChessBoard *ChessBoard::getMidBoard()
{
    return this->game->midBoard;
}

string ChessBoard::printBoardLevel(Level level)
{
    if(level == TOP)
    {
        return "Top(3)";
    }
    else if(level == MIDDLE)
    {
        return "Mid(2)";
    }
    else
    {
        return "Bot(1)";
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
