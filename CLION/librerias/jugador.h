#ifndef CLION_JUGADOR_H
#define CLION_JUGADOR_H

#include "tablero.h"
#include "barco.h"

class jugador {
private:
    bool tipo; // 0 = CPU 1 = Persona
    tablero t;
    vector<barco> flota;

public:
    jugador(int _l, bool _tipo);

    void ubicarBarcos(int pos, int x, int y, int rot);
    void ubicarBarcos(int pos, coordenada x, int rot);

    casilla getCasilla(int _x, int _y);
    barco getBarco(int pos);
    void setBarcoXY(int _x, int _y, int pos);
    bool getTipo();
    void setBarco(int _x, int _y,int rot, int pos);
};


#endif //CLION_JUGADOR_H
