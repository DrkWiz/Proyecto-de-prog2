#include "casilla.h"

casilla::casilla() {
    coordenada();
    setEstado(false);
}

void casilla::setEstado(bool _estado) {
    estado = _estado;
}

bool casilla::getEstado() {
    return estado;
}

void casilla::setXY(coordenada x) {
    setX(x.getX());
    setY(x.getY());
}

void casilla::setXY(short _x, short _y) {
    setX(_x);
    setY(_y);
}

