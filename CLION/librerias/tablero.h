#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include <iostream>
#include "casilla.h"
using namespace std;

/*
    La idea del tablero es que contenga un vector[Xmax][Ymax] de casillas, ademas
    de metodos para administrarlas
 */

class tablero{
private:
    int l; // Valor maximo de las coordenadas (X, Y) del tablero.

    vector<vector<casilla>> tabla;
    vector<casilla> columnas;

public:
    tablero();
    tablero(int _l); // Constructor basico para el tablero

    void setL(int _l); // Setea el valor de l
    void setTablero(); // Crea e inicializa todas las casillas del tablero.
    void mostrar(); // Muestra todas las casillas del tablero con sus valores (X, Y)

    casilla getCasilla(int pos1, int pos2); // Devuelve una casilla
};

#endif
