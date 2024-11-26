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

void dosJugadores(int &puntuacionMasAlta, string &ganador);

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


///


void unJugador(int &puntuacionMasAlta, string &ganador, string topJugadores[], int topPuntaje[]){
    cls();
    int tirada[6], total=0, maxpuntaje=0;
    char nombre[30];

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

    while(total<100){
        for(int i=1; i<=3; i++){
            cls();
            cout << "Jugador: " << nombre << " |  Ronda " << ronda << " |  Tirada " << i << " |  Puntaje: " << total << endl;
            cout << "-----------------------------------------------------------------------" << endl;

            cargarVector(tirada, 6);
            dados(tirada, 6);

            cout << endl;

            ///se verifica si hubo una escalera
            if(escalera(tirada, 6)){
                cout << "Felicidades " << nombre << " saco una escalera." << endl;
                system("pause>null");
                maxpuntaje=100;
                total=500;  ///para salir del while
                break;  ///hacemos un break para salir del for y saltearnos todo los demas pasos, ya que ganamos automaticamente
            }

            ///verifica si hubo 6 dados iguales o no
            if(todosIguales(tirada, 6)){
                total += tirada[0]*10;  ///añade al total el valor del primer numero*10
                if(tirada[0]*10>maxpuntaje){    ///se actualiza la tirada mas grande
                    maxpuntaje = tirada[0]*10;
                    cout << endl << "Valor: " << tirada[0]*10 << endl;
                }
                if(tirada[0]==6){   ///si el valor de los dados es 6, se resetea el total
                    total=0;
                    cout << endl << "Valor: " << 0 << endl;
                }
            }
            else{   ///en caso de ser distintos
                total += sumarTirada(tirada, 6);    ///sumamos la tirada al total
                if(sumarTirada(tirada, 6)>maxpuntaje){  ///se actualiza la tirada mas grande
                    maxpuntaje = sumarTirada(tirada, 6);
                }
                cout << endl << "Valor: " << sumarTirada(tirada, 6) << endl;
            }



            cout << endl << endl << "Presione cualquier tecla para seguir a la siguiente tirada" << endl;
            system("pause>null");

            ///se verifica si el total acumulado es 100
            if(total>=100){
                cout << "Felicidades " << nombre << " alcanzo los 100 puntos." << endl;
                cout << "Su puntaje total es de: " << total << endl;

                if(total > puntuacionMasAlta) {
                    puntuacionMasAlta = total;  ///se actualiza los valores del tablero
                    ganador = nombre;           ///se actuliza el nombre del ganador al tablero
                }

                system("pause>null");
                break;
            }

        }
        cls();
        cout << "Maximo de la ronda: " << maxpuntaje << endl;
        system("pause>null");
        ronda++;
    }

    actualizarTablero(topJugadores, topPuntaje, nombre, total); ///se reacomoda los puntajes junto a sus respectivos nombres
    cls();
}

