#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "iviewgame.h"

#include <QMainWindow>
#include <QKeyEvent>
#include <QPoint>
#include <QSize>

#include <QPainter>
#include <QPaintEvent>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow, public IViewGame {

    Q_OBJECT

public:

    explicit GameWindow(QSize _sizeArea, unsigned int _gameSpeed, QWidget *parent = nullptr);
    ~GameWindow();

    enum directionMove { Up, Right, Down, Left };

    void drawGrid() override;
    void drawApple(QPoint applePoint) override;
    void drawSnake(QVector<QPoint> &snakePoints) override;

    QPoint moveSnake() override;

private:

    Ui::GameWindow *ui;

    QSize sizeArea;
    QSize sizeBlockPixel;

    const unsigned int DELAY;

    directionMove snakeMove;

protected:

    void timerEvent(QTimerEvent*) override;
    void keyPressEvent(QKeyEvent*) override;
    void paintEvent(QPaintEvent*) override;

signals:
    /*! Signal to call a specific slot */
    void signalFrameNext();

};

#endif // GAMEWINDOW_H
