
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

int jugador::getPosF(int x, int y) {
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < flota[i].getSize(); j++)
        {
            if(flota[i].getX(j) == x && flota[i].getY(j) == y)
            {
                return i;
            }
        }
    }
    return 0;
}

void jugador::setBarcoH(bool _e, int posF) {
    flota[posF].setH(_e);
}
