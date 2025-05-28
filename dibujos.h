// dibujos.h

#ifndef DIBUJOS_H
#define DIBUJOS_H

#include <iostream>
#include <conio.h>

void SetScreenPointerPosition(int x, int y);
void placaIntro();
void dibujarPiedra(const char* colores);
void dibujarPapel(const char* colores);
void dibujarTijera(const char* colores);
void dibujarIntro();
void dibujarMenu();
void dibujarSalida();
void dibujarEmpatePiedra();
void dibujarVictoriaPiedra();
void dibujarDerrotaPiedra();
void dibujarEmpatePapel();
void dibujarVictoriaPapel();
void dibujarDerrotaPapel();
void dibujarEmpateTijera();
void dibujarVictoriaTijera();
void dibujarDerrotaTijera();
void escribirPiedra();
void escribirPapel();
void escribirTijera();
void dibujarNumero(int numero);
void dibujarPuntajeUsuario();
void dibujarPuntajeAzar();
void dibujarGanaste();
void dibujarPerdiste();

#endif
#pragma once
