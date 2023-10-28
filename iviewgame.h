#ifndef IVIEWGAME_H
#define IVIEWGAME_H

#include <QPoint>
#include <QVector>

class IViewGame {

public:

    virtual QPoint initSnake() = 0;
    virtual QPoint initApple() = 0; // &snakeBlocks

    virtual void drawGrid() = 0;
    virtual void drawApple(QPoint applePoint) = 0;
    virtual void drawSnake(QVector<QPoint> snakePoints) = 0;

    virtual QPoint moveSnake() = 0;

    virtual bool checkMatchSnakeAndApple(QPoint snake, QPoint apple) = 0;

public: // signals

    virtual void signalFrameNext() = 0;

};

#endif // IVIEWGAME_H
