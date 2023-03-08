#include <iostream>

#include "chessboard.h"
#include "boardcell.h"
#include "rook.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"

using namespace std;


ChessBoard::ChessBoard(){

    // Create cells
    for(int ri = 0; ri < ROW_COUNT; ri++){
        for(int ci = 0; ci < COL_COUNT; ci++){
            cells[ri][ci] = new BoardCell(this, ri, ci);
        }
    }


    const int lastRowIndex = ROW_COUNT - 1;
    const int lastColIndex = COL_COUNT - 1;

    // Create and place Rocks
    new Rook( getCell(0,0), WHITE );
    new Rook( getCell(0,lastColIndex), WHITE );
    new Rook( getCell(lastRowIndex,0), BLACK );
    new Rook( getCell(lastRowIndex,lastColIndex), BLACK );


    new Bishop( getCell(0,1), WHITE );
    new Bishop( getCell(0,lastColIndex-1), WHITE );
    new Bishop( getCell(lastRowIndex,1), BLACK );
    new Bishop( getCell(lastRowIndex,lastColIndex-1), BLACK );


    new King( getCell(0,2), WHITE );
    new King( getCell(lastRowIndex,2), BLACK );

    new Queen( getCell(0,3), WHITE );
    new Queen( getCell(lastRowIndex,3), BLACK );

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
                cout << " " << nickName << " |";
            }
        }
        cout << ri+1 << "|" << endl;
        cout << center << divider << endl;
    }
    cout << center << "  | a | b | c | d | e | f |" << endl;
        cout << endl << endl;

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
