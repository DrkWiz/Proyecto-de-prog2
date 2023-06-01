#include "iostream"
#include "barco.h"
#include "tablero.h"
using namespace std;

int main(){

    tablero t(3);

    t.setTablero();
    casilla a = t.getCasilla(1, 1);
    cout<<a.getY()<<", "<<a.getX()<<endl;

    t.mostrar();


    return 0;
}