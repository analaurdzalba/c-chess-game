//
//  main.cpp
//  Juego de damas inglesas
//
//  Creado por Ana Laura Rodriguez Matrícula: A01194933 el 11/2/18.
//  Copyright © 2018 Ana Laura Rodriguez. All rights reserved.
// Este programa simula un juego de damas inglesas.
// Fundamentos de Programación Ago-Dic 2018

#include <iostream>
using namespace std;

void cargarTablero(char tablero[9][9]){
    for(int ren = 0; ren < 9; ren++){
        for(int col = 0; col < 9; col++){
            if(ren==0){
                tablero[ren][col]=col+48;
            }
            if(col == 0){
                tablero[ren][col]=ren+48;
            }
        }
    }
    
    tablero[0][0] = ' ';
    
    for(int ren = 1; ren <= 8; ren++){
        for(int col = 1; col <= 8; col++){
            if((ren%2!=0)&&(col%2!=0)){
                tablero[ren][col]='#';
            }
            else if((ren%2==0)&&(col%2==0)){
                tablero[ren][col]='#';
            }
            else {
                if(((ren==1)&&(col%2==0))||((ren==2)&&(col%2!=0))||((ren==3)&&(col%2==0))){
                    tablero[ren][col]='X';
                }
                else{
                    if(((ren==6)&&(col%2!=0))||((ren==7)&&(col%2==0))||((ren==8)&&(col%2!=0))){
                        tablero[ren][col]='O';
                    }
                    else{
                        
                        tablero[ren][col]=' ';
                    }
                }
            }
        }
    }
}
void imprimirTablero(char tablero[9][9]){
    for(int ren = 0; ren < 9; ren++){
        for(int col = 0; col < 9; col++){
            cout << tablero[ren][col] << ' ';
        }
        cout << endl;
    }
}
void jugador(int &cont, int &turno){
    if(cont % 2 == 0){
        turno = 1;
        cout << "Jugador 1 " << endl;
    }
    else {
        turno = 2;
        cout << "Jugador 2 " << endl;
    }
    cont++;
}
void pedirFicha(int turno, int &ren, int &col, char &lado, char tablero[9][9]){
    if(turno == 1){
        for(int cont = 0; cont >= 0; cont++){
            cout << "Introduzca renglón." << endl;
            cin >> ren;
            cout << "Introduzca columna." << endl;
            cin >> col;
            if((ren < 9)&&(col<9)&&((tablero[ren][col]=='X')||(tablero[ren][col])==' ')){
                cont = -2;
            }
            else {
                cont++;
            }
        }
        for(int cont = 0; cont >= 0; cont++){
            cout << "Introduzca Lado (I = izq, D = der)" << endl;
            cin >> lado;
            lado = toupper(lado);
            if((lado == 'D')||(lado == 'I')){
                cont = -2;
            }
            else {
                cont++;
            }
        }
    }
    else {
        for(int cont = 0; cont >= 0; cont++){
            cout << "Introduzca renglón." << endl;
            cin >> ren;
            cout << "Introduzca columna." << endl;
            cin >> col;
            if((ren < 9)&&(col<9)&&((tablero[ren][col]=='O')||(tablero[ren][col])==' ')){
                cont = -2;
            }
            else {
                cont++;
            }
        }
        for(int cont = 0; cont >= 0; cont++){
            cout << "Introduzca Lado (I = izq, D = der)" << endl;
            cin >> lado;
            lado = toupper(lado);
            if((lado=='I')||(lado=='D')){
                cont = -2;
                
            }
            else {
                cont++;
            }
        }
    }
}
void moverFicha(int &renN, int &colN, int ren, int col, char lado,int turno){
    renN = ren;
    colN = col;
    if(turno == 1){
        if(lado == 'I'){
            renN++;
            colN--;
        }
        else if(lado == 'D'){
            renN++;
            colN++;
        }
        return;
    }
    else {
        if(lado == 'I'){
            renN--;
            colN--;
        }
        else if(lado == 'D'){
            renN--;
            colN++;
        }
    }
}
void checarFichas(int renN, char lado, int colN, int ren, int col, char tablero[9][9],int turno,int &fichasO, int &fichasX){
    if(turno == 1){
        if(tablero[renN][colN]==' '){
            tablero[renN][colN] = 'X';
            tablero[ren][col]= ' ';
        }
        else if(tablero[renN][colN]=='O'){
            if(lado == 'I'){
                if(colN-1<0){
                    return;
                }
                else if(renN+1>8){
                    return;
                }
                else if(tablero[renN+1][colN-1]==' '){
                    tablero[renN+1][colN-1]='X';
                    tablero[ren][col]=' ';
                    tablero[renN][colN]= ' ';
                    fichasO--;
                }
                else if(tablero[renN+1][colN-1]=='O'){
                    return;
                }
                else if(tablero[renN+1][colN-1]=='X'){
                    return;
                }
                else {
                    return;
                }
            }
            else if(lado == 'D'){
                if(colN+1>8){
                    return;
                }
                else if(renN+1>8){
                    return;
                }
                else if(tablero[renN+1][colN+1]==' '){
                    tablero[renN+1][colN+1]='X';
                    tablero[ren][col]=' ';
                    tablero[renN][colN]=' ';
                    fichasO--;
                }
                else if(tablero[renN+1][colN+1]=='O'){
                    return;
                }
                else if(tablero[renN+1][colN+1]=='X'){
                    return;
                }
                else {
                    return;
                }
            }
        }
    }
    else if(turno==2){
        if(tablero[renN][colN]==' '){
            tablero[renN][colN] = 'O';
            tablero[ren][col]= ' ';
        }
        else if(tablero[renN][colN]=='X'){
            if(lado=='I'){
                if(colN-1<0){
                    return;
                }
                else if(renN-1<0){
                    return;
                }
                else if(tablero[renN-1][colN-1]=='O'){
                    return;
                }
                else if(tablero[renN-1][colN-1]==' '){
                    tablero[ren][col]=' ';
                    tablero[renN][colN]=' ';
                    fichasX--;
                    tablero[renN-1][colN-1]='O';
                }
                else if(tablero[renN-1][colN-1]=='X'){
                    return;
                }
                else {
                    return;
                }
            }
            else if(lado =='D'){
                if(colN+1>8){
                    return;
                }
                else if(renN-1<0){
                    return;
                }
                else if(tablero[renN-1][colN+1]=='O'){
                    return;
                }
                else if(tablero[renN-1][colN+1]==' '){
                    tablero[ren][col]=' ';
                    tablero[renN][colN]=' ';
                    fichasX--;
                    tablero[renN-1][colN+1]='O';
                }
                else if(tablero[renN-1][colN+1]=='X'){
                    return;
                }
                else {
                    return;
                }
            }
        }
    }
}
void seguirJugando(int fichasX,int fichasO, bool &seguir){
    for(int cont = 0; cont >= 0; cont++){
        char respuesta;
        cout << "¿Desea seguir jugando? S = si, N = no" << endl;
        cin >> respuesta;
        respuesta = toupper(respuesta);
        if(respuesta == 'S'){
            seguir = true;
            cont = -2;
        }
        else if(respuesta == 'N'){
            if(fichasX>fichasO){
                cout << "El jugador 1 es el ganador con " << fichasX << " fichas. El jugador 2 tiene " << fichasO << " fichas." << endl;
                seguir = false;
                cont = -2;
            }
            else if(fichasO > fichasX){
                cout << "El jugador 2 es el ganador con " << fichasO << " fichas. El jugador 1 tiene " << fichasX << " fichas." << endl;
                seguir = false;
                cont = -2;
            }
            else if(fichasO == fichasX){
                cout << "¡Es un empate! Ambos jugadores tienen " << fichasX << " fichas." << endl;
                seguir = false;
                cont = -2;
            }
        }
    }
}

