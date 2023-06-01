#include "iostream"
#include "barco.h"
#include "tablero.h"
using namespace std;

int main(){

    tablero t(3);
    t.setTablero();

    for(int i = 0; i < 3; i++)
    {
        cout<<"("<<t.casillas[i]->getX()<<", "<<t.casillas[i]->getY()<<") "<<endl;
    }

    return 0;
}