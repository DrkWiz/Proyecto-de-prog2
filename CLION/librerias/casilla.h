#ifndef CASILLA_H
#define CASILLA_H

#include "coordenada.h"
#include "barco.h"

class casilla:public coordenada{

    // Casilla hereda de coordenada, por lo tanto tambien tiene los atributos (X, Y)
private:
    bool estado; // Estado de la casilla, 0 = agua, 1 = barco.
public:
    casilla(); // Constructor basico coor=(0, 0), estado=0

    void setEstado(bool _estado); // Setea el estado
    bool getEstado(); // Devuelve el estado

    void setXY(coordenada x);
    void setXY(short _x, short _y);
};



#endif