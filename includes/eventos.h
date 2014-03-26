#ifndef EVENTOS_H
#define EVENTOS_H

#include "general.h"

typedef struct param_btn_Generar {
    int columnas;
    int filas;
    nodoMatriz_t **matriz;
} param_generar_t;

void generar_laberinto(GtkWidget *button, gpointer data);

#endif
