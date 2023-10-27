#include "snake.h"

Snake::Snake(QPoint pointBegin) {

    this->snakeBlocks.append(pointBegin);

}

QPoint Snake::getPointSnake() {

    return *this->snakeBlocks.begin();

}

void Snake::addSnakeBlock() {

}

void Snake::moveSnake(QPoint pointMove) {

    for (auto n = snakeBlocks.rbegin(); n > snakeBlocks.rend(); n++) {

        *n = *(n + 1);

    }

    *snakeBlocks.begin() = pointMove;

}
