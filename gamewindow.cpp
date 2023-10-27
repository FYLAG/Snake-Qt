#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QSize _sizeArea, unsigned int _gameSpeed, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::GameWindow), sizeArea(_sizeArea), DELAY(100 * _gameSpeed) {

    ui->setupUi(this);
    ui->frame->hide();

    snakeMove = directionMove::Right;

    this->sizeBlockPixel = { 50, 50 };

    this->setWindowTitle("Snake2D");

    const QSize SIZE_WIN = sizeArea * sizeBlockPixel;

    this->resize(SIZE_WIN);
    this->setMinimumSize(SIZE_WIN);
    this->setMaximumSize(SIZE_WIN);

    startTimer(DELAY);

}

GameWindow::~GameWindow() {
    delete ui;
}

void GameWindow::timerEvent(QTimerEvent *event) {

    Q_UNUSED(event);

    emit signalFrameNext();

}

void GameWindow::keyPressEvent(QKeyEvent *event) {

    int key = event->key();

    switch (key) {

        case Qt::Key_Up:
            snakeMove = directionMove::Up;
            break;

        case Qt::Key_Right:
            snakeMove = directionMove::Right;
            break;

        case Qt::Key_Down:
            snakeMove = directionMove::Down;
            break;

        case Qt::Key_Left:
            snakeMove = directionMove::Left;
            break;

        default:
            break;

    }

}

void GameWindow::paintEvent(QPaintEvent *event) {

    drawGrid();

    // drawApple(QPoint applePoint)

    // drawSnake(QVector<QPoint> &snakePoints);

    Q_UNUSED(event);

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
    paint.setBrush(QColor(225, 25, 25));

    paint.drawRect(applePoint.rx(), applePoint.ry(),
                   sizeBlockPixel.rwidth(), sizeBlockPixel.rheight());

}

void GameWindow::drawSnake(QVector<QPoint> &snakePoints) {

    QPainter paint(this);
    paint.setBrush(QColor(100, 200, 0));

    for (QPoint n : snakePoints) {

            paint.drawRect(n.rx(), n.ry(),
                           sizeBlockPixel.rwidth(), sizeBlockPixel.rheight());

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

