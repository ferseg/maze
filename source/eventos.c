#include "eventos.h"
#include "observador.h"

void generar_laberinto(GtkWidget *button, gpointer data) {
    int *parametros = data;
    int columnas = parametros[0];
    int filas = parametros[1];
    nodoMatriz_t **a = malloc(sizeof(nodoMatriz_t)*filas*columnas);
    a = (nodoMatriz_t**) parametros[2];
    crearLaberinto(filas, columnas, 0, 0, a);
}

void empezar_recorrido(GtkWidget *widget, gpointer data) {
    int *parametros = data;
    int columnas = parametros[0];
    int filas = parametros[1];
    nodoMatriz_t **a = malloc(sizeof(nodoMatriz_t)*filas*columnas);
    int cant_quesos = parametros[2];
    int cant_venenos = parametros[3];
    a = (nodoMatriz_t**) parametros[4];
    int tipo = 0;
    srand(time(NULL));
    while (cant_quesos != 0 || cant_venenos != 0) {
        int i = rand() % filas;
        int j = rand() % columnas;
        int reduccion = ubicar_queso_veneno(filas, columnas, i, j, a, cant_quesos, cant_venenos);
        cant_quesos = reduccion == 1? cant_quesos-1 : cant_quesos;
        cant_venenos = reduccion == 2? cant_venenos-1 : cant_venenos;
    }
    //notify(2,2,1);
}

int ubicar_queso_veneno(int n, int m, int i, int j, nodoMatriz_t a[n][m], int cant_quesos, int cant_venenos) {
    int tipo;
    int reduccion = 0;
    int opt = rand()%2;
    if (cant_quesos > 0 && opt == 0) {
        a[i][j].valor = a[i][j].valor == 1? 2 : a[i][j].valor;
        reduccion = a[i][j].valor == 2? 1 : reduccion;
        tipo = a[i][j].valor == 2? 1 : a[i][j].valor;
    }
    if (cant_venenos > 0 && opt == 1) {
        a[i][j].valor = a[i][j].valor == 1? 3 : a[i][j].valor;
        reduccion = a[i][j].valor == 3? 2 : reduccion; 
        tipo = a[i][j].valor == 3? 2 : a[i][j].valor;
    }
    tipo = tipo < 3? tipo : a[i][j].valor > 10? 3: 0;
    printf("I: %d J:%d TIPO: %d\n", i, j, tipo); 
    notify(i, j, tipo); 
    return reduccion;  
}

