#include "display.h"
#include "guicell.h"
#include "instruction.h"
#include "qapplication.h"
#include "qcheckbox.h"
#include "qgraphicsitem.h"
#include "qgraphicsview.h"
#include <QObject>
#include <QBrush>
#include <QImage>
#include <QFont>
#include <QLabel>

int boardSize = 8;
//Chris
Display::Display()
{
    // Connect Game signal with Display slot
    QObject::connect(&game, SIGNAL(sendResponse(QString)), this, SLOT(getResponse(QString)));
    QObject::connect(&game, SIGNAL(sendMoves(QVector<int>)), this, SLOT(getMoves(QVector<int>)));
    DisplayScene = new QGraphicsScene();
    setup();

}

//Chris
//Sets up the display area for the game
void Display::setup()
{
    createBoards();
    createCapureArea();
    buttonAndTextLayout();
    placePieces();
}

//Chris
//Places piece images on the board
void Display::placePieces()
{

    if(boardSize==8){
    //    setup white pieces
        cellList[0]->setImage(":/images/resource/whiterook.png");
        cellList[7]->setImage(":/images/resource/whiterook.png");
        cellList[2]->setImage(":/images/resource/whitebishop.png");
        cellList[5]->setImage(":/images/resource/whitebishop.png");
        cellList[1]->setImage(":/images/resource/whiteknight.png");
        cellList[6]->setImage(":/images/resource/whiteknight.png");
        cellList[4]->setImage(":/images/resource/whitequeen.png");
        cellList[3]->setImage(":/images/resource/whiteking.png");
        cellList[14]->setImage(":/images/resource/whitepawn.png");
        cellList[15]->setImage(":/images/resource/whitepawn.png");
        cellList[8]->setImage(":/images/resource/whitepawn.png");
        cellList[9]->setImage(":/images/resource/whitepawn.png");
        cellList[10]->setImage(":/images/resource/whitepawn.png");
        cellList[11]->setImage(":/images/resource/whitepawn.png");
        cellList[12]->setImage(":/images/resource/whitepawn.png");
        cellList[13]->setImage(":/images/resource/whitepawn.png");


    //    setup black pieces
        cellList[191]->setImage(":/images/resource/blkrook.png");
        cellList[184]->setImage(":/images/resource/blkrook.png");
        cellList[189]->setImage(":/images/resource/blkbishop.png");
        cellList[186]->setImage(":/images/resource/blkbishop.png");
        cellList[190]->setImage(":/images/resource/blkknight.png");
        cellList[185]->setImage(":/images/resource/blkknight.png");
        cellList[188]->setImage(":/images/resource/blkqueen.png");
        cellList[187]->setImage(":/images/resource/blkking.png");
        cellList[176]->setImage(":/images/resource/blkpawn.png");
        cellList[177]->setImage(":/images/resource/blkpawn.png");
        cellList[178]->setImage(":/images/resource/blkpawn.png");
        cellList[179]->setImage(":/images/resource/blkpawn.png");
        cellList[180]->setImage(":/images/resource/blkpawn.png");
        cellList[181]->setImage(":/images/resource/blkpawn.png");
        cellList[182]->setImage(":/images/resource/blkpawn.png");
        cellList[183]->setImage(":/images/resource/blkpawn.png");

    }else if(boardSize == 6){

        // 6x6   setup white pieces
        cellList[0]->setImage(":/images/resource/whiterook.png");
        cellList[1]->setImage(":/images/resource/whitebishop.png");
        cellList[4]->setImage(":/images/resource/whitebishop.png");

        cellList[3]->setImage(":/images/resource/whitequeen.png");
        cellList[2]->setImage(":/images/resource/whiteking.png");
        cellList[5]->setImage(":/images/resource/whiterook.png");

        cellList[6]->setImage(":/images/resource/whitepawn.png");
        cellList[7]->setImage(":/images/resource/whitepawn.png");
        cellList[8]->setImage(":/images/resource/whitepawn.png");
        cellList[9]->setImage(":/images/resource/whitepawn.png");
        cellList[10]->setImage(":/images/resource/whitepawn.png");
        cellList[11]->setImage(":/images/resource/whitepawn.png");


    //    setup black pieces
        cellList[107]->setImage(":/images/resource/blkrook.png");
        cellList[102]->setImage(":/images/resource/blkrook.png");
        cellList[106]->setImage(":/images/resource/blkbishop.png");
        cellList[103]->setImage(":/images/resource/blkbishop.png");
        cellList[105]->setImage(":/images/resource/blkqueen.png");
        cellList[104]->setImage(":/images/resource/blkking.png");

        cellList[98]->setImage(":/images/resource/blkpawn.png");
        cellList[99]->setImage(":/images/resource/blkpawn.png");
        cellList[100]->setImage(":/images/resource/blkpawn.png");
        cellList[101]->setImage(":/images/resource/blkpawn.png");
        cellList[97]->setImage(":/images/resource/blkpawn.png");
        cellList[96]->setImage(":/images/resource/blkpawn.png");
    }
}

