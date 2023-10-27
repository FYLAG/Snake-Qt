#ifndef APPLE_H
#define APPLE_H

#include <QPoint>

class Apple {

public:

    Apple();

    QPoint getApple();
    void setApple(QPoint &point);

private:

    QPoint pointApple;

};

#endif // APPLE_H
