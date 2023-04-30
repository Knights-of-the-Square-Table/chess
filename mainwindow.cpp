#include "mainwindow.h"
#include "display.h"
#include "qgraphicsview.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
 #include <QUrl>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_exitButton_clicked()
{
    exit(1);
}


void MainWindow::on_playButton_clicked()
{
    hide();
    view = new QGraphicsView(D->getScene());
   // view->setMaximumSize(1920, 1080);
 //   view->maximumSize();
    view->resize(1366,680);
   // view->resize(1920,1080);
    view->setBackgroundBrush(QBrush(QImage(":/images/resource/fullTable.jpg")));
    view->show();

}


void MainWindow::on_instructionsButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://en.wikipedia.org/wiki/Millennium_3D_chess", QUrl::TolerantMode));
}

