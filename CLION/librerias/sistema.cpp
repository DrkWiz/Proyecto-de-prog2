#include "sistema.h"
#include <cstdlib>
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
    barcos = false;
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




void sistema::Inicio(int &l, bool &j) {

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

}

void sistema::limpiar() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

void sistema::filtrar(int l, jugador &j1, jugador &j2) {

    if(!barcos)
    {
        if(j2.getTipo())
        {
            // Jugador vs Jugador
            cout<<"Etapa de barcos J1"<<endl;
            ingreseParaContinuar();
            etapaBarcos(l, j1);
            limpiar();

            cout<<"Etapa de barcos J2"<<endl;
            ingreseParaContinuar();
            etapaBarcos(l, j2);
            limpiar();

            barcos = true;
        }else{
            // Jugador vs CPU
            cout<<"Etapa de barcos J1"<<endl;
            ingreseParaContinuar();
            etapaBarcos(l, j1);
            limpiar();

            etapaBarcos(l, j2);

            barcos = true;
        }
    }else{
        if(j2.getTipo())
        {
            limpiar();
            graficaCompleta(j1,j2,l);
            cout<<endl<<"Turno de ataque del J1:"<<endl;
            ataque(l,j1,j2);
            graficaCompleta(j1,j2,l);
            ingreseParaContinuar();

            limpiar();
            graficaCompleta(j2,j1,l);
            cout<<endl<<"Turno de ataque del J2:"<<endl;
            ataque(l,j2,j1);
            graficaCompleta(j2,j1,l);
            ingreseParaContinuar();

        }else{
            limpiar();
            graficaCompleta(j1,j2,l);
            cout<<endl<<"Turno de ataque del J1:"<<endl;
            ataque(l,j1,j2);
            graficaCompleta(j1,j2,l);
            ingreseParaContinuar();

            ataque(l,j2,j1);
            graficar(j2,l);
        }


    }

}

