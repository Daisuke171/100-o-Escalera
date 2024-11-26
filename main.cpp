#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "funciones.h"
#include "rlutil.h"

int main(){
    int opcion, vTop3[3]{}, puntos=0;
    string ganador = "", ganador2 = "", ganador3 = "";

    do{
        system("cls");
        cout << "--------------------------" << endl;
        cout << "1- NUEVO JUEVO 1 JUGADOR" << endl;
        cout << "2- NUEVO JUEVO 2 JUGADORES" << endl;
        cout << "3- PUNTUACION MAS ALTA" << endl;
        cout << "4- MODO SIMULADO 1 JUGADORES" << endl;
        cout << "5- MODO SIMULADO 2 JUGADORES" << endl;
        cout << "--------------------------" << endl;
        cout << "0- SALIR       " << endl;
        cout << "--------------------------" << endl;
        cout << "Elija opcion: ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            unJugador(vTop3, puntos, ganador);
            break;
        case 2:
            dosJugadores(puntuacionMasAlta, ganador);
            break;
        case 3:
            mostrarPuntuacionMasAlta(puntos, puntuacionMasAlta, puntuacionMasAlta2, puntuacionMasAlta3, ganador, ganador2, ganador3);
            break;
        case 4:
            simulado();
            break;
        case 5:
            simulado2();
            break;
        case 0:
            return 0;
            break;
        }
    }
    while(true);
}