//Chris
//Resets board colors back to default if moves were highlighted
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
//Highlights a given set of cells based on the piece selected and its valid moves
void Display::highLightMoves(std::vector<int> moveList)
{
    for(unsigned int i = 0; i < moveList.size(); i++){
        cellList[moveList[i]]->setBrush(Qt::green);
    }
}

//Chris
//Resets display attributes to new game status
void Display::resetDisplay()
{
    //reset images for captures pieces
    for(int i = 0; i < 15; i++){
        whiteCaptures[i]->setImage("");
        blackCaptures[i]->setImage("");
    }
    int i = 0;
    //reset images in main boards based on the board size
    while(i < boardSize*boardSize * 3){
        cellList[i]->setImage("");
        i++;
    }
    QString s = QString::number(game.players[0]->getPoints());
    QString scoreText = "White score: " + s;
    scoreWhite->setPlainText(scoreText);
    QString s2 = QString::number(game.players[1]->getPoints());
    QString scoreText2 = "Black score: " + s2;
    scoreBlack->setPlainText(scoreText2);
    statusTracker->setPlainText("New Game Created");

    placePieces();
    resetColors();
}


//Chris
//Creates the board layout for the GUI, connecting the cells to the game object
void Display::createBoards()
{
    const int size = boardSize;
    int scale = size;
    int i = 0;
    int j = 0;
    int k = 0;
    bool black = true;
    QList<GUICell*> top, bot, mid;

    //Borders for each board to add depth
    if(boardSize ==8){
        QGraphicsRectItem * topBorder = new QGraphicsRectItem();
        topBorder->setRect(73,258, 569, 569);
        topBorder->setBrush(Qt::black);
        DisplayScene->addItem(topBorder);

        QGraphicsRectItem * midBorder = new QGraphicsRectItem();
        midBorder->setRect(673,258, 569, 569);
        midBorder->setBrush(Qt::black);
        DisplayScene->addItem(midBorder);

        QGraphicsRectItem * botBorder = new QGraphicsRectItem();
        botBorder->setRect(1273,258, 569, 569);
        botBorder->setBrush(Qt::black);
        DisplayScene->addItem(botBorder);
    }

    //Prints 3 boards and appropriately names then and adds them
    //to the cellList in the proper order for move checking
    j = 80;
    k = 260;
    int spacing = 600;
    for(i = 0; i < size*size; i++){
        QString spacenameTop, spacenameMid, spacenameBot;
        spacenameTop = spaces[i];
        spacenameMid = spaces[scale*scale+i];
        spacenameBot = spaces[scale*scale+scale*scale+i];

        GUICell * cellTop = new GUICell(j,k,0);
        cellTop->setRect(j,k,70,70);

        GUICell * cellMid = new GUICell(j+spacing,k,1);
        cellMid->setRect(j+spacing,k,70,70);

        GUICell * cellBot = new GUICell(j+spacing+spacing,k,2);
        cellBot->setRect(j+spacing*2, k,70,70);

        if(i%size == 0){
            black = !black;
        }

        if (black)
        {
            cellTop->setBrush(Qt::lightGray);
            cellMid->setBrush(Qt::lightGray);
            cellBot->setBrush(Qt::lightGray);
        }else{
            cellTop->setBrush(Qt::white);
            cellMid->setBrush(Qt::white);
            cellBot->setBrush(Qt::white);
        }

        //set default color to black or white (used for resetting the proper color scheme after a piece is moved
        cellTop->setColor(black);
        cellMid->setColor(black);
        cellBot->setColor(black);
        black = !black;

        j += 70;
        if (j == 70*size+80)
        {
            j = 80;
            k += 70;
        }
        cellTop->setName(spacenameTop);
        top.append(cellTop);
        DisplayScene->addItem(cellTop);
        QObject::connect(cellTop, SIGNAL(sendSignal(QString)), &game, SLOT(getInput(QString)));

        cellMid->setName(spacenameMid);
        mid.append(cellMid);
        DisplayScene->addItem(cellMid);
        QObject::connect(cellMid, SIGNAL(sendSignal(QString)), &game, SLOT(getInput(QString)));

        cellBot->setName(spacenameBot);
        bot.append(cellBot);
        DisplayScene->addItem(cellBot);
        QObject::connect(cellBot, SIGNAL(sendSignal(QString)), &game, SLOT(getInput(QString)));
    }
    //append them in board order for moving, move validation etc.
    for(int i = 0; i < top.size(); i++){
        cellList.append(top[i]);
    }
    top.clear();

    for(int i = 0; i < mid.size(); i++){
        cellList.append(mid[i]);
    }
    mid.clear();

    for(int i = 0; i < bot.size(); i++){
        cellList.append(bot[i]);
    }
    bot.clear();
}

