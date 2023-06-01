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
    short l; // Valor maximo de las coordenadas (X, Y) del tablero.
    vector<casilla*> casillas;

    void setL(short _l); // Setea l
public:
    tablero(short _l); // Constructor basico para el tablero

    void setTablero(); // Crea e inicializa todas las casillas del tablero.
    void mostrar();

    void llenarVector();
    casilla getCasilla(short pos1, short pos2);

    ~tablero();
};

#endif


/* graficar(){
    int l = 9;

    for(int i = -1; i < l; i++)
             {
                         for(int j = -1; j < l; j++)
                         {
                                  if(i == -1 && j > -1){
                                          cout<<j<<"  ";
                                      }else if(j == -1 && i > -1){
                                          cout<<i<<"  ";
                                      }else if(j == 4 && i == 4){
                                            cout<<"X  ";
                                  }
                                  else {
                                          cout<<"~  ";
                                      }

                                     }
                         cout<<endl;
                     }
  }

}*/