#include "display.h"
#include "guicell.h"
#include "qgraphicsitem.h"
#include "qgraphicsview.h"
#include <QObject>
#include <QBrush>
#include <QImage>


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
        }else{
            cell->setBrush(Qt::white);
        }

        //set default color to black or white (used for resetting the proper color scheme after a piece is moved
        cell->setColor(black);


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
        }else{
            cell->setBrush(Qt::white);
        }
        //set default color to black or white (used for resetting the proper color scheme after a piece is moved
        cell->setColor(black);

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
    j = 2 * (70*size +40);
    k = 0;
    scale += size*size;
    for(i = 0; i < size*size; i++){
        QString spacename = spaces[scale +i];
        GUICell * cell = new GUICell(j,k,2);
        cell->setRect(j,k,70,70);
        if(i%size == 0){
            black = !black;
        }

        if (black)
        {
            cell->setBrush(Qt::lightGray);
        }else{
            cell->setBrush(Qt::white);
        }

        //set default color to black or white (used for resetting the proper color scheme after a piece is moved
        cell->setColor(black);

        black = !black;

        j += 70;
        if (j == 3 * (70 * size) + 80)
        {
            j = 2*(70*size+40);
            k += 70;
        }
        cell->setName(spacename);
        cellList.append(cell);
        DisplayScene->addItem(cell);
        QObject::connect(cell, SIGNAL(sendSignal(QString)), &game, SLOT(getInput(QString)));
    }

    QString s = QString::number(game.players[0]->getPoints());
    QString scoreText = "Player 1 score: " + s;
    scoreWhite = new QGraphicsTextItem();
    scoreWhite->setPlainText(scoreText);
    scoreWhite->setPos(1200, 575);
    DisplayScene->addItem(scoreWhite);

    QString s2 = QString::number(game.players[1]->getPoints());
    QString scoreText2 = "Player 2 score: " + s2;
    scoreBlack = new QGraphicsTextItem();
    scoreBlack->setPlainText(scoreText2);
    scoreBlack->setPos(0, -30);
    DisplayScene->addItem(scoreBlack);
}


//Chris
void Display::placePieces()
{

//    //setup black pieces
//    cellList[0]->setImage(":/images/resource/blkrook.png");
//    cellList[7]->setImage(":/images/resource/blkrook.png");
//    cellList[1]->setImage(":/images/resource/blkbishop.png");
//    cellList[6]->setImage(":/images/resource/blkbishop.png");
//    cellList[2]->setImage(":/images/resource/blkknight.png");
//    cellList[5]->setImage(":/images/resource/blkknight.png");
//    cellList[3]->setImage(":/images/resource/blkqueen.png");
//    cellList[4]->setImage(":/images/resource/blkking.png");
//    cellList[14]->setImage(":/images/resource/blkpawn.png");
//    cellList[15]->setImage(":/images/resource/blkpawn.png");
//    cellList[8]->setImage(":/images/resource/blkpawn.png");
//    cellList[9]->setImage(":/images/resource/blkpawn.png");
//    cellList[10]->setImage(":/images/resource/blkpawn.png");
//    cellList[11]->setImage(":/images/resource/blkpawn.png");
//    cellList[12]->setImage(":/images/resource/blkpawn.png");
//    cellList[13]->setImage(":/images/resource/blkpawn.png");

    cellList[107]->setImage(":/images/resource/blkrook.png");
    cellList[102]->setImage(":/images/resource/blkrook.png");
    cellList[106]->setImage(":/images/resource/blkbishop.png");
    cellList[103]->setImage(":/images/resource/blkbishop.png");
    cellList[105]->setImage(":/images/resource/blkqueen.png");
    cellList[104]->setImage(":/images/resource/blkking.png");

//    //setup white pieces
//    cellList[191]->setImage(":/images/resource/whiterook.png");
//    cellList[184]->setImage(":/images/resource/whiterook.png");
//    cellList[190]->setImage(":/images/resource/whitebishop.png");
//    cellList[185]->setImage(":/images/resource/whitebishop.png");
//    cellList[189]->setImage(":/images/resource/whiteknight.png");
//    cellList[186]->setImage(":/images/resource/whiteknight.png");
//    cellList[187]->setImage(":/images/resource/whitequeen.png");
//    cellList[188]->setImage(":/images/resource/whiteking.png");
//    cellList[176]->setImage(":/images/resource/whitepawn.png");
//    cellList[177]->setImage(":/images/resource/whitepawn.png");
//    cellList[178]->setImage(":/images/resource/whitepawn.png");
//    cellList[179]->setImage(":/images/resource/whitepawn.png");
//    cellList[180]->setImage(":/images/resource/whitepawn.png");
//    cellList[181]->setImage(":/images/resource/whitepawn.png");
//    cellList[182]->setImage(":/images/resource/whitepawn.png");
//    cellList[183]->setImage(":/images/resource/whitepawn.png");

        cellList[0]->setImage(":/images/resource/whiterook.png");
        cellList[5]->setImage(":/images/resource/whiterook.png");
        cellList[1]->setImage(":/images/resource/whitebishop.png");
        cellList[4]->setImage(":/images/resource/whitebishop.png");
        cellList[3]->setImage(":/images/resource/whitequeen.png");
        cellList[2]->setImage(":/images/resource/whiteking.png");
}

