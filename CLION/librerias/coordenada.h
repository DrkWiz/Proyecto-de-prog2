#ifndef COOR_H
#define COOR_H

class coordenada{
private:
    int x; // Valor X de la coordenada
    int y; // Valor Y de la coordenada
public:
    coordenada(); // Constructor basico (0, 0)
    coordenada(int _x, int _y); // Constructor basico (x, y)

    bool operator==(coordenada Y);


    void setX(int _x); // Setea el valor X
    void setY(int _y); // Setea el valor Y

    int getX(); // Devuelve el valor de X
    int getY(); // Devuelve el valor de Y
};







#endif