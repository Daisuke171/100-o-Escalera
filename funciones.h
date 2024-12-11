#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "funciones.h"
#include "rlutil.h"
using namespace rlutil;

void unJugador(int &puntuacionMasAlta, string &ganador, string topJugadores[], int topPuntaje[]);

void dosJugadores(int &puntuacionMasAlta, string &ganador, string topJugadores[], int topPuntaje[]);

void actualizarTablero(string topJugadores[], int topPuntajes[], string jugador, int puntajeJugador);

void mostrarPuntajes(string topJugadores[], int topPuntajes[]);

void simulado();

void simulado2();

void cargarVector(int v[], int tam);

void dados(const int v[], int tam);

int sumarTirada(const int v[], int tam);

bool escalera(const int v[], int tam);

bool todosIguales(const int v[], int tam);

void cargarVectorManual(int v[],int tam);

int todosIguales2(const int v[], int tam);

void perimetro(int x, int y);

///


void unJugador(int &puntuacionMasAlta, string &ganador, string topJugadores[], int topPuntaje[]){
    cls();
    int tirada[6], total=0, maxpuntaje=0;
    char nombre[30];

    perimetro(20,5);

    locate(tcols()/4,3);
    cout << "Bienvenido" << endl;
    locate(tcols()/4,4);
    cout << "Ingrese su nombre: ";
    cin >> nombre;

    cout << endl;
    locate(tcols()/4,5);
    cout << "Presione cualquier tecla para jugar" << endl;
    system("pause>null");

    cls();

    int ronda = 1;
    srand(time(NULL));
    perimetro(20,5);


    while(total<100){
        for(int i=1; i<=3; i++){
            cls();
            locate(tcols()/4,2);
            cout << "Jugador: " << nombre << " |  Ronda " << ronda << " |  Tirada " << i << " |  Puntaje: " << total << endl;
            perimetro(20,5);
            cargarVector(tirada, 6);
            locate(tcols()/3,4);
            dados(tirada, 6);

            cout << endl;

            ///se verifica si hubo una escalera
            if(escalera(tirada, 6)){
                locate(tcols()/3,10);
                cout << "Felicidades " << nombre << " saco una escalera." << endl;
                system("pause>null");
                total=500;  ///para salir del while
                break;  ///hacemos un break para salir del for y saltearnos todo los demas pasos, ya que ganamos automaticamente
            }

            ///verifica si hubo 6 dados iguales o no
            if(todosIguales(tirada, 6)){
                if(tirada[0]*10>maxpuntaje){    ///se actualiza la tirada mas grande
                    maxpuntaje = tirada[0]*10;
                    locate(tcols()/4,6);
                    cout << endl;
                    cout << "Valor: " << tirada[0]*10 << endl;
                }
                if(tirada[0]==6){   ///si el valor de los dados es 6, se resetea el total
                    total=0;
                    locate(tcols()/4,6);
                    cout << endl;
                    cout << "Valor: " << 0 << endl;
                }
            }
            else{   ///en caso de ser distintos
                if(sumarTirada(tirada, 6)>maxpuntaje){  ///se actualiza la tirada mas grande
                    maxpuntaje = sumarTirada(tirada, 6);
                }
                locate(tcols()/4,6);
                cout << endl;
                locate(tcols()/4,6);
                cout << "Valor: " << sumarTirada(tirada, 6) << endl;
            }



            cout << endl << endl;
            locate(tcols()/4-5,9);
            cout << "Presione cualquier tecla para seguir a la siguiente tirada" << endl;
            system("pause>null");
        }

        total+=maxpuntaje;

        ///se verifica si el total acumulado es 100
        if(total>=100){
            locate(tcols()/4+5,12);
            cout << "Felicidades " << nombre << " alcanzo los 100 puntos." << endl;
            locate(tcols()/4+5,13);
            cout << "Su puntaje total es de: " << total << endl;

            if(total > puntuacionMasAlta) {
                puntuacionMasAlta = total;  ///se actualiza los valores del tablero
                ganador = nombre;           ///se actuliza el nombre del ganador al tablero
            }

            system("pause>null");
            break;
        }

        locate(tcols()/4,7);
        cout << "Maximo de la ronda: " << maxpuntaje << endl;
        maxpuntaje=0;
        system("pause>null");
        ronda++;
    }

    actualizarTablero(topJugadores, topPuntaje, ganador, puntuacionMasAlta); ///se reacomoda los puntajes junto a sus respectivos nombres
    cls();
}