void sistema::etapaBarcos(int l, jugador &j) {

    int x, y, rot;
    bool error;

    cout<<endl;
    if(j.getTipo())
    {
        for(int i = 0; i < 7; i++) {
            limpiar();
            graficar(j, l);
            try{
                error = false;
                cout<<"Ingrese la coordenada de la cabeza del barco numero "<<i+1<<endl;
                cout<<"X = ";
                cin>>x;
                cout<<"Y = ";
                cin>>y;
                cout<<"Ingrese la rotacion del barco (0 = hacia la derecha, 1 = hacia abajo, 2 = hacia la izquierda, 3 = hacia arriba)"<<endl;
                cin>>rot;

                if(cin.fail())
                {
                    error = true;
                    throw runtime_error("Entrada invalida, ingrese numeros enteros");
                }
            }
            catch (const exception &e)
            {
                cout<<endl<<"Error: "<<e.what()<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                x = -1;
                y = -1;
                rot = 0;
                ingreseParaContinuar();
            }
            if(!error)
            {
                if(!validarCoordenada(l,x,y,rot,j.getBarco(i).getT(),j))
                {
                    i--;
                }else{
                    j.setBarco(x,y,rot,i);
                }
            }
        }

    }else{
        srand(time(nullptr));

        for (int i = 0; i < 7; ++i) {
            do {
                x = rand() % l;
                y = rand() % l;
                rot = rand() % 4;
            } while (!validarCoordenada(l,x,y,rot,j.getBarco(i).getT(),j));

            j.setBarco(x,y,rot,i);
            //graficar(j,l);
        }

    }

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

bool sistema::validarCoordenada(int l, int x, int y, int rot, int t, jugador j) {


    if(!coordenadaValida(x,y,l))
    {
        if(j.getTipo())
        {
            cout<<endl<<"Esta coordenada esta fuera del tablero"<<endl;
            ingreseParaContinuar();
        }
        return false;
    }


    int dx = 0,
        dy = 0;

    switch (rot) {
        case 0:
            dx = 1;
            break;
        case 1:
            dy = 1;
            break;
        case 2:
            dx = -1;
            break;
        case 3:
            dy = -1;
            break;
    }

    for(int i = 0; i < t; i++)
    {
        int nx = x + i * dx;
        int ny = y + i * dy;

        if(!coordenadaValida(nx, ny, l))
        {
            if(j.getTipo())
            {
                cout<<endl<<"El barco queda afuera del tablero"<<endl;
                ingreseParaContinuar();
            }

            //corregirCoordenada(x, y, (rot+2) % 4);
            //return validarCoordenada(l, x, y, rot, t, jugador(0, false));
            return false;
        }

        for(int r=0; r < 7; r++)
        {
            for(int o = 0; o < j.getBarco(r).getSize(); o++)
            {
                if( nx == j.getBarco(r).getX(o) && ny == j.getBarco(r).getY(o))
                {
                    if(j.getTipo())
                    {
                        cout<<endl<<"El barco se superpone con otro barco"<<endl;
                        ingreseParaContinuar();
                    }
                    return false;
                }
            }
        }
    }

    for(int r=0; r < 7; r++)
    {
        for(int o = 0; o < j.getBarco(r).getSize(); o++)
        {
            if( x == j.getBarco(r).getX(o) && y == j.getBarco(r).getY(o))
            {
                if(j.getTipo())
                {
                    cout<<endl<<"El barco se superpone con otro barco"<<endl;
                    ingreseParaContinuar();
                }
                return false;
            }
        }
    }

    return true;

}

void sistema::ingreseParaContinuar() {
    cout<<endl<<"Ingrese una tecla para continuar"<<endl;
    cin.get();
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

void sistema::ataque(int l, jugador &j1, jugador &j2) {

    int x,y;
    bool atacando = true;
    bool error = false;

    if(j1.getTipo())
    {

        do{
            try{
                atacando = false;
                error = false;
                cout<<"Ingrese la coordenada que desea atacar: "<<endl<<"X = ";
                cin>>x;
                cout<<"Y = ";
                cin>>y;

                if(cin.fail())
                {
                    error = true;
                    throw runtime_error("Entrada invalida, ingrese numeros enteros");
                }
            }
            catch (exception& e)
            {
                cout<<"Error: "<<e.what()<<endl;
                ingreseParaContinuar();
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                atacando = true;
            }

            if(!error)
            {
                if(!validarAtaque(l,x,y,j1))
                {
                    atacando = true;
                }else{
                    j1.agregarAtq(x,y);
                    actualizarBarcos(j1,j2);

                    if(j2.getBarco(j2.getPosF(x,y)).getH())
                    {
                        cout<<"Hundiste el barco de "<<j2.getBarco(j2.getPosF(x,y)).getT()<<" casillas!"<<endl;
                        ingreseParaContinuar();
                    }
                }
            }

        }while(atacando);

    }else{
        do{
            x = rand() % l;
            y = rand() % l;
        } while (!validarAtaque(l,x,y,j1));
        j1.agregarAtq(x,y);
        actualizarBarcos(j1,j2);

    }

}

void sistema::graficaCompleta(jugador j1, jugador j2, int l) {
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
            for(int r=0; r < 7 && k >= 0 && i >= 0; r++)
            {
                for(int o = 0; o < j1.getBarco(r).getSize(); o++)
                {
                    if(k==j1.getBarco(r).getX(o) && i==j1.getBarco(r).getY(o) && !j1.getBarco(r).getEstado(o)){
                        cout <<"\033[35m" << "0  " << "\033[0m";
                        imprimir = true;
                    }

                }
            }

            for(int r=0; r < 7 && k >= 0 && i >= 0; r++)
            {
                for(int o = 0; o < j1.getBarco(r).getSize(); o++)
                {
                    if(k ==j1.getBarco(r).getX(o) && i==j1.getBarco(r).getY(o) && j1.getBarco(r).getEstado(o)){
                        cout <<"\033[31m" << "0  " << "\033[0m";
                        imprimir = true;
                    }

                }
            }




            for(int r = 0; r < j2.getAtqSize(); r++)
            {
                for(int p = 0; p < 7; p++)
                {
                    for(int o = 0; o < j1.getBarco(p).getSize(); o++){
                        if(!imprimir && j2.getAtq(r).getX() == k && j2.getAtq(r).getY() == i && !(k==j1.getBarco(p).getX(o) && i==j1.getBarco(p).getY(o)))
                        {
                            cout<<"\033[34m" << "X  " <<"\033[0m";
                            imprimir = true;
                        }
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

    cout<<endl;

    for(int i = -1; i < l; i++)
    {
        for(int k = -1; k < l; k++)
        {
            for(int r = 0; r < j1.getAtqSize() && k>= 0 && i >= 0; r++)
            {
               for(int o = 0; o < 7; o++)
               {
                   for(int p = 0; p < j2.getBarco(o).getSize(); p++)
                   {
                       if(!imprimir && k == j1.getAtq(r).getX() && i == j1.getAtq(r).getY() && k == j2.getBarco(o).getX(p) && i == j2.getBarco(o).getY(p))
                       {
                           cout<<"\033[31m" << "X  " <<"\033[0m";
                           imprimir = true;
                       }
                   }
               }

                for(int o = 0; o < 7; o++)
                {
                    for(int p = 0; p < j2.getBarco(o).getSize(); p++)
                    {
                        if(!imprimir && k == j1.getAtq(r).getX() && i == j1.getAtq(r).getY() && !(k == j2.getBarco(o).getX(p) && i == j2.getBarco(o).getY(p)))
                        {
                            cout<<"\033[37m" << "X  " <<"\033[0m";
                            imprimir = true;
                        }
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
            if(!imprimir){
                cout<<"\033[34m" << "~  " <<"\033[0m";
            }
            imprimir = false;
        }
        cout<<endl;
    }
}

bool sistema::validarAtaque(int l, int x, int y, jugador j) {
    if (!coordenadaValida(x, y, l)) {
        if(j.getTipo())
        {
            cout<<endl<<"El ataque cae afuera del tablero"<<endl;
            ingreseParaContinuar();
        }
        return false;
    }

    for(int i = 0; i < j.getAtqSize(); i++)
    {
        if(x == j.getAtq(i).getX() && y == j.getAtq(i).getY())
        {
            if(j.getTipo())
            {
                cout<<endl<<"Yatacates en esta casilla"<<endl;
                ingreseParaContinuar();
            }

            return false;
        }
    }

    return true;
}

void sistema::actualizarBarcos(jugador &atacante, jugador &atacado) {
    for(int i = 0; i < atacante.getAtqSize(); i++)
    {
        for(int j = 0; j < 7; j++)
        {
            for(int k = 0; k < atacado.getBarco(j).getSize(); k++)
            {
                if(atacante.getAtq(i).getX() == atacado.getBarco(j).getX(k)
                 && atacante.getAtq(i).getY() == atacado.getBarco(j).getY(k))
                {
                    atacado.setBarcoEstado(1,j,k);
                }
            }
        }
    }

    for (int i=0; i < 7 ; i++){
        for(int k = 0; k < atacado.getBarco(i).getSize();k++){
            if(confirmarHundido(atacado.getBarco(i))){
                atacado.setBarcoH(1,i);
            }
        }
    }
}

void sistema::condicionVictoria(jugador j1, jugador j2) {
    int puntosJ1 = 0;
    int puntosJ2 = 0;

    for(int i = 0; i < 7; i++)
    {
        if(j1.getBarco(i).getH())
        {
            puntosJ2++;
        }
        if(j2.getBarco(i).getH())
        {
            puntosJ1++;
        }
    }

    if(puntosJ1 == 7)
    {
        funcionando = false;
        limpiar();
        cout<<"El JUGADOR 1 ha ganado!!"<<endl;
    }else if(puntosJ2 == 7)
    {
        funcionando = false;
        limpiar();
        cout<<"El JUGADOR 2 ha ganado!!"<<endl;
    }
}

bool sistema::confirmarHundido(barco b) {

    for(int i = 0; i < b.getSize(); i++)
    {
        if(!b.getEstado(i))
        {
            return false;
        }
    }


    return true;
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



