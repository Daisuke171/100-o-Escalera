#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "funciones.h"
#include "juego.h"

int main(){
    int opcion;

    do{
        system("cls");
        cout << "--------------------------" << endl;
        cout << "1- NUEVO JUEVO 1 JUGADOR" << endl;
        cout << "2- NUEVO JUEVO 2 JUGADORES" << endl;
        cout << "3- PUNTUACION MAS ALTA" << endl;
        cout << "--------------------------" << endl;
        cout << "0- SALIR       " << endl;
        cout << "--------------------------" << endl;
        cout << "Elija opcion: ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            unJugador();
            break;
        case 2:

            break;
        case 3:

            break;
        case 0:
            return 0;
            break;
        }
    }
    while(true);
}
