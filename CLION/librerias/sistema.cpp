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

    limpiar();
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




int sistema::Inicio(int &l, bool &j) {

    int opcion;

    do{
        limpiar();

        cout<<"Batalla Naval: "<<endl;
        cout<<"1) Jugador vs CPU"<<endl;
        cout<<"2) Jugador vs Jugador"<<endl;
        cout<<"3) Configurar tablero Actual:("<<l<<" x "<<l<<")"<<endl;
        cout<<endl;
        try{
            cin >> opcion;
            if(cin.fail() || opcion > 3 || opcion < 1)
            {
                throw runtime_error("Entrada Invalida, debe ser un numero entero entre 1 y 3");
            }
        }
        catch(const exception& e) {
            cout<< endl << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = 0;
        }

        if(opcion == 3)
        {
            std::cout << "Editar tamaño del tablero seleccionado." << std::endl;
            cin >> l;
            opcion = 0;
        }
        if(opcion == 1)
        {
            j = false;
        }
    } while (opcion > 3 || opcion < 1);




    return opcion;

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

void sistema::limpiar() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

void sistema::filtrar(int l, jugador j1, jugador j2) {
    if(j2.getTipo())
    {
        // Jugador vs Jugador
    }else{
        // Jugador vs CPU
    }
}

void sistema::etapaBarcos(int l, jugador j) {
    graficar(j, l);

    int x, y;
    coordenada X;

    cout<<endl;

    do{
        cout<<"Ingrese la coordenada de la cabeza del barco"<<endl;
        cout<<"X = ";
        cin>>x;
        cout<<"Y = ";
        cin>>y;


    }while();


}

bool sistema::coordenadaValida(int x, int y, int l) {
    if( x >= 0 && x < l && y >= 0 && y < l)
    {
        return true;
    }
    return false;
}

void sistema::corregirCoordenada(int &x, int &y, int rot) {
    switch (rot) {
        case 0:
            x++;
            break;
        case 1:
            y++;
            break;
        case 2:
            x--;
            break;
        case 3:
            y--;
            break;
        default:
            break;
    }
}


/*

bool validarCoordenadas(vector<vector<int>>& tablero, int x, int y, int rotacion, int tamaño_barco) {
    int l = tablero.size();
    int dx = 0, dy = 0;

    if (rotacion == 0) {
        dy = -1;
    } else if (rotacion == 1) {
        dx = 1;
    } else if (rotacion == 2) {
        dy = 1;
    } else if (rotacion == 3) {
        dx = -1;
    }

    // Comprobar si la coordenada inicial está dentro del tablero
    if (!coordenadaValida(x, y, l)) {
        cout << "La coordenada inicial está fuera del tablero." << endl;
        return false;
    }

    // Comprobar si las coordenadas generadas por el sistema están dentro del tablero
    for (int i = 0; i < tamaño_barco; i++) {
        int nx = x + i * dx;
        int ny = y + i * dy;

        if (!coordenadaValida(nx, ny, l)) {
            cout << "Las coordenadas generadas están fuera del tablero." << endl;

            // Corregir la coordenada inicial y volver a comprobar
            corregirCoordenada(x, y, (rotacion + 2) % 4);
            return validarCoordenadas(tablero, x, y, rotacion, tamaño_barco);
        }
    }

    return true;
}
 */



