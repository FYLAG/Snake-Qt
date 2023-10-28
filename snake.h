#ifndef SNAKE_H
#define SNAKE_H

#include <QVector>
#include <QPoint>

class Snake {

public:

    Snake(QPoint pointStart);

    QPoint getPointSnake();

    QVector<QPoint> getSnakeBlocks();

    void addSnakeBlock();

    void moveSnake(QPoint pointMove);

private:

    QVector<QPoint> snakeBlocks;
    QPoint pointOld;

};

#endif // SNAKE_H
