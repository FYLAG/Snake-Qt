#include "apple.h"

Apple::Apple(QPoint pointCreate) {
    this->pointApple = pointCreate;
}

QPoint Apple::getApple() {
    return this->pointApple;
}
