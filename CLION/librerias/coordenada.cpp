#include "coordenada.h"

coordenada::coordenada() {
    setX(0);
    setY(0);
}

coordenada::coordenada(int _x, int _y) {
    setX(_x);
    setY(_y);
}

void coordenada::setX(int _x) {
    x = _x;
}

void coordenada::setY(int _y) {
    y = _y;
}

int coordenada::getX() {
    return x;
}

int coordenada::getY() {
    return y;
}
