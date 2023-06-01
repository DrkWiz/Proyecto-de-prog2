#include "tablero.h"
tablero::tablero(short _l) {
    setL(l);
}

void tablero::setL(short _l) {
    l = _l;
}

void tablero::setTablero() {

    for(int i = 0; i < l; i++)
    {
        casillas.emplace_back(new casilla);
    }

}

void tablero::llenarVector() {

}

void tablero::mostrar() {

    for(short i = 0; i < l; i++)
    {
        for(short j = 0; j < l; j++)
        {
            cout<<"( "<<casillas[i][j].getX()<<", "<<casillas[i][j].getY()<<")";
        }
    }

}

casilla tablero::getCasilla(short pos1,short pos2) {
int i=pos1,j=pos2;
    return casillas[i][j];
}

tablero::~tablero() {
    for(casilla *p : casillas)
    {
        delete p;
    }

    casillas.clear();
}
