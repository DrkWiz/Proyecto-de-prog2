#include "librerias/sistema.h"
using namespace std;

int main(){

 /*   //tablero t(3);
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
  /*  // jugador j(9,0);
    // j.ubicarBarcos(0, 0, 0, 0);
    // j.ubicarBarcos(1, 3,3,0);
    // j.ubicarBarcos(2, 3, 5, 1);
    // j.ubicarBarcos(3, 1, 8, 0);
    // s.graficar(j, 9);
*/

    int l = 9;
    bool j = false;
    jugador j1(l, false), j2(l, j);

    s.etapaBarcos(l,j2);
    s.etapaBarcos(l,j1);

    j2.agregarAtq(j1.getBarco(0).getX(0), j1.getBarco(0).getY(0));
    j1.agregarAtq(j2.getBarco(0).getX(0), j2.getBarco(0).getY(0));

    s.actualizarBarcos(j1,j2);
    s.actualizarBarcos(j2,j1);

    s.graficaCompleta(j2,j1,l);



/*    s.etapaBarcos(l,j1);
    s.etapaBarcos(l,j2);

    s.ataque(l,j1,j2);

    s.graficar(j2,l);
    s.graficaCompleta(j1,j2,l);
*/

    /*int opcion = s.Inicio(l, j);

    s.etapaBarcos(l, j2);
*/

/*
    while (s.getFuncionando())
    {
        s.filtrar(l, j1, j2);
    }-
*/

       /*try{
            cin>>l;
            cin>>rot;

            for(int r=0; r < 7; r++)
            {
                for(int o = 0; o < j.getBarco(r).getSize(); o++)
                {
                   if( xingresa == j.getBarco(r).getX(o) && Yingresado == j.getBarco(r).getY(o))
                   {
                       throw
                   }
                }
            }
            }
            catch (const exception& e){

            }
*/


    return 0;
}