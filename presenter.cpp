#include "presenter.h"

#include <QDebug>

Presenter::Presenter(IViewGame *view, QObject *parent)
    : QObject(parent), view(view), snake(nullptr), apple(nullptr) {

    QObject *viewObject = dynamic_cast<QObject*>(this->view);
    QObject::connect(viewObject, SIGNAL(signalFrameNext()), this, SLOT(refreshView()));

}

void Presenter::initSnake() {

    this->snake = new Snake(this->view->initSnake());
    this->view->initSnake();

}

void Presenter::initApple() {

    this->apple = new Apple(this->view->initApple());
    this->view->initApple();

}

void Presenter::refreshView() {

    view->drawGrid();

    if (this->apple == nullptr) {

        this->initApple();

    } else {

        view->drawApple(apple->getApple());

    }

    if (this->snake == nullptr) {

        this->initSnake();

    } else {

        if (!this->view->getGameStop()) {

            this->snake->moveSnake(view->moveSnake());

            if (this->view->checkMatchSnakeAndApple(snake->getPointSnake(), apple->getApple())) {

                this->snake->addSnakeBlock();

                delete this->apple;
                this->apple = new Apple(this->view->initApple());

            }

        }

        view->drawSnake(snake->getSnakeBlocks());

    }

}

