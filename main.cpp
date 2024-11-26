#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "funciones.h"
#include "rlutil.h"
using namespace rlutil;

int main(){
    int puntuacionMasAlta = 0;
    string ganador = "";
    int vTopPuntajes[3]{};
    string vTopJugadores[3]="";

    setBackgroundColor(MAGENTA);
    setColor(WHITE);

    int y=0;
    hidecursor();
    cls();
    do{
        locate(tcols()/4,3);
        cout << "   100 O ESCALERAS" << endl;
        locate(tcols()/4,4);
        cout << "NUEVO JUEVO 1 JUGADOR" << endl;
        locate(tcols()/4,5);
        cout << "NUEVO JUEVO 2 JUGADORES" << endl;
        locate(tcols()/4,6);
        cout << "PUNTUACION MAS ALTA" << endl;
        locate(tcols()/4,7);
        cout << "MODO SIMULADO 1 JUGADORES" << endl;
        locate(tcols()/4,8);
        cout << "MODO SIMULADO 2 JUGADORES" << endl;
        locate(tcols()/4,9);
        cout << "       SALIR" << endl;

        locate((tcols()/4)-2, 4+y);
        cout << (char)175;
        int key = getkey();

        switch(key){
            case 14: //up
                locate((tcols()/4)-2, 4+y);
                cout << " ";
                y--;
                if(y<0){
                    y=0;
                }
                break;
            case 15: //dwn
                locate((tcols()/4)-2, 4+y);
                cout << " ";
                y++;
                if(y>5){
                    y=5;
                }
                break;
            case 1:
                switch(y){
                    case 0:
                        unJugador(puntuacionMasAlta, ganador, vTopJugadores, vTopPuntajes);
                        break;
                    case 1:
                        dosJugadores(puntuacionMasAlta, ganador);
                        break;
                    case 2:
                        mostrarPuntajes(vTopJugadores, vTopPuntajes);
                        break;
                    case 3:
                        simulado();
                        break;
                    case 4:
                        simulado2();
                        break;
                    case 5:
                        return 0;
                        break;
                    }
                break;
            default:
                break;
        }


    }
    while(true);
}