void dosJugadores(int &puntuacionMasAlta, string &ganador){
    system("cls");
    //j son los lanzamients del 2do jugador
    int tirada[6],ronda,j;
    char player1[30], player2[30];
    int total, total_1,total_2,maxpuntaje_1,maxpuntaje_2;
    cout<<"BIENVENIDOS"<<endl;
    cout<<endl;
    cout<<"JUGADOR 1"<<endl;
    cout<<"Ingrese nombre: ";
    cin>>player1;
    cout<<endl;
    cout<<endl;
    cout<<"JUGADOR 2"<<endl;
    cout<<"Ingrese nombre: ";
    cin>>player2;
    cout<<endl;
    cout<<"Presione una tecla para Empezar el Juego :D";
    system("pause>null");
    total=0;
    total_1=0;
    total_2=0;
    ronda=1;
    while(total<100){
        maxpuntaje_1=1;
        maxpuntaje_2=1;
        j=0;
        for(int i=1;i<7;i++){
            if(i==1||i<4){
                system("cls");
                cout << "Jugador 1: " << player1 << " |  Ronda " << ronda << " |  Tirada " << i << " |  Puntaje: " << total_1 << endl;
                cout << "-----------------------------------------------------------------------" << endl;
                if(maxpuntaje_1!=1){
                cout << "Maximo puntaje de la ronda: " << maxpuntaje_1 << endl;
                }
                else cout << "Maximo puntaje de la ronda: " << endl;
                cout << "-----------------------------------------------------------------------" << endl;

                cargarVector(tirada, 6);
                dados(tirada, 6);

                if(escalera(tirada, 6)){
                    cout << "Felicidades " << player1 << " saco una escalera." << endl;
                    system("pause>null");
                    total=100;
                    break;
                }


                if(todosIguales(tirada, 6)){
                    int valorIgual= todosIguales2(tirada,6);
                    if(valorIgual!=6){
                        total_1 += tirada[0]*10;
                        if(tirada[0]*10>maxpuntaje_2){
                            maxpuntaje_2 = tirada[0]*10;
                        }
                    }

                    else{
                        total_1*=0;
                    }

                }
                else{
                    total_1 += sumarTirada(tirada, 6);
                    if(sumarTirada(tirada, 6)>maxpuntaje_1){
                        maxpuntaje_1 = sumarTirada(tirada, 6);
                    }
                }

                    cout << endl << endl << "Presione cualquier tecla para seguir a la siguiente tirada" << endl;
                    system("pause>null");

            }
            else{
                j++;
                system("cls");
                cout << "Jugador 2: " << player2 << " |  Ronda " << ronda << " |  Tirada " << j << " |  Puntaje: " << total_2 << endl;
                cout << "-----------------------------------------------------------------------" << endl;
                if(maxpuntaje_2!=1){
                cout << "Maximo puntaje de la ronda: " << maxpuntaje_2 << endl;
                }
                else cout << "Maximo puntaje de la ronda: " << endl;
                cout << "-----------------------------------------------------------------------" << endl;

                cargarVector(tirada, 6);
                dados(tirada, 6);

                if(escalera(tirada, 6)){
                    cout << "Felicidades " << player2 << " saco una escalera." << endl;
                    system("pause>null");
                    total=100;
                    break;
                }

                if(todosIguales(tirada, 6)){
                    int valorIgual=todosIguales2(tirada,6);
                    if(valorIgual!=6){
                        total_2 += tirada[0]*10;
                        if(tirada[0]*10>maxpuntaje_2){
                            maxpuntaje_2 = tirada[0]*10;
                        }
                    }
                    else{
                        total_2*=0;
                    }
                }
                else{
                    total_2 += sumarTirada(tirada, 6);
                    if(sumarTirada(tirada, 6)>maxpuntaje_2){
                        maxpuntaje_2 = sumarTirada(tirada, 6);
                    }
                }

                    cout << endl << endl << "Presione cualquier tecla para seguir a la siguiente tirada" << endl;
                    system("pause>null");

            }
            if(total_1>=100){
                cout << "Felicidades " << player1 << " alcanzo los 100 puntos." << endl;
                cout << "Su puntaje total es de: " << total_1 << endl;

                if(total_1 > puntuacionMasAlta) {
                    puntuacionMasAlta = total_1;
                    ganador = player1;
                }

                total=total_1;
                system("pause>null");
                break;
            }
           else if (total_2>=100){
                cout<< "Felicidades "<<player2 <<" alcanzo los 100 puntos."<< endl;
                cout<<"Su puntaje total es de: "<< total_2<< endl;

                if(total_2> puntuacionMasAlta){
                    puntuacionMasAlta = total_2;
                    ganador = player2;
                }
                total=total_2;
                system("pause>null");
                break;
           }
        }
        ronda++;
    }

    cls();
}

void actualizarTablero(string topJugadores[], int topPuntajes[], string jugador, int puntajeJugador){
    for (int i=0; i<3; i++) {
        if (puntajeJugador>topPuntajes[i]) {
            // Baja los puntajes y nombres abajo
            for (int j=2; j>i; j--) {
                topPuntajes[j] = topPuntajes[j - 1];
                topJugadores[j] = topJugadores[j - 1];
            }
            // Pone el nuevo puntaje
            topPuntajes[i] = puntajeJugador;
            topJugadores[i] = jugador;
            break;
        }
    }
}

