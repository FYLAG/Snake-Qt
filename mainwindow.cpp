#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

}

MainWindow::~MainWindow() {
    delete ui;
    delete game;
}

void MainWindow::on_pushButton_play_clicked() {

    this->game = new GameWindow({10, 10}, 1);

    this->game->show();

    this->hide();

}

void MainWindow::on_pushButton_quit_clicked() {
    this->close();
}

