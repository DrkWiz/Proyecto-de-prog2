//
// Created by nico on 08/06/23.
//

#include "jugador.h"

jugador::jugador(int _l, bool _tipo) {
    t.setL(_l);
    tipo = _tipo;

    flota.emplace_back(barco(1));
    flota.emplace_back(barco(2));
    flota.emplace_back(barco(2));
    flota.emplace_back(barco(3));
    flota.emplace_back(barco(3));
    flota.emplace_back(barco(3));
    flota.emplace_back(barco(4));

    t.setTablero();
}

void jugador::ubicarBarcos(int pos, int x, int y, int rot) {
    coordenada a(x,y);
    flota[pos].setBarco(a,rot);

}

void jugador::ubicarBarcos(int pos, coordenada x, int rot) {
    flota[pos].setBarco(x, rot);
}

casilla jugador::getCasilla(int _x, int _y) {
    return t.getCasilla(_x,_y);
}

barco jugador::getBarco(int pos) {
    return flota[pos];
}

bool jugador::getTipo() {
    return tipo;
}

void jugador::setBarcoXY(int _x, int _y, int pos) {
    flota[pos].setXY(_x,_y);
}

void jugador::setBarco(int _x, int _y, int rot, int pos) {
    setBarcoXY(_x,_y, pos);

    for(int i = 1; i < flota[pos].getT(); i++)
    {
        switch (rot) {
            case 0:
                setBarcoXY(_x + i, _y, pos);
                break;
            case 1:
                setBarcoXY(_x, _y + i, pos);
                break;
            case 2:
                setBarcoXY(_x - i, _y, pos);
                break;
            case 3:
                setBarcoXY(_x, _y - i, pos);
                break;
            default:
                break;
        }
    }
}

int jugador::getAtqSize() {
    return ataques.size();
}

coordenada jugador::getAtq(int pos) {
    return ataques[pos];
}

void jugador::agregarAtq(int _x, int _y) {
    coordenada X(_x,_y);
    ataques.emplace_back(X);
}

void jugador::setBarcoEstado(bool _e, int posF, int posB) {
    flota[posF].setEstado(_e, posB);
}
