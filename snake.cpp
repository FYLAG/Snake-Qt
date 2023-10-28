#include "snake.h"

Snake::Snake(QPoint pointStart) {
    this->snakeBlocks.append(pointStart);
}

QPoint Snake::getPointSnake() {
    return *this->snakeBlocks.begin();
}

QVector<QPoint> Snake::getSnakeBlocks() {
    return this->snakeBlocks;
}

void Snake::addSnakeBlock() {
    this->snakeBlocks.append(this->pointOld);
}

void Snake::moveSnake(QPoint pointMove) {

    for (auto n = snakeBlocks.end(); n > snakeBlocks.begin(); n--) {

        *n = *(n - 1);

    }

    *snakeBlocks.begin() += pointMove;
    this->pointOld = *snakeBlocks.end();

}
