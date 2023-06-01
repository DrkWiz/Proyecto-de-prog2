#include "iostream"
#include "barco.h"
#include "tablero.h"
using namespace std;

int main(){

    tablero t(3);
    t.llenarVector();

    t.mostrar();


    return 0;
}