void dosJugadores(int &puntuacionMasAlta, string &ganador, string topJugadores[], int topPuntaje[]){
    cls();
    int tirada[6], total1=0, total2=0, maxpuntaje1=0, maxpuntaje2=0;
    char nombre1[30], nombre2[30];

    perimetro(20,5);

    locate(tcols()/4,3);
    cout << "Bienvenido Jugador 1" << endl;
    locate(tcols()/4,4);
    cout << "Ingrese su nombre: ";
    cin >> nombre1;

    cls();
    perimetro(20,5);
    locate(tcols()/4,3);
    cout << "Bienvenido Jugador 2" << endl;
    locate(tcols()/4,4);
    cout << "Ingrese su nombre: ";
    cin >> nombre2;

    locate(tcols()/4,5);
    cout << "Presione cualquier tecla para jugar" << endl;
    system("pause>null");

    cls();

    int ronda = 1;
    srand(time(NULL));
    perimetro(20,5);

    int turno=0;
    bool win=false;

    while(win!=true){
        if(turno==0){
            for(int i=1; i<=3; i++){
                cls();
                locate(tcols()/4,2);
                cout << "Jugador: " << nombre1 << " |  Ronda " << ronda << " |  Tirada " << i << " |  Puntaje: " << total1 << endl;
                perimetro(20,5);
                cargarVector(tirada, 6);
                locate(tcols()/3,4);
                dados(tirada, 6);

                cout << endl;

                ///se verifica si hubo una escalera
                if(escalera(tirada, 6)){
                    locate(tcols()/3,10);
                    cout << "Felicidades " << nombre1 << " saco una escalera." << endl;
                    system("pause>null");
                    win=true;  ///para salir del while
                    break;  ///hacemos un break para salir del for y saltearnos todo los demas pasos, ya que ganamos automaticamente
                }

                ///verifica si hubo 6 dados iguales o no
                if(todosIguales(tirada, 6)){
                    if(tirada[0]*10>maxpuntaje1){    ///se actualiza la tirada mas grande
                        maxpuntaje1 = tirada[0]*10;
                        locate(tcols()/4,6);
                        cout << endl;
                        cout << "Valor: " << tirada[0]*10 << endl;
                    }
                    if(tirada[0]==6){   ///si el valor de los dados es 6, se resetea el total
                        total1=0;
                        locate(tcols()/4,6);
                        cout << endl;
                        cout << "Valor: " << 0 << endl;
                    }
                }
                else{   ///en caso de ser distintos
                    if(sumarTirada(tirada, 6)>maxpuntaje1){  ///se actualiza la tirada mas grande
                        maxpuntaje1 = sumarTirada(tirada, 6);
                    }
                    locate(tcols()/4,6);
                    cout << "Valor: " << sumarTirada(tirada, 6) << endl;
                }
                locate(tcols()/4-5,9);
                cout << "Presione cualquier tecla para seguir a la siguiente tirada" << endl;
                system("pause>null");
            }
            total1+=maxpuntaje1;
            turno=1;
            locate(tcols()/4,7);
            cout << "Maximo de la ronda: " << maxpuntaje1 << endl;
            maxpuntaje1=0;
            system("pause>null");
            ///se verifica si el total acumulado es 100
            if(total1>=100){
                locate(tcols()/4+5,12);
                cout << "Felicidades " << nombre1 << " alcanzo los 100 puntos." << endl;
                locate(tcols()/4+5,13);
                cout << "Su puntaje total es de: " << total1 << endl;

                if(total1 > puntuacionMasAlta) {
                    puntuacionMasAlta = total1;  ///se actualiza los valores del tablero
                    ganador = nombre1;           ///se actuliza el nombre del ganador al tablero
                }
                win=true;
                system("pause>null");
            }
        }
        else{
            for(int i=1; i<=3; i++){
                cls();
                locate(tcols()/4,2);
                cout << "Jugador: " << nombre2 << " |  Ronda " << ronda << " |  Tirada " << i << " |  Puntaje: " << total2 << endl;
                perimetro(20,5);
                cargarVector(tirada, 6);
                locate(tcols()/3,4);
                dados(tirada, 6);

                cout << endl;

                ///se verifica si hubo una escalera
                if(escalera(tirada, 6)){
                    locate(tcols()/3,10);
                    cout << "Felicidades " << nombre2 << " saco una escalera." << endl;
                    system("pause>null");
                    win=true;  ///para salir del while
                    break;  ///hacemos un break para salir del for y saltearnos todo los demas pasos, ya que ganamos automaticamente
                }

                ///verifica si hubo 6 dados iguales o no
                if(todosIguales(tirada, 6)){
                    if(tirada[0]*10>maxpuntaje2){    ///se actualiza la tirada mas grande
                        maxpuntaje2 = tirada[0]*10;
                        locate(tcols()/4,6);
                        cout << endl;
                        cout << "Valor: " << tirada[0]*10 << endl;
                    }
                    if(tirada[0]==6){   ///si el valor de los dados es 6, se resetea el total
                        total2=0;
                        locate(tcols()/4,6);
                        cout << endl;
                        cout << "Valor: " << 0 << endl;
                    }
                }
                else{   ///en caso de ser distintos
                    if(sumarTirada(tirada, 6)>maxpuntaje2){  ///se actualiza la tirada mas grande
                        maxpuntaje2 = sumarTirada(tirada, 6);
                    }
                    locate(tcols()/4,6);
                    cout << endl;
                    locate(tcols()/4,6);
                    cout << "Valor: " << sumarTirada(tirada, 6) << endl;
                }
                locate(tcols()/4-5,9);
                cout << "Presione cualquier tecla para seguir a la siguiente tirada" << endl;
                system("pause>null");
            }
            turno=0;
            total2+=maxpuntaje2;
            locate(tcols()/4,7);
            cout << "Maximo de la ronda: " << maxpuntaje2 << endl;
            maxpuntaje2=0;
            system("pause>null");
            ///se verifica si el total acumulado es 100
            if(total2>=100){
                locate(tcols()/4+5,12);
                cout << "Felicidades " << nombre2 << " alcanzo los 100 puntos." << endl;
                locate(tcols()/4+5,13);
                cout << "Su puntaje total es de: " << total2 << endl;

                if(total2 > puntuacionMasAlta) {
                    puntuacionMasAlta = total2;  ///se actualiza los valores del tablero
                    ganador = nombre2;           ///se actuliza el nombre del ganador al tablero
                }
                win=true;
                system("pause>null");
            }
        }
        if(turno==1){
            cls();
            perimetro(20,5);
            locate(tcols()/4,3);
            cout << "Total del Jugador 1: " << total1 << endl;
            locate(tcols()/4,7);
            cout << "Presione cualquier tecla para seguir al turno del jugador 2" << endl;
            system("pause>null");
        }
        else{
            cls();
            perimetro(20,5);
            locate(tcols()/4,3);
            cout << "Total del Jugador 2: " << total2 << endl;
            locate(tcols()/4,7);
            cout << "Presione cualquier tecla para seguir al turno del jugador 1" << endl;
            system("pause>null");
        }
        ronda++;
    }
    actualizarTablero(topJugadores, topPuntaje, ganador, puntuacionMasAlta); ///se reacomoda los puntajes junto a sus respectivos nombres
    cls();
}