int main () {
    char tablero[9][9];
    int cont = 0;
    int turno = 0;
    int ren, col, renN, colN;
    char lado;
    int fichasX = 12;
    int fichasO = 12;
    bool seguir = true;
    cout << "¡Bienvenido a Damas Inglesas!" << endl;
    //Función para cargar el tablero de juego.
    cargarTablero(tablero);
    //Función para mostrar el tablero en la pantalla.
    imprimirTablero(tablero);
    do{
        //Función para saber de quién es el turno.
        jugador(cont,turno);
        //Función para pedirle al usuario la ficha que desea mover y el lado hacia donde desea hacer su movimiento.
        pedirFicha(turno,ren,col,lado,tablero);
        //Función para mover las fichas en el tablero.
        moverFicha(renN,colN,ren,col,lado,turno);
        //Función para verificar que el movimiento del usuario es posible en el tablero.
        checarFichas(renN,lado,colN,ren,col,tablero,turno,fichasO,fichasX);
        //Función para cargar el tablero de juego.
        imprimirTablero(tablero);
        if(fichasX==0){
            cout << "El jugador 2 es el ganador con " << fichasO << " fichas."<< endl;
            seguir = false;
        }
        else if(fichasO == 0){
            cout << "El jugador 1 es el ganador con " << fichasX << " fichas." << endl;
            seguir = false;
        }
        else {
            //Función para saber si el usuario quiere seguir jugando.
            seguirJugando(fichasX,fichasO,seguir);
        }
    }
    while(seguir==true);
    
    return 0;
}
