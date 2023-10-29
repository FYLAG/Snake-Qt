#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(GameWindow *gameWin, Presenter *presenter, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), gameWin(gameWin), presenter(presenter) {

    ui->setupUi(this);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_play_clicked() {

    this->gameWin = new GameWindow({21, 11}, 1);
    this->presenter = new Presenter(gameWin);

    this->gameWin->show();

    this->hide();

}

void MainWindow::on_pushButton_quit_clicked() {
    this->close();
}

