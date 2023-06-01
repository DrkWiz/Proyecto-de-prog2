#include "barco.h"

barco::barco(short _t) {
    setT(_t);
}

void barco::setT(short _t) {
    t = _t;
}

void barco::setBarco(coordenada x, short rot) {

    setXY(x);

    for(int i = 1; i < t; i++)
    {
        switch (rot) {
            case 0:
                setXY(x.getX() + i, x.getY());
                break;
            case 1:
                setXY(x.getX(), x.getY() + i);
                break;
            case 2:
                setXY(x.getX() - i, x.getY());
                break;
            case 3:
                setXY(x.getX(), x.getY() - i);
                break;
            default:
                break;
        }
    }
}

void barco::setXY(coordenada x) {
    posicion.emplace_back(x.getX(),x.getY());
    damaged.emplace_back(0);
}

void barco::setXY(short _x, short _y) {
    posicion.emplace_back(_x, _y);
    damaged.emplace_back(0);
}

coordenada barco::getXY(short pos) {
    return posicion[pos];
}

short barco::getX(short pos) {
    return posicion[pos].getX();
}

short barco::getY(short pos) {
    return posicion[pos].getY();
}

void barco::setEstado(bool _estado, short pos) {
    damaged[pos] = _estado;
}

bool barco::getEstado(short pos) {
    return damaged[pos];
}


