#ifndef COOR_H
#define COOR_H

class coordenada{
private:
    short x; // Valor X de la coordenada
    short y; // Valor Y de la coordenada
public:
    coordenada(); // Constructor basico (0, 0)
    coordenada(short _x, short _y); // Constructor basico (x, y)

    void setX(short _x); // Setea el valor X
    void setY(short _y); // Setea el valor Y

    short getX(); // Devuelve el valor de X
    short getY(); // Devuelve el valor de Y
};







#endif