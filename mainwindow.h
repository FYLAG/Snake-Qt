#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamewindow.h"

#include <QMainWindow>
#include <QSize>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {

    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow *ui;

    GameWindow *game;

    QSize sizeArea;

private slots:

    void on_pushButton_play_clicked();
    void on_pushButton_quit_clicked();

};

#endif // MAINWINDOW_H
