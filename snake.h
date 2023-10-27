#ifndef SNAKE_H
#define SNAKE_H

#include "gamewindow.h"

#include <QVector>
#include <QPoint>

class Snake {

public:

    Snake(QPoint pointBegin);

    QPoint getPointSnake();

    void addSnakeBlock();

    void moveSnake(QPoint pointMove);

private:

    QVector<QPoint> snakeBlocks;

};

#endif // SNAKE_H
