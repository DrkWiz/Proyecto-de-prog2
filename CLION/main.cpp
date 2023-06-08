#include "librerias/sistema.h"
using namespace std;

int main(){

    //tablero t(3);
    //t.setTablero();

    //for(int i = 0; i < 3; i++)
    //{
    //    cout<<"("<<t.casillas[i]->getX()<<", "<<t.casillas[i]->getY()<<") "<<endl;
    //}


    //int filas = 4;
    //int columna[] = {5, 4, 3, 2, 1};

    //vector<vector<casilla>> vec(filas);

    //for (int i = 0; i < filas; i++) {

    //    int col = columna[i];
    //    vec[i] = vector<casilla>(col);

    //    for (int j = 0; j < col; j++)
    //    {
    //        vec[i][j].setXY(i,j);
    //    }
    //}

    //for (int i = 0; i < filas; i++)
    //{
    //    for (int j = 0; j < vec[i].size(); j++)
    //    {
    //        cout << "(" << vec[i][j].getX() << ", " << vec[i][j].getY() << "); ";
    //    }
    //    cout << endl;
    //}

    //tablero t(8);
    //t.setTablero();
    //t.mostrar();

    //jugador j(3,1);
    //j.ubicarBarcos(0, 30, 0, 0);

    //cout<<j.getBarco(0).getX(0)<<endl; */

    sistema s;
    jugador j(9,0);
    j.ubicarBarcos(1, 3,3,0);
    s.graficar(j, 9);

    return 0;
}