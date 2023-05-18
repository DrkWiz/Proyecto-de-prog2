#ifndef COOR_H
#define COOR_H

class coordenada{
private:
    short x;
    short y;
public:
    coordenada();
    coordenada(short _x, short _y);

    void setX(short _x);
    void setY(short _y);

    short getX();
    short getY();
};







#endif