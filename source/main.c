#include "general.h"
#include "matrizGUI.h"

#include "generadorMatriz.h"
#include "creadorLaberinto.h"
#include "eventos.h"
#include "raton.h"


GtkWidget *window;
GtkWidget *matriz;
nodoMatriz_t **a;

int main(gint argc, gchar *argv[]) {

    // Layout de la ventana
    GtkWidget *layout;
    // Boton de generar la matriz
    GtkWidget *btnGenerar;
    // Boton empezar a correr los threads
    GtkWidget *btnEmpezar;

	// Inicia la interfaz con GTK
	gtk_init(&argc, &argv);

	// Configuracion de la ventana.
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(window), "Generador de laberintos");
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

	// Inicia el layout
	layout = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

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
		// Inicializa la matriz logica
		a = malloc(sizeof(nodoMatriz_t)*filas*columnas);
        generarMatriz(filas, columnas ,a);

        // Genera un struc de param para generar el laberinto
        param_generar_t *paramsGenerar;
		paramsGenerar = malloc(sizeof(param_generar_t));
		paramsGenerar->columnas = columnas;
		paramsGenerar->filas = filas;
		paramsGenerar->matriz = a;//malloc(sizeof(nodoMatriz_t)*filas*columnas);


		btnGenerar = gtk_button_new_with_label("Generar Laberinto");
        g_signal_connect(G_OBJECT(btnGenerar), "clicked", G_CALLBACK(generar_laberinto), (gpointer) paramsGenerar);

        // Agrega los elementos al layout
        gtk_box_pack_start(GTK_BOX(layout), matriz, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(layout), btnGenerar, FALSE, FALSE, 0);


	}

	gtk_container_add(GTK_CONTAINER(window), layout);
    gtk_widget_show_all(layout);
	gtk_widget_show_all(window);

	gtk_main();
	return 0;

}

void notify(int i, int j) {
    usleep(1000);
    pintarCamino(matriz, i, j, "../images/white_square.png");
}
