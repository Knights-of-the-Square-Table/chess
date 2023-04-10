#include "display.h"
#include "guicell.h"
#include "qgraphicsitem.h"
#include <QObject>


//Chris
Display::Display()
{
    // Connect Game signal with Display slot
    QObject::connect(&game, SIGNAL(sendResponse(QString)), this, SLOT(getResponse(QString)));
    DisplayScene = new QGraphicsScene();
    setup();
    placePieces();
}


//Chris
void Display::setup()
{

    const int size = 6;
    int scale = size;
    //i = square, j = x pos, k = y pos
    int i = 0;
    int j = 0;
    int k = 0;
    bool black = true;
    //board 1
    for(i = 0; i < size*size; i++){

        QString spacename = spaces[i];
        GUICell * cell = new GUICell(j,k,0);
        cell->setRect(j,k,70,70);
        if(i%size == 0){
            black = !black;
        }

        if (black)
        {
            cell->setBrush(Qt::lightGray);
        }
        black = !black;

        j += 70;
        if (j == 70*size)
        {
            j = 0;
            k += 70;
        }
        cell->setName(spacename);
        cellList.append(cell);
        DisplayScene->addItem(cell);
        QObject::connect(cell, SIGNAL(sendSignal(QString)), &game, SLOT(getInput(QString)));
    }

    black = true;
    //board 2
    j = 70*size +40;
    k = 0;
    scale *= size;
    for(i = 0; i < size*size; i++){

        QString spacename = spaces[scale +i];
        GUICell * cell = new GUICell(j,k,1);
        cell->setRect(j,k,70,70);
        if(i%size == 0){
            black = !black;
        }

        if (black)
        {
            cell->setBrush(Qt::lightGray);
        }
        black = !black;

        j += 70;
        if (j == 70*size+ 70*size +40)
        {
            j = 70*size +40;
            k += 70;
        }
        cell->setName(spacename);
        cellList.append(cell);
        DisplayScene->addItem(cell);
        QObject::connect(cell, SIGNAL(sendSignal(QString)), &game, SLOT(getInput(QString)));
    }
//    This for the 3rd board when we get there
//    j = 2 * (70*size +40);
//    k = 0;
//    scale *=size;
//    for(i = 0; i < size*size; i++){
//        QString spacename = spaces[scale +i];
//        GUICell * cell = new GUICell(j,k,2);
//        cell->setRect(j,k,70,70);
//        if(i%size == 0){
//            black = !black;
//        }

//        if (black)
//        {
//            cell->setBrush(Qt::lightGray);
//        }
//        black = !black;

//        j += 70;
//        if (j == 3 * (70 * size) + 80)
//        {
//            j = 2*(70*size+40);
//            k += 70;
//        }
//        cell->setName(spacename);
//        cellList.append(cell);
//        DisplayScene->addItem(cell);
//        QObject::connect(cell, SIGNAL(sendSignal(QString)), &game, SLOT(getInput(QString)));
//    }
}


//Chris
void Display::placePieces()
{
    //setup black pieces
    cellList[0]->setImage(":/images/resource/blkrook.png");
    cellList[5]->setImage(":/images/resource/blkrook.png");
    cellList[1]->setImage(":/images/resource/blkbishop.png");
    cellList[4]->setImage(":/images/resource/blkbishop.png");
    cellList[3]->setImage(":/images/resource/blkqueen.png");
    cellList[2]->setImage(":/images/resource/blkking.png");
    cellList[6]->setImage(":/images/resource/blkpawn.png");
    cellList[7]->setImage(":/images/resource/blkpawn.png");
    cellList[8]->setImage(":/images/resource/blkpawn.png");
    cellList[9]->setImage(":/images/resource/blkpawn.png");
    cellList[10]->setImage(":/images/resource/blkpawn.png");
    cellList[11]->setImage(":/images/resource/blkpawn.png");
    //setup white pieces
    cellList[71]->setImage(":/images/resource/whiterook.png");
    cellList[66]->setImage(":/images/resource/whiterook.png");
    cellList[70]->setImage(":/images/resource/whitebishop.png");
    cellList[67]->setImage(":/images/resource/whitebishop.png");
    cellList[69]->setImage(":/images/resource/whitequeen.png");
    cellList[68]->setImage(":/images/resource/whiteking.png");
    cellList[65]->setImage(":/images/resource/whitepawn.png");
    cellList[64]->setImage(":/images/resource/whitepawn.png");
    cellList[63]->setImage(":/images/resource/whitepawn.png");
    cellList[62]->setImage(":/images/resource/whitepawn.png");
    cellList[61]->setImage(":/images/resource/whitepawn.png");
    cellList[60]->setImage(":/images/resource/whitepawn.png");

}

//Chris
QGraphicsScene* Display::getScene()
{
    return DisplayScene;
}

//Chris
void Display::getResponse(QString response)
{
     std::string responseString = response.toStdString();
}

