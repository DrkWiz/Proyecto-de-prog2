#ifndef BARCO_H
#define BARCO_H

#include "coordenada.h"
#include <vector>


/* La idea es que barco contenga su propio vector de coordenadas y otro vector que lo acompañe sobre el estado
de cada coordenada, entonces se actualiza el estado si es dañado*/

class barco {
private:
    int t; // tamaño
    std::vector<coordenada> posicion; // coordenadas del barco
    std::vector<bool> damaged; // estado de cada coordenada, 0 = bien, 1 = dañado


public:
    barco(int _t); // Constructor

    void setXY(coordenada x); // Crea una coordenada al final del vector y setear el estado a 0.
    void setXY(int _x, int _y); // Crear coordenada al final del vector a traves de dos int,
                                    // ademas de setear el estado 0

    void setT(int _t); // Setear tamaño
    // Setea el estado de una casilla, pos hace referencia a la posicion dentro del vector
    void setEstado(bool _estado, int pos);



    coordenada getXY(int pos); // Devuelve un par de coordenadas, pos es la posicion del dato en el vector
    int getX(int pos); // Devuelve la coordenada X.
    int getY(int pos); // Devuelve la coordenada Y.
    bool getEstado(int pos); // Devuelve el estado de ese par de coordenadas
    int getT();
    int getSize();
    // Construye un barco de tamaño t a partir de la coordenada inicial X y una direccion para armarlo.
    void setBarco(coordenada x, int rot);

};


#endif
