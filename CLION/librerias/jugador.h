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

};


#endif //CLION_JUGADOR_H
