#include "guicell.h"



GUICell::GUICell(int x, int y, int level)
{

    xCoord = x;
    yCoord = y;
    boardLevel = level;

    piece.setParentItem(this);

}

void GUICell::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    //Player must left click to emit signal
    if(e->buttons() == Qt::LeftButton){
         qDebug() << "You clicked " << name;
         emit sendSignal(name);
    }



}

void GUICell::setName(QString n)
{
    name = n;
}

QString GUICell::getName()
{
    return name;
}

void GUICell::setImage(QString path)
{
    image = path;
    piece.setPixmap(path);
    piece.setPos(xCoord, yCoord);
    piece.show();
}

QString GUICell::getImage()
{
    return image;
}

void GUICell::clearImage()
{
    piece.hide();
}
