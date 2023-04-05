#include <iostream>
#include <sstream>
#include "chessgame.h"
#include "boardcell.h"
#include <string.h>
#include <limits>
#include "chessgame.h"


using namespace std;

int main(){

    ChessGame* g = new ChessGame();
    g->run(g);
//    g->run();

    return 0;
}
