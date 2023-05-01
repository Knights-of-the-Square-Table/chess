#include "guicell.h"
#include <iostream>
#include <stdio.h>
#include <QDebug>

//Chris
GUICell::GUICell(int x, int y, int level)
{

    xCoord = x;
    yCoord = y;
    boardLevel = level;

    piece.setParentItem(this);

}
//Chris
//Used for detecting if the cell has been clicked
void GUICell::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    //Player must left click to emit signal
    if(e->buttons() == Qt::LeftButton){
         qDebug() << "You clicked " << name;
         setBrush(Qt::darkGreen);
         emit sendSignal(name);
    }
}

//Chris
void GUICell::setName(QString n)
{
    name = n;
}
//Chris
QString GUICell::getName()
{
    return name;
}
//Chris
void GUICell::setImage(QString path)
{
    image = path;
    piece.setPixmap(path);
    piece.setPos(xCoord, yCoord);
    piece.show();
}
//Chris
QString GUICell::getImage()
{
    return image;
}
//Chris
void GUICell::clearImage()
{
    piece.hide();
    this->setImage("");
}

//Chris
//Helper method for setting a default color for cells
void GUICell::setColor(bool isBlack)
{
    this->isBlack = isBlack;
}

//Chris
bool GUICell::getColor()
{
    return isBlack;
}
