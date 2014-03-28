#include "stack.h"
#include <stdlib.h>

void clear(pila_t *pila)
{
    while (pila->size != 0)
    {
        nodo_t* temp = pila->top;
        pila->top = pila->top->next;
        pila->size--;

    }
}

void push(pila_t *pila, nodo_t* data)
{
    data->next = pila->top;
    pila->top = data;
    pila->size++;
}

nodo_t* pop(pila_t * pila)
{
    nodo_t* data = malloc(sizeof(nodo_t));
    if (pila->size != 0)
    {
        data = pila->top;
        nodo_t *temp = pila->top->next;
        pila->top = temp;
        pila->size--;

    }
    return data;
}

nodo_t* topValue(pila_t * pila)
{
    if (pila->top != NULL)
    {
        return pila->top;
    }

    return NULL;
}

int length (pila_t * pila)
{
    return pila->size;
}
