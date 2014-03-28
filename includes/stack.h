#ifndef pila_H_INCLUDED
#define pila_H_INCLUDED
#include "node.h"

typedef struct pila {
    struct nodo *top;
    int size;
} pila_t;

void clear(pila_t *pila);
void push(pila_t *pila, nodo_t* data);
nodo_t* pop(pila_t * pila);
nodo_t* topValue(pila_t * pila);
int length (pila_t * pila);


#endif // pila_H_INCLUDED
