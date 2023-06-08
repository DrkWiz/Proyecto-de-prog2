#include "tablero.h"

tablero::tablero(int _l) {
    l = _l;
}



void tablero::setTablero() {

    columnas.resize(l);
    for (int i = 0; i < l; i++)
    {
        tabla.push_back(columnas);
    }

    for (int i = 0; i < l; i++) {

     for (int j = 0; j < l; j++)
     {
         tabla[i][j].setXY(i,j);
     }
    }


}

void tablero::llenarVector() {

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

casilla tablero::getCasilla(short pos1,short pos2) {
int i=pos1,j=pos2;
    return tabla[i][j];
}
//
//tablero::~tablero() {
//    for(casilla *p : casillas)
//    {
//        delete p;
//    }
//
//    casillas.clear();
//}
