#ifndef PRESENTER_H
#define PRESENTER_H

#include "iviewgame.h"
#include "snake.h"
#include "apple.h"

#include <QObject>

class Presenter : public QObject {

    Q_OBJECT

public:

    explicit Presenter(IViewGame *view, QObject *parent = nullptr);

private:

    IViewGame *view;
    Snake *snake;
    Apple *apple;

    void initSnake();
    void initApple();

private slots:

    void refreshView();

};

#endif // PRESENTER_H
