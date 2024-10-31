#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void unJugador(int &puntuacionMasAlta, string &ganador);

void dosJugadores();

void mostrarPuntuacionMasAlta(int &puntuacionMasAlta, string &ganador);

void simulado();

void cargarVector(int v[], int tam);

void dados(const int v[], int tam);

int sumarTirada(const int v[], int tam);

bool escalera(const int v[], int tam);

bool todosIguales(const int v[], int tam);

///


void unJugador(int &puntuacionMasAlta, string &ganador){
    system("cls");
    int tirada[6], total=0;
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
            else cout << "Maximo puntaje de la ronda: " << endl;
            cout << "-----------------------------------------------------------------------" << endl;

            cargarVector(tirada, 6);
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

                if(total > puntuacionMasAlta) {
                    puntuacionMasAlta = total;
                    ganador = nombre;
                }

                system("pause>null");
                break;
            }

        }
        ronda++;
    }
}

void dosJugadores(){
}

void mostrarPuntuacionMasAlta(int &puntuacionMasAlta, string &ganador){
    system("cls");



     cout << "EL JUGADOR CON LA PUNTUACION MAS ALTA FUE: " << ganador << " con " << puntuacionMasAlta << endl;






    system("pause>null");
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

#endif // FUNCIONES_H_INCLUDED
