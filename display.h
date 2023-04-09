#ifndef DISPLAY_H
#define DISPLAY_H

#include <QGraphicsScene>
#include <QObject>
#include <QtCore>
#include <QtGui>
#include "chessgame.h"


class Display: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene * DisplayScene;
    ChessGame game;
 //   QList<Space *> spaceList;
    QString move;
    void setup();
    void placePieces();
    Color turnColor;
    QGraphicsTextItem * turn;
    QGraphicsTextItem * check;

    const QString spaces[192] =
    {
 //bottomboard:
        "a80", "b80", "c80", "d80", "e80", "f80", "g80", "h80",
        "a70", "b70", "c70", "d70", "e70", "f70", "g70", "h70",
        "a60", "b60", "c60", "d60", "e60", "f60", "g60", "h60",
        "a50", "b50", "c50", "d50", "e50", "f50", "g50", "h50",
        "a40", "b40", "c40", "d40", "e40", "f40", "g40", "h40",
        "a30", "b30", "c30", "d30", "e30", "f30", "g30", "h30",
        "a20", "b20", "c20", "d20", "e20", "f20", "g20", "h20",
        "a10", "b10", "c10", "d10", "e10", "f10", "g10", "h10",
 //midboard:
        "a81", "b81", "c81", "d81", "e81", "f81", "g81", "h81",
        "a71", "b71", "c71", "d71", "e71", "f71", "g71", "h71",
        "a61", "b61", "c61", "d61", "e61", "f61", "g61", "h61",
        "a51", "b51", "c51", "d51", "e51", "f51", "g51", "h51",
        "a41", "b41", "c41", "d41", "e41", "f41", "g41", "h41",
        "a31", "b31", "c31", "d31", "e31", "f31", "g31", "h31",
        "a21", "b21", "c21", "d21", "e21", "f21", "g21", "h21",
        "a11", "b11", "c11", "d11", "e11", "f11", "g11", "h11",
//topboard:
        "a82", "b82", "c82", "d82", "e82", "f82", "g82", "h82",
        "a72", "b72", "c72", "d72", "e72", "f72", "g72", "h72",
        "a62", "b62", "c62", "d62", "e62", "f62", "g62", "h62",
        "a52", "b52", "c52", "d52", "e52", "f52", "g52", "h52",
        "a42", "b42", "c42", "d42", "e42", "f42", "g42", "h42",
        "a32", "b32", "c32", "d32", "e32", "f32", "g32", "h32",
        "a22", "b22", "c22", "d22", "e22", "f22", "g22", "h22",
        "a12", "b12", "c12", "d12", "e12", "f12", "g12", "h12"
    };

public:
    Display();
    QGraphicsScene* getScene();

public slots:
    void getResponse(QString response);
};


#endif // DISPLAY_H
