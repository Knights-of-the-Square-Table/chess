#ifndef DISPLAY_H
#define DISPLAY_H

#include <QGraphicsScene>
#include <QObject>
#include <QtCore>
#include <QtGui>
#include "chessgame.h"
#include "guicell.h"
#include <QMessageBox>
#include <QPushButton>
#include <QWidget>
#include <QApplication>

//Chris
class Display: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene * DisplayScene;
    ChessGame game;
    QList<GUICell *> cellList;
    QString move;
    void setup();
    void placePieces();
    void resetColors();
    void highLightMoves(std::vector<int> moveList);
    std::vector<int> possibleMoves;

    std::vector<GUICell*> whiteCaptures;
    std::vector<GUICell*> blackCaptures;
    Color turnColor;
    QGraphicsTextItem * turn;
    QGraphicsTextItem * check;
    QGraphicsTextItem * scoreWhite;
    QGraphicsTextItem * scoreBlack;

    QPushButton *exitButton, *menuButton;

    void createBoards();
    void createCapureArea();
    void buttonAndTextLayout();
  //  void placePieces();

    const QString spaces[192] =
    {
 //QString identities for each space for the 3 boards
        //8x8

// //topBoard:
        "a02", "b02", "c02", "d02", "e02", "f02", "g02", "h02",
        "a12", "b12", "c12", "d12", "e12", "f12", "g12", "h12",
        "a22", "b22", "c22", "d22", "e22", "f22", "g22", "h22",
        "a32", "b32", "c32", "d32", "e32", "f32", "g32", "h32",
        "a42", "b42", "c42", "d42", "e42", "f42", "g42", "h42",
        "a52", "b52", "c52", "d52", "e52", "f52", "g52", "h52",
        "a62", "b62", "c62", "d62", "e62", "f62", "g62", "h62",
        "a72", "b72", "c72", "d72", "e72", "f72", "g72", "h72",
// midboard:
        "a01", "b01", "c01", "d01", "e01", "f01", "g01", "h01",
        "a11", "b11", "c11", "d11", "e11", "f11", "g11", "h11",
        "a21", "b21", "c21", "d21", "e21", "f21", "g21", "h21",
        "a31", "b31", "c31", "d31", "e31", "f31", "g31", "h31",
        "a41", "b41", "c41", "d41", "e41", "f41", "g41", "h41",
        "a51", "b51", "c51", "d51", "e51", "f51", "g51", "h51",
        "a61", "b61", "c61", "d61", "e61", "f61", "g61", "h61",
        "a71", "b71", "c71", "d71", "e71", "f71", "g71", "h71",
//  botboard:
        "a00", "b00", "c00", "d00", "e00", "f00", "g00", "h00",
        "a10", "b10", "c10", "d10", "e10", "f10", "g10", "h10",
        "a20", "b20", "c20", "d20", "e20", "f20", "g20", "h20",
        "a30", "b30", "c30", "d30", "e30", "f30", "g30", "h30",
        "a40", "b40", "c40", "d40", "e40", "f40", "g40", "h40",
        "a50", "b50", "c50", "d50", "e50", "f50", "g50", "h50",
        "a60", "b60", "c60", "d60", "e60", "f60", "g60", "h60",
        "a70", "b70", "c70", "d70", "e70", "f70", "g70", "h70",


    };
    //6x6 boardsetup
    const QString spaces2[108] ={
        //top board
        "a02", "b02", "c02", "d02", "e02", "f02",
        "a12", "b12", "c12", "d12", "e12", "f12",
        "a22", "b22", "c22", "d22", "e22", "f22",
        "a32", "b32", "c32", "d32", "e32", "f32",
        "a42", "b42", "c42", "d42", "e42", "f42",
        "a52", "b52", "c52", "d52", "e52", "f52",
//        //midboard:

        "a01", "b01", "c01", "d01", "e01", "f01",
        "a11", "b11", "c11", "d11", "e11", "f11",
        "a21", "b21", "c21", "d21", "e21", "f21",
        "a31", "b31", "c31", "d31", "e31", "f31",
        "a41", "b41", "c41", "d41", "e41", "f41",
        "a51", "b51", "c51", "d51", "e51", "f51",
//        //botboard:

        "a00", "b00", "c00", "d00", "e00", "f00",
        "a10", "b10", "c10", "d10", "e10", "f10",
        "a20", "b20", "c20", "d20", "e20", "f20",
        "a30", "b30", "c30", "d30", "e30", "f30",
        "a40", "b40", "c40", "d40", "e40", "f40",
        "a50", "b50", "c50", "d50", "e50", "f50",

    };

public:
    Display();
    QGraphicsScene* getScene();


public slots:
    void getResponse(QString response);
    void getMoves(QVector<int> moves);
    void on_exitButton_clicked();
    void onMenuButtonClick();
};


#endif // DISPLAY_H
