#include "librerias/sistema.h"
using namespace std;

int main(){
    sistema *s;
    s = new sistema;
    bool *j;
    j = new bool;
    *j = true;

    int *l;
    l = new int;
    *l = 9;

    s->Inicio(*l,*j);

    jugador * j1;
    j1 = new jugador(*l, true);
    jugador * j2;
    j2 = new jugador(*l, *j);

    do {
        s->filtrar(*l,*j1,*j2);
        s->condicionVictoria(*j1,*j2);
    } while (s->getFuncionando());

    delete s;
    delete j;
    delete l;
    delete j1;
    delete j2;

    return 0;
}