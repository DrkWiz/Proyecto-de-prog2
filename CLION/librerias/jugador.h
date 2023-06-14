#ifndef CLION_JUGADOR_H
#define CLION_JUGADOR_H

#include "tablero.h"
#include "barco.h"

class jugador {
private:
    bool tipo; // 0 = CPU 1 = Persona
    tablero t; // El tablero del jugador
    vector<barco> flota; // La flota de 7 barcos del jugador, siendo:
                         // 1 de una casilla, 2 de dos casillas, 3 de tres casillas y 1 de 4 casillas.

    vector<coordenada> ataques; // Vector que almacena los ataques del jugador
public:

    jugador(int _l, bool _tipo); // Constructor del jugador

    void agregarAtq(int _x, int _y); // Agrega un ataque al final del vector
    coordenada getAtq(int pos); // Devuelve la coordenda de un ataque
    int getAtqSize(); // Devuelve el tamaño del vector de ataque
    casilla getCasilla(int _x, int _y); // Devuelve una casilla del tablero
    barco getBarco(int pos); // Devuelve un barco de la flota

    void setBarcoXY(int _x, int _y, int pos); // Ubica una casilla de un barco
    bool getTipo(); // Devuelve si el jugador es una persona o el CPU
    void setBarco(int _x, int _y,int rot, int pos); // Ubica un barco
    void setBarcoEstado(bool _e, int posF, int posB); // Cambia el estado de un barco de la flota
    void setBarcoH(bool _e, int posF); // Cambia si un barco de la flota esta hundido o no

    int getPosF(int x, int y); // Devuelve la posicion dentro del vector de flota
                               // para un barco con una casilla en esa coordenada
};


#endif //CLION_JUGADOR_H
