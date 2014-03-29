#ifndef EVENTOS_H
#define EVENTOS_H

#include "general.h"

typedef struct param_btn_Generar {
    int columnas;
    int filas;
    nodoMatriz_t **matriz;
} param_generar_t;

typedef struct param_btn_Empezar
{
	int filas;
	int columnas;
	int quesos;
	int venenos;
	nodoMatriz_t **matriz;
} param_empezar_t;

void generar_laberinto(GtkWidget *button, gpointer data);
void empezar_recorrido(GtkWidget *widget, gpointer data);

#endif