void mostrarPuntajes(string topJugadores[], int topPuntajes[]){
    system("cls");
    cout << "---- TOP 3 ----" << endl;
    for (int i=0; i<3; i++) {
        if (topJugadores[i]!=""){
            if(topPuntajes[i]==500){
                cout << i+1 << ". " << topJugadores[i] << " - " << "¡ESCALERA!" << endl;
            }
            else{
                cout << i+1 << ". " << topJugadores[i] << " - " << topPuntajes[i] << " puntos" << endl;
            }
        }
        else{
            cout << i+1 << ". " << " <sin puntos>" << endl;
        }
    }
    cout << "----------------------" << endl;
    cout << endl << "Presione cualquier tecla volver al menu" << endl;
    system("pause>null");
    cls();
}

void simulado(){
    system("cls");
    int tirada[6]{};
    int total=0;
    char nombre[30];

    cout << "Bienvenido" << endl << "Ingrese su nombre: ";
    cin >> nombre;

    cout << endl;
    cout << "Presione cualquier tecla para jugar" << endl;
    system("pause>null");

    system("cls");

    int ronda = 1;
    srand(time(NULL));

    while(total<100){
        int maxpuntaje=1;

        for(int i=1; i<=3; i++){
            system("cls");
            cout << "Jugador: " << nombre << " |  Ronda " << ronda << " |  Tirada " << i << " |  Puntaje: " << total << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            if(maxpuntaje!=1){
                cout << "Maximo puntaje de la ronda: " << maxpuntaje << endl;
            }
            cout << "-----------------------------------------------------------------------" << endl;

            for(int t=0; t<6; t++){
                cout << "Ingrese dado: ";
                cin >> tirada[t];
            }

            dados(tirada, 6);

            if(escalera(tirada, 6)){
                cout << "Felicidades " << nombre << " saco una escalera." << endl;
                system("pause>null");
                total=100;
                break;
            }

            if(todosIguales(tirada, 6)){
                total += tirada[0]*10;
                if(tirada[0]*10>maxpuntaje){
                    maxpuntaje = tirada[0]*10;
                }
                if(tirada[0]==6){
                    total=0;
                }
            }
            else{
                total += sumarTirada(tirada, 6);
                if(sumarTirada(tirada, 6)>maxpuntaje){
                    maxpuntaje = sumarTirada(tirada, 6);
                }
            }

            cout << endl << endl << "Presione cualquier tecla para seguir a la siguiente tirada" << endl;
            system("pause>null");



            if(total>=100){
                cout << "Felicidades " << nombre << " alcanzo los 100 puntos." << endl;
                cout << "Su puntaje total es de: " << total << endl;
                system("pause>null");
                break;
            }

        }

        ronda++;
    }
}

