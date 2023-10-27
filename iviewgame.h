#ifndef IVIEWGAME_H
#define IVIEWGAME_H

#include <QPoint>
#include <QVector>

class IViewGame {

public:

    // virtual void setApple(QPoint &point) = 0;
    // virtual QPoint getApple() = 0;

    virtual void drawGrid() = 0;
    virtual void drawApple(QPoint applePoint) = 0;
    virtual void drawSnake(QVector<QPoint> &snakePoints) = 0;

    virtual QPoint moveSnake() = 0;

public: // signals

};

#endif // IVIEWGAME_H
