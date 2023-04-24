#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Display.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_exitButton_clicked();

    void on_playButton_clicked();

    void on_instructionsButton_clicked();

private:
    Ui::MainWindow *ui;
    Display *D = new Display();
};
#endif // MAINWINDOW_H
