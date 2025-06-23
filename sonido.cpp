// sonido.cpp
#include "sonido.h"
#include <iostream>
#include <Windows.h> // Se mantiene para PlaySound y MultiByteToWideChar
#include <string>
#include <chrono> // ¡Nuevo! Para std::chrono
#include <thread> // ¡Nuevo! Para std::this_thread::sleep_for

using namespace std;

void musica(int orden) {
    const char* archivoSonidoANSI;
    archivoSonidoANSI = " ";

    switch (orden) {
    case 1:
        archivoSonidoANSI = "sonidos/truco_intro.wav";
        break;
    case 2:
        archivoSonidoANSI = "sonidos/truco_eleccion.wav";
        break;
    case 3:
        archivoSonidoANSI = "sonidos/truco_mezcla.wav";
        break;
    case 4:
        archivoSonidoANSI = "sonidos/truco_victoria.wav";
        break;
    case 5:
        archivoSonidoANSI = "sonidos/truco_empate.wav";
        break;
    case 6:
        archivoSonidoANSI = "sonidos/truco_derrota.wav";
        break;
    case 7:
        archivoSonidoANSI = "sonidos/truco_puntaje.wav";
        break;
    case 8:
        archivoSonidoANSI = "sonidos/truco_ganaste.wav";
        break;
    case 9:
        archivoSonidoANSI = "sonidos/truco_perdiste.wav";
        break;
    case 0:
        archivoSonidoANSI = "sonidos/truco_gameover.wav";
        break;
    default:
        break;
    }
    // Convertir la cadena ANSI a Unicode
    wstring archivoSonidoUNICODE; // Variable para la ruta Unicode
    int tamano = MultiByteToWideChar(CP_ACP, 0, archivoSonidoANSI, -1, nullptr, 0);
    archivoSonidoUNICODE.resize(tamano);
    int resulta = MultiByteToWideChar(CP_ACP, 0, archivoSonidoANSI, -1, &archivoSonidoUNICODE[0], tamano);

    // Reproduce el archivo de sonido usando la ruta Unicode
    PlaySound(archivoSonidoUNICODE.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}