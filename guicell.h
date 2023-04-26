#ifndef GUICELL_H
#define GUICELL_H

#include <QDebug>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QImage>
#include <QBrush>
#include <string>

class GUICell: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    GUICell(int x, int y, int boardLevel);
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void setName(QString n);
    QString getName();
    void setImage(QString path);
    QString getImage();
    void clearImage();
    void setColor(bool isBlack);
    bool getColor();

private:
    QString name;
    QGraphicsPixmapItem piece;
    QString image;
    int xCoord;
    int yCoord;
    bool isBlack;
    //Might change boardLevel to something else if it makes more sense
    int boardLevel;


signals:
    QString sendSignal(QString name);
};

#endif // GUICELL_H
