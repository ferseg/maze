#include "general.h"
#include "matrizGUI.h"


// includes jimmy
#include "generadorMatriz.h"
#include "creadorLaberinto.h"

//#include "node.h"
//#include "stack.h"

// ---------------------------


GtkWidget *window;
GtkWidget *matriz;

int main(gint argc, gchar *argv[]) {

	// Inicia la interfaz con GTK
	gtk_init(&argc, &argv);

	// Configuracion de la ventana.
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(window), "Generador de laberintos");

	// Matriz donde se van a posicionar los botones.
	// Configuracion de la matriz
	matriz = gtk_grid_new();
	gtk_grid_set_row_homogeneous(GTK_GRID(matriz), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(matriz), TRUE);
	gtk_grid_set_row_spacing(GTK_GRID(matriz), 0);
	gtk_grid_set_column_spacing(GTK_GRID(matriz), 0);

	// Si contiene los argumentos requeridos
	if (argc >= 5) {
		int filas = atoi(argv[1]);
		int columnas = atoi(argv[2]);
		int quesos = atoi(argv[3]);
		int venenos = atoi(argv[4]);
		generarMatrizPrincipal(matriz, filas, columnas);

		//notify(5,5);

		// --------------------------------

        nodoMatriz_t a[filas][columnas];

        generarMatriz(filas, columnas ,a);

        crearLaberinto(filas, columnas, 0, 0, a);
        // ---------------------------------


	}



	gtk_container_add(GTK_CONTAINER(window), matriz);
	gtk_widget_show_all(window);

	gtk_main();
	return 0;

}

void notify(int i, int j) {
    pintarCamino(matriz, i, j, "../images/white_square.png");
}
