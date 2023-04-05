#include <iostream>
#include <sstream>
#include "chessgame.h"
#include "boardcell.h"
#include <string.h>
#include <limits>
#include "chessgame.h"


using namespace std;

int main(){
    cout << "Game starting" << endl;
    ChessGame* g = new ChessGame();

    g->run();

    return 0;
}
