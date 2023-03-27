TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bishop.cpp \
        boardcell.cpp \
        chessboard.cpp \
        chessgame.cpp \
        chesspiece.cpp \
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
    king.h \
    level.h \
    player.h \
    queen.h \
    rook.h
