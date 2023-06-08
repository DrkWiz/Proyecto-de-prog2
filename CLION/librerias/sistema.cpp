
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
    // "\033[34m" << "~  " <<"\033[0m" Azul agua
    // "\033[35m" << "0  " << "\033[0m" Magenta barco
    // "\033[31m" << "X  " <<"\033[0m" rojo golpe
    // "\033[37m" << "X  " <<"\033[0m" Blanco fallo

    // i = y; k = x;
    bool imprimir = false;

    for(int i = -1; i < l; i++)
    {

        for(int k = -1; k < l; k++)
        {
            for(int r=0; r < 7; r++)
            {
                for(int o = 0; o < j.getBarco(r).getSize(); o++)
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
            /*if(k == 6 && i == 4){
                cout<<"\033[35m" << "0  " << "\033[0m";
                imprimir = true;
            }*/
            if(!imprimir){
                cout<<"\033[34m" << "~  " <<"\033[0m";
            }
            imprimir = false;
        }
        cout<<endl;
    }
}




void sistema::Inicio(jugador j1, jugador j2, int l) {

    int opcion;

    cout<<"Batalla Naval: "<<endl;
    cout<<"1) Jugador vs CPU"<<endl;
    cout<<"2) Jugador vs Jugador"<<endl;
    cout<<"3) Configurar tablero Actual:("<<l<<" x "<<l<<")"<<endl;
    cout<<endl;
    do{
        try{
            cin >> opcion;
            if(cin.fail() || opcion > 3 || opcion < 1)
            {
                throw runtime_error("Entrada Invalida, debe ser un numero entero entre 1 y 3");
            }
        }
        catch(const exception& e) {
            cout<< "Error: " << e.what() << endl;
            opcion = 0;
        }
    } while (opcion > 3 || opcion < 1);


    switch (opcion) {
        case 1:
            std::cout << "Jugador vs Jugador seleccionado." << std::endl;

            break;
        case 2:
            std::cout << "Jugador vs Bot seleccionado." << std::endl;

            break;
        case 3:
            std::cout << "Editar tamaño del tablero seleccionado." << std::endl;

            break;
        case 4:
            std::cout << "Iniciar juego seleccionado." << std::endl;
            
            break;
        default:
            std::cout << "Opción inválida. Por favor, ingrese una opción válida." << std::endl;
            break;
    }
}


