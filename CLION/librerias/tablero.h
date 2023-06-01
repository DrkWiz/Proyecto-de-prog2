#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "casilla.h"
using namespace std;

/*
    La idea del tablero es que contenga un vector[Xmax][Ymax] de casillas, ademas
    de metodos para administrarlas
 */

class tablero{
private:
    short l; // Valor maximo de las coordenadas (X, Y) del tablero.
    vector<vector<casilla>> casillas;
public:
    tablero();

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