
#ifndef CLION_SISTEMA_H
#define CLION_SISTEMA_H

#include "jugador.h"
#include <limits>

using namespace std;

class sistema {
private:
    bool funcionando;
    bool turno;
    bool barcos;
public:
    sistema();

    bool getFuncionando();
    void operator++();

    void limpiar();
    void graficar(jugador j, int l);
    void graficaCompleta(jugador j1, jugador j2, int l);

    void Inicio(int &l, bool &j);
    void filtrar(int l, jugador &j1, jugador &j2);

    void ingreseParaContinuar();

    bool coordenadaValida(int x, int y, int l);
    void corregirCoordenada(int &x, int &y, int rot);
    bool validarCoordenada(int l, int x, int y, int rot, int t, jugador j);

    bool validarAtaque(int l, int x, int y, jugador j);
    void actualizarBarcos(jugador &atacante, jugador &atacado);
    bool confirmarHundido(barco b);

    void etapaBarcos(int l, jugador &j);

    void condicionVictoria(jugador j1, jugador j2);

    // Jugador vs Jugador // Jugador vs CPU
    void ataque(int l, jugador &j1, jugador &j2);





};


#endif
