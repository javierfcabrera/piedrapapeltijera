// PiedraPapelTijera.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h> // Se mantiene para _kbhit, _getch, y ahora para SetConsoleOutputCP/SetConsoleCP
#include <string>
#include <chrono> 
#include <thread> 
#include "dibujos.h"
#include "sonido.h"

using namespace std;

int main()
{
    //Configuración para mostrar tildes y caracteres especiales
    SetConsoleOutputCP(CP_UTF8); // Establece la codificación de salida de la consola a UTF-8
    SetConsoleCP(CP_UTF8);       // Establece la codificación de entrada de la consola a UTF-8

    char Elige;
    char Salida;
    int Azar;
    int Puntaje_Usuario;
    int Puntaje_Azar;
    string Elecciones;
    Elige = ' ';
    Salida = 'A';
    Azar = 0;
    Puntaje_Usuario = 0;
    Puntaje_Azar = 0;
    Elecciones = "";

    srand(time(0));

    placaIntro();
    cout << "                  (2025) DE JAVIER CABRERA CON MÚSICA DE 'TRUCO' (1982-86) DE ARIEL Y ENRIQUE ARBISER" << endl;
    this_thread::sleep_for(chrono::milliseconds(4500));
   
    dibujarMenu();
    while (Salida != 'X') {

        if (_kbhit()) {
            Elige = _getch(); // Lee una tecla sin esperar Enter

            if (Elige == 'X' || Elige == 'x') {
                Salida = 'X';
                dibujarSalida();
                break;
            }

            if (Elige == '1' || Elige == '2' || Elige == '3') {
                musica(2);
                this_thread::sleep_for(chrono::milliseconds(250));
                dibujarIntro();

                Azar = rand() % 3 + 1;

                char Azar_char = Azar + '0';

                Elecciones = Elecciones + Elige + Azar_char;

                int EleccionesInt = atoi(Elecciones.c_str());

                switch (EleccionesInt) {
                case 11:
                    dibujarEmpatePiedra();
                    musica(5);
                    break;
                case 12:
                    dibujarDerrotaPiedra();
                    musica(6);
                    ++Puntaje_Azar;
                    break;
                case 13:
                    dibujarVictoriaPiedra();
                    musica(4);
                    ++Puntaje_Usuario;
                    break;
                case 21:
                    dibujarVictoriaPapel();
                    musica(4);
                    ++Puntaje_Usuario;
                    break;
                case 22:
                    dibujarEmpatePapel();
                    musica(5);
                    break;
                case 23:
                    dibujarDerrotaPapel();
                    musica(6);
                    ++Puntaje_Azar;
                    break;
                case 31:
                    dibujarDerrotaTijera();
                    musica(6);
                    ++Puntaje_Azar;
                    break;
                case 32:
                    dibujarVictoriaTijera();
                    musica(4);
                    ++Puntaje_Usuario;
                    break;
                case 33:
                    dibujarEmpateTijera();
                    musica(5);
                    break;
                }
                EleccionesInt = 0;
                this_thread::sleep_for(chrono::milliseconds(2000));

                system("cls");
                system("color 80");
                musica(7);
                dibujarPuntajeUsuario();
                dibujarNumero(Puntaje_Usuario);
                dibujarPuntajeAzar();
                dibujarNumero(Puntaje_Azar);
                this_thread::sleep_for(chrono::milliseconds(3300));

                if (Puntaje_Usuario == 2 || Puntaje_Azar == 2) {
                    if (Puntaje_Usuario == 2) {
                        dibujarGanaste();
                        placaIntro();
                        cout << "                  (2025) DE JAVIER CABRERA CON MÚSICA DE 'TRUCO' (1982-86) DE ARIEL Y ENRIQUE ARBISER" << endl;
                        this_thread::sleep_for(chrono::milliseconds(4500));
                    }
                    else {
                        dibujarPerdiste();
                        placaIntro();
                        cout << "                  (2025) DE JAVIER CABRERA CON MÚSICA DE 'TRUCO' (1982-86) DE ARIEL Y ENRIQUE ARBISER" << endl;
                        this_thread::sleep_for(chrono::milliseconds(4500));
                    }
                    Puntaje_Usuario = 0;
                    Puntaje_Azar = 0;
                }
                Elige = ' ';
                Elecciones = "";
                dibujarMenu();
            }
        }
    }
    return 0;
}