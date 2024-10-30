#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void unJugador();

void cargarVector(int v[], int tam);

void dados(const int v[], int tam);

int sumarTirada(const int v[], int tam);

///


void unJugador(){
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

    while(total<=100){
        for(int i=1; i<=3; i++){
            system("cls");
            cout << "Ronda " << ronda << "  Tirada " << i << endl;
            cout << "--------------------------" << endl;
            cargarVector(tirada, 6);
            dados(tirada, 6);
            total += sumarTirada(tirada, 6);

            cout << endl << endl << "Puntaje total: " << total << endl;
            cout << endl << endl << "Presione cualquier tecla para seguir a la siguiente tirada" << endl;
            system("pause>null");

            if(total>=100){
                cout << "Felicidades " << nombre << " alcanzo los 100 puntos." << endl;
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


#endif // FUNCIONES_H_INCLUDED
