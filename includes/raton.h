#ifndef RATON_H
#define RATON_H
#include "stack.h"
#include "nodoMatriz.h"

typedef struct raton
{
    int color;
    int i;
    int j;
    int cantQuesos;
    int vivo;

}raton_t;

void anchura(raton_t* pRaton, int i, int j, int n, int m, nodoMatriz_t matriz[n][m]);
void profunidad(raton_t* pRaton, int i, int j, int n, int m, nodoMatriz_t matriz[n][m]);
void random_alg(raton_t* pRaton, int i, int j, int n, int m, nodoMatriz_t matriz[n][m]);
#endif // RATON_H
