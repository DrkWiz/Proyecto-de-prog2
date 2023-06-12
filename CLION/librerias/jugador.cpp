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
