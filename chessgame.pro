QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += console c++17
#CONFIG -= app_bundle
#CONFIG -= qt

#QT       += core gui

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chessgame
#TEMPLATE = app

SOURCES += \
        bishop.cpp \
        boardcell.cpp \
        chessboard.cpp \
        chessgame.cpp \
        chesspiece.cpp \
        display.cpp \
        guicell.cpp \
        king.cpp \
        knight.cpp \
        main.cpp \
        mainwindow.cpp \
        pawn.cpp \
        player.cpp \
        queen.cpp \
        rook.cpp

HEADERS += \
    bishop.h \
    boardcell.h \
    chessboard.h \
    chessgame.h \
    chesspiece.h \
    color.h \
    display.h \
    guicell.h \
    king.h \
    knight.h \
    level.h \
    mainwindow.h \
    pawn.h \
    player.h \
    queen.h \
    rook.h

RESOURCES += \
    rsc.qrc

FORMS += \
    mainwindow.ui
