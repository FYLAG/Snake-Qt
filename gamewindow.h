#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "iviewgame.h"
#include "presenter.h"

#include <QMainWindow>
#include <QKeyEvent>
#include <QPoint>
#include <QSize>

#include <QRandomGenerator>

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

    bool getGameStop() override;

    QPoint initSnake() override;
    QPoint initApple() override;

    void drawGrid() override;
    void drawApple(QPoint applePoint) override;
    void drawSnake(QVector<QPoint> snakePoints) override;

    QPoint moveSnake() override;

    bool checkMatchSnakeAndApple(QPoint snake, QPoint apple) override;

private:

    Ui::GameWindow *ui;

    QSize sizeArea;
    QSize sizeBlockPixel;

    const unsigned int DELAY;

    directionMove snakeMove;

    bool gameOver;
    bool gameStop;
    bool keyFree;

    int timerId;

    void eventGameContinue();
    void eventGameReset();
    void eventGameStop();
    void eventGameOver();
    void eventGameWin();

protected:

    void timerEvent(QTimerEvent*) override;
    void keyPressEvent(QKeyEvent*) override;
    void paintEvent(QPaintEvent*) override;

signals:
    /*! Signal to call a specific slot */
    void signalFrameNext() override;

private slots:
    void on_pushButton_play_clicked();
    void on_pushButton_reset_clicked();
    void on_pushButton_close_clicked();
};

#endif // GAMEWINDOW_H
