#ifndef BARCO_H
#define BARCO_H

#include "coordenada.h"
#include <vector>

class barco {
private:
    short t;
    std::vector<coordenada> posicion;
    std::vector<bool> damaged;

public:
    barco(short _t);


    void setT(short _t);
    void setXY(coordenada x);
    void setXY(short _x, short _y);

    coordenada getXY(short pos);
    short getX(short pos);
    short getY(short pos);

    void setBarco(coordenada x, short rot);

};


#endif
