#include <iostream>
#include <sstream>
#include "MainWindow.h"
#include "chessgame.h"
#include <string.h>
#include <QApplication>

//Chris
using namespace std;

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec(); // comment this line out for CLI

//    ChessGame* g = new ChessGame();
//    g->run();

//    return 0; //uncomment this line for CLI
}
