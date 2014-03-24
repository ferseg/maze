#include "general.h"
#ifndef CREADORLABERINTO_H
#define CREADORLABERINTO_H

#define CAMINO 1
#define VISITADO 1
#define NO_VISITADO 0

void crearLaberinto(int n, int m, int quesos, int venenos, nodoMatriz_t matriz[n][m]);

#endif // CREADORLABERINTO_H
