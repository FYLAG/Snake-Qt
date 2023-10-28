#ifndef APPLE_H
#define APPLE_H

#include <QPoint>

class Apple {

public:

    Apple(QPoint pointCreate);

    QPoint getApple();
    void setApple(QPoint &point);

private:

    QPoint pointApple;

};

#endif // APPLE_H