//Chris
//Creates the capture pieces areas for each player
void Display::createCapureArea()
{
    int j = 80;
    int k = 130;
    int n = 1774;

    //setup white captured pieces
    for(int i = 0; i <15; i++){
        GUICell * cellWhite = new GUICell(j,k,5);
        whiteCaptures.push_back(cellWhite);
        cellWhite->setRect(j,k,0,0);
        DisplayScene->addItem(cellWhite);

        GUICell * cellBlack = new GUICell(n,k,5);
        blackCaptures.push_back(cellBlack);
        cellBlack->setRect(n,k,0,0);
        DisplayScene->addItem(cellBlack);

        j+=60;
        n-=60;
        if (j == 60*8 +80)
        {
            j = 80;
            n = 1774;
            k += 60;
        }
    }
}

//Chris
//This sets up the rest of the game window with buttons and text areas
void Display::buttonAndTextLayout()
{
    //place label roughly in center of window
    QLabel *logo = new QLabel(nullptr);
    logo->setAttribute(Qt::WA_TranslucentBackground);
    logo->setFixedHeight(200);
    logo->setFixedWidth(300);
    QPixmap pix(":/images/resource/transparentLogoSmall.png");
    // get label dimensions
    int h = logo->height();
    int w = logo->width();
    // set a scaled pixmap to a w x h window keeping its aspect ratio
    logo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    logo->setPixmap(pix);
    logo->move(880, 60);
    DisplayScene->addWidget(logo);

    //Adds score tracker texts
    QString s = QString::number(game.players[0]->getPoints());
    QString scoreText = "White score: " + s;
    scoreWhite = new QGraphicsTextItem();
    scoreWhite->setPlainText(scoreText);
    scoreWhite->setFont(QFont("times", 16));
    scoreWhite->setDefaultTextColor(Qt::white);
    scoreWhite->setPos(500, 230);
    DisplayScene->addItem(scoreWhite);

    QString s2 = QString::number(game.players[1]->getPoints());
    QString scoreText2 = "Black score: " + s2;
    scoreBlack = new QGraphicsTextItem();
    scoreBlack->setPlainText(scoreText2);
    scoreBlack->setFont(QFont("times", 16));
    scoreBlack->setDefaultTextColor(Qt::white);
    scoreBlack->setPos(1275, 230);
    DisplayScene->addItem(scoreBlack);

    //Adds the game status text
    QString status = "White's turn first.";
    statusTracker = new QGraphicsTextItem();
    statusTracker->setPlainText(status);
    statusTracker->setDefaultTextColor(Qt::white);
    statusTracker->setFont(QFont("times", 25));
    statusTracker->setPos(830,890);
    DisplayScene->addItem(statusTracker);


    //Add board labels
    QString boardName = "TOP BOARD";
    QGraphicsTextItem * topBoard = new QGraphicsTextItem();
    topBoard->setPlainText(boardName);
    topBoard->setFont(QFont("times", 20));
    topBoard->setDefaultTextColor(Qt::white);
    topBoard->setPos(300, 825);
    DisplayScene->addItem(topBoard);

    boardName = "MIDDLE BOARD";
    QGraphicsTextItem * midBoard = new QGraphicsTextItem();
    midBoard->setPlainText(boardName);
    midBoard->setFont(QFont("times", 20));
    midBoard->setDefaultTextColor(Qt::white);
    midBoard->setPos(860, 825);
    DisplayScene->addItem(midBoard);

    boardName = "BOTTOM BOARD";
    QGraphicsTextItem * botBoard = new QGraphicsTextItem();
    botBoard->setPlainText(boardName);
    botBoard->setFont(QFont("times", 20));
    botBoard->setDefaultTextColor(Qt::white);
    botBoard->setPos(1417, 825);
    DisplayScene->addItem(botBoard);


    //Added buttons for additional functionality

    exitButton = new QPushButton();
    exitButton->setGeometry(1720,910,120,35);
    exitButton->setText("Quit");
    QObject::connect(exitButton, SIGNAL(clicked()), this, SLOT(on_exitButton_clicked()));
    DisplayScene->addWidget(exitButton);

    newGameButton = new QPushButton();
    newGameButton->setGeometry(1570,910,120,35);
    newGameButton->setText("New Game");
    QObject::connect(newGameButton, SIGNAL(clicked()), this, SLOT(onNewGameClick()));
    DisplayScene->addWidget(newGameButton);

    infoButton = new QPushButton();
    infoButton->setGeometry(145, 910, 120, 35);
    infoButton->setText("Instructions");
    QObject::connect(infoButton, SIGNAL(clicked()), this, SLOT(onInfoButtonClick()));
    DisplayScene->addWidget(infoButton);


    //Setup a checkbox and location for it
    QPoint * point = new QPoint();
    point->setX(330);
    point->setY(923);
    QGraphicsTextItem * checkBoxText = new QGraphicsTextItem();
    checkBoxText->setPlainText("Show moves");
    checkBoxText->setPos(341, 913);
    checkBoxText->setFont(QFont("times", 14));
    checkBoxText->setDefaultTextColor(Qt::white);
    highLight = new QCheckBox();
    highLight->setChecked(true);
    highLight->setCheckable(true);
    highLight->move(*point);
    QObject::connect(highLight, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxChecked()));
    DisplayScene->addItem(checkBoxText);
    DisplayScene->addWidget(highLight);
}

