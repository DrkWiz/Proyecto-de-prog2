#include "tablero.h"

tablero::tablero(int _l) {
    l = _l;
}



void tablero::setTablero() {

    columnas.resize(l);

    for (int i = 0; i < l; i++) {
        tabla.push_back(columnas);
    }

    for (int i = 0; i < l; i++) {

        for (int j = 0; j < l; j++) {
            tabla[i][j].setXY(i, j);
        }
    }

}

void tablero::mostrar() {

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < tabla[i].size(); j++)
        {
            cout << "(" << tabla[i][j].getX() << ", " << tabla[i][j].getY() << "); ";
        }
        cout << endl;
    }

}

casilla tablero::getCasilla(int pos1, int pos2) {
    return tabla[pos1][pos2];
}

tablero::tablero() {
    l = 1;
}

void tablero::setL(int _l) {
    l = _l;
}
