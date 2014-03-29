#include "general.h"
#include "matrizGUI.h"

// Genera los cuadrados negros que simbolizan las paredes del laberinto
void generarMatrizPrincipal(GtkWidget *matriz, int filas, int columnas) {
	int i;
	int j;
	for(i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			// Crea una imagen a partir de un archivo y lo dibuja en pantalla
			GtkWidget *imagen;
			imagen = gtk_image_new_from_file("../images/grass2.png");
			// El CELL_SIZE es utilizado para ubicar correctamente el cuadrado
			gtk_grid_attach(GTK_GRID(matriz), imagen, i*CELL_SIZE, j*CELL_SIZE, SQUARE_SIZE, SQUARE_SIZE);
		}
	}
}

// Pinta un elemento del camino en la matriz
void pintar(GtkWidget *matriz, int fila, int columna, char *path) {
	GtkWidget *imagen;
	imagen = gtk_grid_get_child_at(GTK_GRID(matriz), fila*CELL_SIZE, columna*CELL_SIZE);
	gtk_image_set_from_file(GTK_IMAGE(imagen), path);
}
