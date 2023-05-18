#include "coordenada.h"

coordenada::coordenada() {
    setX(0);
    setY(0);
}

coordenada::coordenada(short _x, short _y) {
    setX(_x);
    setY(_y);
}

void coordenada::setX(short _x) {
    x = _x;
}

void coordenada::setY(short _y) {
    y = _y;
}

short coordenada::getX() {
    return x;
}

short coordenada::getY() {
    return y;
}
