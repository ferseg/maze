#include "creadorLaberinto.h"

// Genera el punto inicial del laberinto
void crearLaberinto(int n, int m, int quesos, int venenos, nodoMatriz_t matriz[n][m])
{
	srand(time(NULL));
	int i = rand() % n;
	int j = rand() % m;
    crearLaberintoAux(i, j, n, m, matriz);

}

// Funcion que genera el laberinto
void crearLaberintoAux(int i, int j, int n, int m, nodoMatriz_t matriz[n][m])
{

    nodoMatriz_t* vecinos = malloc(4*sizeof(nodoMatriz_t));
    //int cantVecinos = 0;

    if (matriz[i][j].visitado == NO_VISITADO)
    {
        matriz[i][j].visitado = VISITADO;

        int list[2] = {1,1};
        int index = 0;
        int is[4] = {0, 0, 0, 0};
        int js[4]= {0, 0, 0, 0};
        int vecinosCamino = 0;

        for (index = 0; index < 4; index++)
        {
            int tmp = list[(index+1) % 2];
            list[(index+1) % 2] = 0;
            list[index % 2] *= -1;

            int x = i + list[0] < 0? i : i + list[0] >= n? i : i + list[0];
            int y = j + list[1] < 0? j : j + list[1] >= m? j : j + list[1];

            vecinos[index] = matriz[x][y];

            if (vecinos[index].valor == CAMINO)
                vecinosCamino++;

            is[index] = x;
            js[index] = y;
            list[(index+1) % 2] = tmp;
        }

        if (vecinosCamino > CAMINO)
            return ;

        matriz[i][j].valor = CAMINO;
        notify(i, j);

        int c, d, swapI, swapJ;
        nodoMatriz_t swap;

        for (c = 0 ; c < 3; c++)
        {
            for (d = 0 ; d < (3 - c); d++)
            {
              if (vecinos[d].valor > vecinos[d+1].valor)
              {
                  swap = vecinos[d];
                  swapI = is[d];
                  swapJ = js[d];

                  vecinos[d] = vecinos[d+1];
                  is[d] = is[d+1];
                  js[d] = js[d+1];

                  vecinos[d+1] = swap;
                  is[d+1] = swapI;
                  js[d+1] = swapJ;
              }
            }
        }

        if ((is[0] != i || js[0] != j) && (matriz[is[0]][js[0]].valor > 10))
            crearLaberintoAux(is[0], js[0], n, m, matriz);
        if ((is[1] != i || js[1] != j) && (matriz[is[1]][js[1]].valor > 10))
            crearLaberintoAux(is[1], js[1], n, m, matriz);
        if ((is[2] != i || js[2] != j) && (matriz[is[2]][js[2]].valor > 10))
            crearLaberintoAux(is[2], js[2], n, m, matriz);
        if ((is[3] != i || js[3] != j) && (matriz[is[3]][js[3]].valor > 10))
            crearLaberintoAux(is[3], js[3], n, m, matriz);

    }

    return;

}

/*
void crearLaberintoAux2(int i, int j, int n, int m, nodoMatriz_t matriz[n][m])
{
    node_t node;// = malloc(sizeof(node_t));
    node.data = matriz[i][j];
    node.data.valor = 1;
    node.data.visitado = VISITADO;
    notify(i, j);
    stack_t pila = malloc(sizeof(stack_t));
    pila.size = 0;
    pila.top = malloc(sizeof(node_t));
    push(pila, node);
    while (pila.size != 0) {
        int index;
        int vecinosCamino = 0;
        int list[2] = {1,1};
        nodoMatriz_t menorAdyacente = malloc(sizeof(nodoMatriz_t));
        int new_i = 0;
        int new_j = 0;
        int cant_visitados = 0;
        for (index = 0; index < 4; index++)
        {

            int tmp = list[(index+1) % 2];
            list[(index+1) % 2] = 0;
            list[index % 2] *= -1;

            int x = i + list[0] < 0? i : i + list[0] >= n? i : i + list[0];
            int y = j + list[1] < 0? j : j + list[1] >= m? j : j + list[1];

            if (matriz[x][y].valor == CAMINO)
                vecinosCamino++;

            cant_visitados = matriz[x][y].visitado == VISITADO? cant_visitados++ : cant_visitados;

            if ((matriz[x][y].visitado == NO_VISITADO && menorAdyacente.valor > matriz[x][y].valor) || index == 0) {
                menorAdyacente = matriz[x][y];
                new_i = x;
                new_j = y;
            }


            list[(index+1) % 2] = tmp;
        }

        if (vecinosCamino > CAMINO)
            continue ;
        if (cant_visitados == 4) {
            pop(pila);
        }
        menorAdyacente.valor = CAMINO;
        menorAdyacente.visitado = VISITADO;
        notify(new_i, new_j);
        i = new_i;
        j = new_j;
        push(pila, menorAdyacente);


    }
}*/
