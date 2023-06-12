
#ifndef CLION_SISTEMA_H
#define CLION_SISTEMA_H

#include "jugador.h"
#include <limits>

using namespace std;

class sistema {
private:
    bool funcionando;
    bool turno;
public:
    sistema();

    bool getFuncionando();
    void operator++();

    void limpiar();
    void graficar(jugador j, int l);
    int Inicio(int &l, bool &j);
    void filtrar(int l, jugador j1, jugador j2);

    bool coordenadaValida(int x, int y, int l);
    void corregirCoordenada(int &x, int &y, int rot);
    bool validarCoordenada(int l, int x, int y, int rot, int t, jugador j);
    // Jugador vs Jugador
    void etapaBarcos(int l, jugador &j);


    // Jugador vs CPU



};


#endif
