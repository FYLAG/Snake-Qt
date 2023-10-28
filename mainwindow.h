#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamewindow.h"
#include "presenter.h"

#include <QMainWindow>
#include <QSize>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {

    Q_OBJECT

public:

    MainWindow(GameWindow *gameWin, Presenter *presenter, QWidget *parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow *ui;

    GameWindow *gameWin;
    Presenter *presenter;

    QSize sizeArea;

private slots:

    void on_pushButton_play_clicked();
    void on_pushButton_quit_clicked();

};

#endif // MAINWINDOW_H
