#include "generadorMatriz.h"

// Genera una matriz de nxm
void generarMatriz(int n, int m, nodoMatriz_t matriz[n][m])
{
    int i;
    int j;
    srand(time(NULL));

    for (i = 0;  i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            matriz[i][j].valor = (rand()%191) + 10;
            matriz[i][j].visitado = 0;
        }
    }
}
