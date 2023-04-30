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
//   QFile file(":/images/resource/millennium_3d_chess1556.pdf");
//   if(!file.open(QIODevice::ReadOnly)){
//       QMessageBox::information(nullptr, "Error", file.errorString());
//   }

//   QTextStream in(&file);
//    this->hide();
//   ui->textBrowser->setText(in.readAll());
    QDesktopServices::openUrl(QUrl("https://en.wikipedia.org/wiki/Millennium_3D_chess", QUrl::TolerantMode));

}

instruction::~instruction()
{
    delete ui;
}
