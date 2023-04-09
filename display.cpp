#include "display.h"
#include "qgraphicsitem.h"
#include "qgraphicsview.h"
#include <QObject>

Display::Display()
{
    // Connect Game signal with Display slot
 //   QObject::connect((&game, SIGNAL(sendResponse(QString)), this, SLOT(getResponse(QString))));
    DisplayScene = new QGraphicsScene();

    setup();

   // placePieces();
}

void Display::getResponse(QString response)
{
     std::string responseString = response.toStdString();
}

void Display::setup()
{

    const int size = 6;
    //i = square, j = x pos, k = y pos
    int i = 0;
    int j = 0;
    int k = 0;
    bool black = true;
    //board 1
    for(i = 0; i < size*size; i++){
        QGraphicsRectItem * cell =  new QGraphicsRectItem();

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
        DisplayScene->addItem(cell);
    }

    black = true;

    j = 70*size +40;
    k = 0;
    for(i = 0; i < size*size; i++){
        QGraphicsRectItem * cell =  new QGraphicsRectItem();
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

        DisplayScene->addItem(cell);
    }
//    This for the 3rd board when we get there
//    j = 2 * (70*size +40);
//    k = 0;
//    for(i = 0; i < size*size; i++){
//        QGraphicsRectItem * cell =  new QGraphicsRectItem();
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

//        DisplayScene->addItem(cell);
//    }
}

void Display::placePieces()
{

}
QGraphicsScene* Display::getScene()
{
    return DisplayScene;
}

