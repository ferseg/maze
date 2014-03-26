#include "eventos.h"

void generar_laberinto(GtkWidget *button, gpointer data) {
    int *parametros = data;
    int columnas = parametros[0];
    int filas = parametros[1];
    nodoMatriz_t **a = malloc(sizeof(nodoMatriz_t)*filas*columnas);
    a = (nodoMatriz_t**) parametros[2];
    crearLaberinto(filas, columnas, 0, 0, a);

}

