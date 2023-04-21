#include <iostream>
#include <sstream>
#include "chessgame.h"
#include <string.h>
#include "chessgame.h"
#include "display.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGridLayout>
#include <QFrame>


using namespace std;

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    Display D;
   // MainWindow w;
    QGraphicsView* view = new QGraphicsView(D.getScene());
    view->setFixedSize(1800,1000);
    view->show();

    return a.exec(); // comment this line out for CLI

    ChessGame* g = new ChessGame();
    g->run();

//    return 0; //uncomment this line for CLI
}