void actualizarTablero(string topJugadores[], int topPuntajes[], string jugador, int puntajeJugador){
    for(int i=0;i<3;i++){
        if(puntajeJugador>topPuntajes[i]){
            // Baja los puntajes y nombres abajo
            for(int j=2;j>i;j--){
                topPuntajes[j]=topPuntajes[j-1];
                topJugadores[j]=topJugadores[j-1];
            }
            // Pone el nuevo puntaje
            topPuntajes[i]=puntajeJugador;
            topJugadores[i]=jugador;
            break;
        }
    }
}

void mostrarPuntajes(string topJugadores[], int topPuntajes[]){
    cls();
    perimetro(20,5);
    locate(tcols()/2.5,2);
    cout << "---- TOP 3 ----" << endl;
    for (int i=0; i<3; i++) {
        if (topJugadores[i]!=""){
            if(topPuntajes[i]>=500){
                locate(10,5+i);
                cout << i+1 << ". " << topJugadores[i] << " - " << "¡ESCALERA!" << endl;
            }
            else{
                locate(10,5+i);
                cout << i+1 << ". " << topJugadores[i] << " - " << topPuntajes[i] << " puntos" << endl;
            }
        }
        else{
            locate(10,5+i);
            cout << i+1 << ". " << " <sin puntos>" << endl;
        }
    }
    locate(10,9);
    cout << "Presione cualquier tecla volver al menu" << endl;
    system("pause>null");
    cls();
}

void cargarVector(int v[], int tam){
    for(int i=0; i<tam; i++){
        v[i]=((rand()%6)+1); /// carga valor entre 1 a 6
    }
}

void dados(const int v[], int tam){
    for(int i=0; i<tam; i++){
        cout << v[i] << "   ";
    }
}

int sumarTirada(const int v[], int tam){
    int suma = 0;

    for(int i=0; i<tam; i++){
        suma+=v[i];
    }

    return suma;
}

bool escalera(const int v[], int tam){
    bool gano[6]={false, false, false, false, false, false};

    for(int i=0; i<tam; i++){
        if(v[i]>=1 && v[i]<=6){
            gano[v[i]-1]=true;
        }
    }

    for(int i=0; i<tam; i++){
        if(!gano[i]) return false;
    }
    return true;
}

bool todosIguales(const int v[], int tam){
    for(int i=0; i<tam; i++){
        if(v[0]!=v[i]){
            return false;
        }
    }
    return true;
}

void perimetro(int x, int y){

    locate(4,1);
    cout << (char)201;
    for(int i=5; i<=x*5; i++){
        locate(i,1);
        cout << (char)205;
    }
    locate(x*5,1);
    cout << (char)187;

    locate(4,y*5+1);
    cout << (char)200;
    locate(x*5,y*5+1);
    cout << (char)188;

    for(int i=2; i<=y*5; i++){
        locate(4,i);
        cout << (char)186;
        locate(x*5,i);
        cout << (char)186;
    }

    for(int i=5; i<x*5; i++){
        locate(i,y*5+1);
        cout << (char)205;
    }
}

#endif // FUNCIONES_H_INCLUDED
