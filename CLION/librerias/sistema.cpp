
#include "sistema.h"

void sistema::operator++() {
    if(!turno)
    {
        turno = true;
    }else{
        turno = false;
    }
}

sistema::sistema() {
    turno = 0;
    funcionando = 1;
}

bool sistema::getFuncionando() {
    return funcionando;
}

void sistema::graficar(jugador j, int l) {

    // i = y; k = x;
    bool imprimir = false;

    // flota 0 - 6;
    // barco 0 - t;

    for(int i = -1; i < l; i++)
    {

        for(int k = -1; k < l; k++)
        {
            for(int r=0; r < 7; r++)
            {
                for(int o = 0; o < j.getBarco(r).getT(); o++)
                {
                    if(k==j.getBarco(r).getX(o) && i==j.getBarco(r).getY(o)){
                        cout <<"\033[35m" << "0  " << "\033[0m";
                        imprimir = true;
                    }
                }

            }

            if(i == -1 && k > -1){
                cout << k << "  ";
                imprimir = true;
            }
            if(k == -1 && i > -1) {
                cout << i << "  ";
                imprimir = true;
            }
            if(k == 6 && i == 4){
                cout<<"\033[35m" << "0  " << "\033[0m";
                imprimir = true;
            }
            if(!imprimir){
                cout<<"\033[34m" << "~  " <<"\033[0m";
            }
            imprimir = false;
        }
        cout<<endl;
    }
}



 // "\033[34m" << "~  " <<"\033[0m" Azul agua
 // "\033[35m" << "0  " << "\033[0m" Magenta barco
 // "\033[31m" << "X  " <<"\033[0m" rojo golpe
 // "\033[37m" << "X  " <<"\033[0m" Blanco fallo