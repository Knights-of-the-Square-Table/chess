#include "instruction.h"
#include "ui_instruction.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QUrl>
#include <stdlib.h>
#include "mainwindow.h"

//Chris
//TODO adjust so it opens the pdf to the instructions to millenium 3D chess.
instruction::instruction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instruction)
{
    ui->setupUi(this);

    QDesktopServices::openUrl(QUrl("https://en.wikipedia.org/wiki/Millennium_3D_chess", QUrl::TolerantMode));
}

instruction::~instruction()
{
    delete ui;
}
