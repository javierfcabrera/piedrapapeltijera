// PiedraPapelTijera.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <string>
#include "dibujos.h"
#include "sonido.h"

using namespace std;

int main()
{
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
    dibujarMenu();
    while (Salida != 'X') {
        

        if (_kbhit()) {
            Elige = _getch(); // Lee una tecla sin esperar Enter

            //El usuario elige una opción elige Piedra, Papel, Tijera o Salir del juego
            //while (Elige != '1' && Elige != '2' && Elige != '3' && Elige != 'x' && Elige != 'X') {
              //  cin >> Elige;
            if (Elige == 'X' || Elige == 'x') {
                Salida = 'X';
                dibujarSalida();
                break;
            }
            // }

        //Dibuja la intro antes de jugar salvo que se haya elegido la X para Salir del juego
            if (Elige == '1' || Elige == '2' || Elige == '3') {
                musica(2);
                Sleep(250);
                dibujarIntro();

                //Número al azar entre 1 y 3
                Azar = rand() % 3 + 1;

                //Conversión de int a char
                char Azar_char = Azar + '0';

                //Suma de dos char en un string
                Elecciones = Elecciones + Elige + Azar_char;

                //Conversión del string en int (para luego utilizar switch)
                int EleccionesInt = atoi(Elecciones.c_str());

                //Switch para dibujar las elecciones del jugador y de la máquina (azar)    
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
                Sleep(2000);

                //Muestra el puntaje parcial entre el jugador y la máquina (azar) salvo que se haya Salir
                system("cls");
                system("color 80");
                musica(7);
                dibujarPuntajeUsuario();
                dibujarNumero(Puntaje_Usuario);
                dibujarPuntajeAzar();
                dibujarNumero(Puntaje_Azar);
                Sleep(3200);

                //Cuando alguien llegue a sumar 10 puntos, terminará el juego en dos opciones
                if (Puntaje_Usuario == 2 || Puntaje_Azar == 2) {
                    if (Puntaje_Usuario == 2) {
                        dibujarGanaste();
                        placaIntro();            
                    }
                    else {
                        dibujarPerdiste();
                        placaIntro();                      
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
}