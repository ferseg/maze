#include "node.h"
#include "nodoMatriz.h"
#include <stdio.h>

#ifndef STACK_H
#define STACK_H

typedef struct stack {
    node_t* top;
    int size;
} stack_t;

void clear(stack_t *stack);
void push(stack_t *stack, nodoMatriz_t* data);
nodoMatriz_t* pop(stack_t * stack);
int topValue(stack_t * stack);
int length (stack_t * stack);

#endif
