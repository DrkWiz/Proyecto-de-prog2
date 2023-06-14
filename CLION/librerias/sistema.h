
#ifndef CLION_SISTEMA_H
#define CLION_SISTEMA_H

#include "jugador.h"
#include <limits>

using namespace std;
/*
    La idea de esta clase es que funcione como intermediaria para manejar las interacciones de los demas objetos
    esencialmente para reducir la main a solo metodos de esta clase
 */
class sistema {
private:
    bool funcionando; // Atributo que define si el sistema esta "funcionando"
    bool barcos; // Atributo que define si ya se realizó la etapa de barcos
public:
    sistema(); // Constructor de sistema

    bool getFuncionando(); // Devuelve el valor de funcionando

    void limpiar(); // Ejecuta 'cls' o 'clear' en la consola
    void ingreseParaContinuar(); // Pide que se ingrese un dato para que el programa continue

    void graficar(jugador j, int l); // Grafica un tablero con solo los barcos de un jugador

    // Grafica un tablero con los barcos de un jugador, los disparos del enemigo y los disparos del jugador
    void graficaCompleta(jugador j1, jugador j2, int l);

    void Inicio(int &l, bool &j); // Un menu inicial para cambiar el tablero y elegir el modo de juego
    void filtrar(int l, jugador &j1, jugador &j2); // Funcion principal para el funcionamiento del juego

    bool coordenadaValida(int x, int y, int l); // Revisa si la coordenada esta dentro del tablero
    bool validarCoordenada(int l, int x, int y, int rot, int t, jugador j); // Revisa si la coordenada se choca
                                                                            // con otro barco o si se sale del tablero
    bool validarAtaque(int l, int x, int y, jugador j); // Revisa si el ataque es repetido o si cae afuera
    void actualizarBarcos(jugador &atacante, jugador &atacado); // Actualiza el estado de la flota de un jugador
    bool confirmarHundido(barco b); // Revisa si el barco esta hundido

    void etapaBarcos(int l, jugador &j); // Etapa para ubicar todos los barcos de un jugador

    void condicionVictoria(jugador j1, jugador j2); // Revisa si algun jugador ya hundió todos los barcos

    void ataque(int l, jugador &j1, jugador &j2); // Etapa para el ataque de un jugador hacia otro
};


#endif
