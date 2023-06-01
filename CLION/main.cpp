#include "iostream"
#include "barco.h"
using namespace std;

int main(){
    barco b(4);
    coordenada test(0,0);
    b.setBarco(test, 3);

    for(int i = 0; i < 4; i++)
    {
        cout<<b.getX(i)<<", "<<b.getY(i)<<". Estado = "<<b.getEstado(i)<<endl;
    }


    return 0;
}