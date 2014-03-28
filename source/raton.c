#include "raton.h"

#define CAMINO 0
void anchura(raton_t* pRaton, int i, int j, int n, int m, nodoMatriz_t matriz[n][m])
{

}

void profunidad(raton_t* pRaton, int i, int j, int n, int m, nodoMatriz_t matriz[n][m])
{

    pila_t *stck = malloc(sizeof(pila_t));
    stck->size = 0;
    //stck->top = malloc(sizeof(nodo_t));

    nodo_t *ndo = malloc(sizeof(nodo_t));

    int is[4] = {0, 0, 0, 0};
    int js[4]= {0, 0, 0, 0};

    //ndo->data = matriz[i][j];
    ndo->i = i;
    ndo->j = j;
    int matrizVisitados[n][m];

    int x, y = 0;

    for(x = 0; x < n; x++)
    {
        for(y = 0; y < m; y++)
        {
            matrizVisitados[x][y] = 0; //llenar de 0's
        }
    }

    x, y = 0;

    push(stck, ndo);

    push(stck, ndo);

    matrizVisitados[i][j] = 1;

    pRaton->i = i;
    pRaton->j = j;


    while(stck->size != 0 && pRaton->vivo == 1)
    {
        int list[2] = {1,1};
        int index = 0;
        int cantCaminos = 0;
        int i,j = 0;
        nodoMatriz_t* vecinos = malloc(4*sizeof(nodoMatriz_t));

        //notify anterior con i,j del Raton
        i = topValue(stck)->i;
        j = topValue(stck)->j;



        pRaton->i = i;
        pRaton->j = j;

        //notify movimiento con nuevo i,j del raton
        //SI ES QUESO O SI ES VENENO LLAMAR A LA FUNCION
        matrizVisitados[i][j] = 1;

        for (index = 0; index < 4; index++)
        {
            int tmp = list[(index+1) % 2];
            list[(index+1) % 2] = 0;
            list[index % 2] *= -1;

            int x = i + list[0] < 0? i : i + list[0] >= n? i : i + list[0];
            int y = j + list[1] < 0? j : j + list[1] >= m? j : j + list[1];

            vecinos[index] = matriz[x][y];

            if (vecinos[index].valor == CAMINO && matrizVisitados[x][y] == 0){
                is[cantCaminos] = x;
                js[cantCaminos] = y;
                cantCaminos++;
            }

            list[(index+1) % 2] = tmp;
        }

        if(cantCaminos == 0)
        {
            //notify lugar desocupado
            pop(stck);
            //notify nuevo lugar ocupado
        }

        else
        {
            for(i = 0; i < cantCaminos; i++)
            {
                nodo_t *ndo; //= malloc(sizeof(nodo_t));
                ndo->i = is[i];
                ndo->j = js[i];
                //ndo->data = matriz[is[i]][js[i]];
                push(stck, ndo);
            }
        }



    }

}

void random_alg(raton_t* pRaton, int i, int j, int n, int m, nodoMatriz_t matriz[n][m]);
