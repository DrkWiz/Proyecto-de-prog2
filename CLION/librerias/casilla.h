#ifndef CASILLA_H
#define CASILLA_H

#include "coordenada.h"

class casilla:public coordenada{
private:
    bool estado;
public:
    casilla();

    void setEstado(bool _estado);
    bool getEstado();

    bool checkearBarco(/*barco*/);
};



#endif