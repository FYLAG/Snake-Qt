#include "gamewindow.h"
#include "ui_gamewindow.h"

#include <QDebug>

GameWindow::GameWindow(QSize _sizeArea, unsigned int _gameSpeed, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::GameWindow), sizeArea(_sizeArea), DELAY(200 * _gameSpeed) {

    ui->setupUi(this);

    ui->frameGamePause->hide();
    // ui->frameGameOver->hide();
    // ui->frameGameWin->hide();

    snakeMove = directionMove::Right;

    setFocusPolicy(Qt::StrongFocus);

    this->sizeBlockPixel = { 50, 50 };

    const QSize SIZE_WIN = sizeArea * sizeBlockPixel;

    this->resize(SIZE_WIN);
    this->setMinimumSize(SIZE_WIN);
    this->setMaximumSize(SIZE_WIN);

    this->setWindowTitle("Snake2D");

    this->gameOver = false;
    this->gameStop = false;
    this->keyFree = true;

    timerId = startTimer(DELAY);

}

GameWindow::~GameWindow() {
    delete ui;
}

void GameWindow::timerEvent(QTimerEvent *event) {

    Q_UNUSED(event);

    this->update();

    this->keyFree = true;
}

void GameWindow::keyPressEvent(QKeyEvent *event) {

    int key = event->key();

    if (key == Qt::Key_Escape) {
        eventGameStop();
    }

    if (key == Qt::Key_Up && snakeMove != directionMove::Down && keyFree) {

        snakeMove = directionMove::Up;
        keyFree = false;

    } else if (key == Qt::Key_Right && snakeMove != directionMove::Left && keyFree) {

        snakeMove = directionMove::Right;
        keyFree = false;

    } else if (key == Qt::Key_Down && snakeMove != directionMove::Up && keyFree) {

        snakeMove = directionMove::Down;
        keyFree = false;

    } else if (key == Qt::Key_Left && snakeMove != directionMove::Right && keyFree) {

        snakeMove = directionMove::Left;
        keyFree = false;

    }

}

void GameWindow::paintEvent(QPaintEvent *event) {

    emit signalFrameNext();

    Q_UNUSED(event);

}

bool GameWindow::getGameStop() {
    return this->gameStop;
}

QPoint GameWindow::initSnake() {

    QPoint pointCenter = {
        sizeArea.rwidth() / 2,
        sizeArea.rheight() / 2
    };

    return pointCenter;

}

QPoint GameWindow::initApple() {

    QPoint pointRandom = {
        QRandomGenerator::global()->bounded(0, sizeArea.rwidth()),
        QRandomGenerator::global()->bounded(0, sizeArea.rheight())
    };

    return pointRandom;

}

void GameWindow::drawGrid() {

    QPainter paint(this);
    QPen pen(QColor(225, 225, 225));

    pen.setWidth(1);
    paint.setPen(pen);

    for (int x = 1; x < sizeArea.width(); x++) {
            paint.drawLine(x * sizeBlockPixel.width(), 0,
                           x * sizeBlockPixel.width(), sizeArea.height() * sizeBlockPixel.height());
    }

    for (int y = 1; y < sizeArea.height(); y++) {
            paint.drawLine(0, y * sizeBlockPixel.height(),
                           sizeArea.width() * sizeBlockPixel.width(), y * sizeBlockPixel.height());
    }

}

void GameWindow::drawApple(QPoint applePoint) {

    QPainter paint(this);
    paint.setPen(Qt::transparent);
    paint.setBrush(QColor(225, 25, 25));

    paint.drawRect(applePoint.rx() * sizeBlockPixel.rwidth(),
                   applePoint.ry() * sizeBlockPixel.rheight(),
                   sizeBlockPixel.rwidth(),
                   sizeBlockPixel.rheight());

}

void GameWindow::drawSnake(QVector<QPoint> snakePoints) {

    QPainter paint(this);
    paint.setPen(Qt::transparent);
    paint.setBrush(QColor(100, 200, 0));

    for (QPoint n : snakePoints) {

            paint.drawRect(n.rx() * sizeBlockPixel.rwidth(),
                           n.ry() * sizeBlockPixel.rheight(),
                           sizeBlockPixel.rwidth(),
                           sizeBlockPixel.rheight());

    }

}

QPoint GameWindow::moveSnake() {

    switch(this->snakeMove) {

        case Up:
            return {0, -1};

        case Right:
            return {1, 0};

        case Down:
            return {0, 1};

        case Left:
            return {-1, 0};

        default:
            return {0, 0};

    }

}

bool GameWindow::checkMatchSnakeAndApple(QPoint snake, QPoint apple) {
    return snake == apple;
}

void GameWindow::eventGameContinue() {

    ui->frameGamePause->hide();
    timerId = startTimer(DELAY);
    this->gameStop = false;

}

void GameWindow::eventGameReset() {

    ui->frameGamePause->hide();
    timerId = startTimer(DELAY);

}

void GameWindow::eventGameStop() {

    killTimer(timerId);
    this->gameStop = true;
    ui->frameGamePause->show();

}

void GameWindow::eventGameOver() {

}

void GameWindow::eventGameWin() {

}

void GameWindow::on_pushButton_play_clicked() {
    eventGameContinue();
}


void GameWindow::on_pushButton_reset_clicked() {
    eventGameReset();
}


void GameWindow::on_pushButton_close_clicked() {
    this->close();
}

