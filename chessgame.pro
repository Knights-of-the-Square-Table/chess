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
        king.cpp \
        main.cpp \
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
    king.h \
    level.h \
    player.h \
    queen.h \
    rook.h

RESOURCES += \
    rsc.qrc
