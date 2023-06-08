#include "barco.h"

barco::barco(int _t) {
    t = _t;
}

void barco::setT(int _t) {
    t = _t;
}

void barco::setBarco(coordenada x, int rot) {

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

void barco::setXY(int _x, int _y) {
    posicion.emplace_back(_x, _y);
    damaged.emplace_back(0);
}

coordenada barco::getXY(int pos) {
    return posicion[pos];
}

int barco::getX(int pos) {
    int x = posicion[pos].getX();
    return x;
}

int barco::getY(int pos) {
    return posicion[pos].getY();
}

void barco::setEstado(bool _estado, int pos) {
    damaged[pos] = _estado;
}

bool barco::getEstado(int pos) {
    return damaged[pos];
}

int barco::getT() {
    return t;
}

int barco::getSize() {
    return posicion.size();
}


