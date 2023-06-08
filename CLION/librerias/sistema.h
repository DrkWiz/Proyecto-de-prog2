
#ifndef CLION_SISTEMA_H
#define CLION_SISTEMA_H

#include "jugador.h"

using namespace std;

class sistema {
private:
    bool funcionando;
    bool turno;
public:
    sistema();

    bool getFuncionando();
    void operator++();

    void graficar(jugador j, int l);

};


#endif