void simulado2(){
int puntuacionMasAlta=0;
string ganador;
system("cls");
    //j son los lanzamients del 2do jugador
    int tirada[6],ronda,j;
    char player1[30], player2[30];
    int total, total_1,total_2,maxpuntaje_1,maxpuntaje_2;
    cout<<"SIMULADO CON 2 JUGADORES"<<endl;
    cout<<endl;
    cout<<"JUGADOR 1"<<endl;
    cout<<"Ingrese nombre: ";
    cin>>player1;
    cout<<endl;
    cout<<endl;
    cout<<"JUGADOR 2"<<endl;
    cout<<"Ingrese nombre: ";
    cin>>player2;
    cout<<endl;
    cout<<"Presione una tecla para Empezar el Juego :D";
    system("pause>null");
    total=0;
    total_1=0;
    total_2=0;
    ronda=1;
    while(total<100){


        maxpuntaje_1=1;
        maxpuntaje_2=1;
        j=0;
        for(int i=1;i<7;i++){


            if(i==1||i<4){
                system("cls");
                cout << "Jugador 1: " << player1 << " |  Ronda " << ronda << " |  Tirada " << i << " |  Puntaje: " << total_1 << endl;
                cout << "-----------------------------------------------------------------------" << endl;
                if(maxpuntaje_1!=1){
                cout << "Maximo puntaje de la ronda: " << maxpuntaje_1 << endl;
                }
                else cout << "Maximo puntaje de la ronda: " << endl;
                cout << "-----------------------------------------------------------------------" << endl;

                cargarVectorManual(tirada, 6);
                dados(tirada, 6);

                if(escalera(tirada, 6)){
                    cout << "Felicidades " << player1 << " saco una escalera." << endl;
                    system("pause>null");
                    total=100;
                    break;
                }

                if(todosIguales(tirada, 6)){
                    int valorIgual=todosIguales2(tirada,6);
                    if(valorIgual!=6){
                        total_1 += tirada[0]*10;
                        if(tirada[0]*10>maxpuntaje_1){
                            maxpuntaje_1 = tirada[0]*10;
                        }
                    }
                    else{
                        total_1*=0;
                    }


                }
                else{
                    total_1 += sumarTirada(tirada, 6);
                    if(sumarTirada(tirada, 6)>maxpuntaje_1){
                        maxpuntaje_1 = sumarTirada(tirada, 6);
                    }
                }

                    cout << endl << endl << "Presione cualquier tecla para seguir a la siguiente tirada" << endl;
                    system("pause>null");

            }
            else{
                j++;
                system("cls");
                cout << "Jugador 2: " << player2 << " |  Ronda " << ronda << " |  Tirada " << j << " |  Puntaje: " << total_2 << endl;
                cout << "-----------------------------------------------------------------------" << endl;
                if(maxpuntaje_2!=1){
                cout << "Maximo puntaje de la ronda: " << maxpuntaje_2 << endl;
                }
                else cout << "Maximo puntaje de la ronda: " << endl;
                cout << "-----------------------------------------------------------------------" << endl;

                cargarVectorManual(tirada, 6);
                dados(tirada, 6);

                if(escalera(tirada, 6)){
                    cout << "Felicidades " << player2 << " saco una escalera." << endl;
                    system("pause>null");
                    total=100;
                    break;
                }

                if(todosIguales(tirada, 6)){
                    int valorIgual=todosIguales2(tirada,6);
                    if(valorIgual!=6){
                        total_2 += tirada[0]*10;
                        if(tirada[0]*10>maxpuntaje_2){
                            maxpuntaje_2 = tirada[0]*10;
                        }
                    }
                    else{
                        total_2*=0;
                    }
                }

                else{
                    total_2 += sumarTirada(tirada, 6);
                    if(sumarTirada(tirada, 6)>maxpuntaje_2){
                        maxpuntaje_2 = sumarTirada(tirada, 6);
                    }
                }

                    cout << endl << endl << "Presione cualquier tecla para seguir a la siguiente tirada" << endl;
                    system("pause>null");

            }
            if(total_1>=100){
                cout << "Felicidades " << player1 << " alcanzo los 100 puntos." << endl;
                cout << "Su puntaje total es de: " << total_1 << endl;

                if(total_1 > puntuacionMasAlta) {
                    puntuacionMasAlta = total_1;
                    ganador = player1;
                }

                total=total_1;
                system("pause>null");
                break;
            }
           else if (total_2>=100){
                cout<< "Felicidades "<<player2 <<" alcanzo los 100 puntos."<< endl;
                cout<<"Su puntaje total es de: "<< total_2<< endl;

                if(total_2> puntuacionMasAlta){
                    puntuacionMasAlta = total_2;
                    ganador = player2;
                }
                total=total_2;
                system("pause>null");
                break;
           }
        }
        ronda++;
    }
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

///Agus
bool todosIguales(const int v[], int tam){
    for(int i=0; i<tam; i++){
        if(v[0]!=v[i]){
            return false;
        }
    }
    return true;
}

void cargarVectorManual(int v[],int tam){

    for(int i=0; i<tam; i++){
        cout<<"Ingrese valor: ";
        cin>>v[i];
        cout<<endl;
    }
}

///Diego
int todosIguales2(const int v[], int tam){
    bool flag=true;
    for(int i=0; i<tam; i++){
        if(v[0]!=v[i]){
            flag= false;
        }
    }
    if(flag){
        return v[0];
    }
    return 0;
}



#endif // FUNCIONES_H_INCLUDED