//Chris
QGraphicsScene* Display::getScene()
{
    return DisplayScene;
}

//Chris
//This method updates the UI for every action the user makes in the game
void Display::getResponse(QString response)
{
    //qDebug() << response;
    std::string temp1 = response.toStdString();

    //check for checkmate, if its over, end the game
    if(temp1 == "Checkmate"){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(nullptr, "GAME OVER", "This game is over, would you like to play again?",
                                      QMessageBox::Yes | QMessageBox::No);

        if(reply == QMessageBox::Yes){
            game.resetGame();
            resetDisplay();
        }else{
             QApplication::quit();
        }

    }

    //resets colors if an invalid move was chosen
    if(temp1 == "Invalid"){
        resetColors();

    //a piece has been selected, iterate over its available moves
    }else if(temp1 == "Paint moves"){
        //once we have the vector ready, this method will access it and iterate over it
       // qDebug() << "attemping to paint moves";
        if(onCheckBoxChecked()){
            highLightMoves(possibleMoves);
        }


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
         QString temp2;

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
                temp2 = cellList[i]->getImage();
                cellList[i]->setImage(temp);
             }
         }


        //this might happen after game updates current player, so player color might seem backwards
        if(game.getCurrentPlayer()->color == BLACK){
            int i = 0;
            while(1){
                if(whiteCaptures[i]->getImage() ==""){
                    whiteCaptures[i]->setImage(temp2);
                    break;
                }
                i++;
            }

        }else{
            int i = 0;
            while(1){
                if(blackCaptures[i]->getImage() ==""){
                    blackCaptures[i]->setImage(temp2);
                    break;
                }
                i++;
            }
        }
        //image has been moved, reset move highlighting
         resetColors();

//        qDebug()<< "Player 1 score: " << game.players[0]->getPoints();
         QString s = QString::number(game.players[0]->getPoints());
         QString scoreText = "White score: " + s;
         scoreWhite->setPlainText(scoreText);
         QString s2 = QString::number(game.players[1]->getPoints());
         QString scoreText2 = "Black score: " + s2;
         scoreBlack->setPlainText(scoreText2);
         QString status;
         if(game.isCurrentPlayerInCheck()){
             if(game.currentPlayerIndex == 0){
                 status = "White is in check.";
             }else{
                 status = "Black is in check.";
             }
         }else if(game.currentPlayerIndex == 0){
             status = "White's move.";
         }else{
             status = "Black's move.";
         }
         statusTracker->setPlainText(status);
    }
}

//Chris
//Slot to update current possible moves from a selected piece
void Display::getMoves(QVector<int> moves)
{
    this->possibleMoves = std::vector<int>(moves.begin(), moves.end());
}

//Chris
//Method to confirm the user wants to exit application when hitting "Quit" button
void Display::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Quit Application", "Are you sure you want to exit the game?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }
}

//Chris
//New game button click asks for confirmation before reseting game state
void Display::onNewGameClick()
{

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Caution", "Are you sure you want to create a new game? This cannot be undone!", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes){
        game.resetGame();
        resetDisplay();
    }

}

//Chris
//TODO: Open window with instructions about the game, the app and maybe have some pictures to help demonstrate
void Display::onInfoButtonClick()
{
    //create infoWindow
    //instruction * window = new instruction();
   // window->show();
    QDesktopServices::openUrl(QUrl("https://en.wikipedia.org/wiki/Millennium_3D_chess", QUrl::TolerantMode));
}

//Chris
//Checkbox to enable/disable move options when a piece is selected
bool Display::onCheckBoxChecked()
{
    return highLight->isChecked();
}
