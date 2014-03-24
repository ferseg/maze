#ifndef NODE_H
#define NODE_H
#include "nodoMatriz.h"

typedef struct node
{
    nodoMatriz_t* data;
    struct node* next;
}node_t;

#endif