//Chris
void Display::resetColors()
{
   for(int i = 0; i < cellList.size(); i++){
       if(cellList[i]->getColor()){
           cellList[i]->setBrush(Qt::lightGray);
       }else{
           cellList[i]->setBrush(Qt::white);
       }
   }
}

//Chris
void Display::highLightMoves(std::vector<int> moveList)
{
    for(unsigned int i = 0; i < moveList.size(); i++){
        cellList[moveList[i]]->setBrush(Qt::green);
    }
}

//Chris
QGraphicsScene* Display::getScene()
{
    return DisplayScene;
}

//Chris
void Display::getResponse(QString response)
{
    qDebug() << response;
    std::string temp1 = response.toStdString();
    //resets colors if an invalid move was chosen
    if(temp1 == "Invalid"){
        resetColors();

    //a piece has been selected, iterate over its available moves
    }else if(temp1 == "Paint moves"){
        //once we have the vector ready, this method will access it and iterate over it
        std::vector<int> moveList = {6, 12,18,24, 36, 72, 42, 84};
        highLightMoves(moveList);

    //the move was successful, perform the image swap
    }else{

         std::string responseString = response.toStdString();
         //qDebug() << "getResponse = " << response;
         QString firstSpace = "";
         QString secondSpace = "";
         firstSpace += response[0];
         firstSpace += response[1];
         firstSpace += response[2];
         secondSpace += response[3];
         secondSpace += response[4];
         secondSpace += response[5];
         QString temp;
        // qDebug() << "firstSpace: " << firstSpace;
         for (int i=0; i<cellList.length(); i++ )
         {
             if (cellList[i]->getName() == firstSpace)
             {
    //             qDebug() << "found the first cell";
                 temp = cellList[i]->getImage();
    //              qDebug() << "Temp: " << temp;
                 cellList[i]->clearImage();
             }
         }
         for (int i=0; i<cellList.length(); i++ )
         {
             if (cellList[i]->getName() == secondSpace)
             {
                 cellList[i]->setImage(temp);
             }
         }
         resetColors();
         //update score buggy, crashing when game.players[].getPoints() is called after a piece is taken
    //     qDebug()<< "Player 1 score: " << game.players[0]->getPoints();
         QString s = QString::number(game.players[0]->getPoints());
         QString scoreText = "Player 1 score: " + s;
         scoreWhite->setPlainText(scoreText);
         QString s2 = QString::number(game.players[1]->getPoints());
         QString scoreText2 = "Player 2 score: " + s2;
         scoreBlack->setPlainText(scoreText2);
    }
}

