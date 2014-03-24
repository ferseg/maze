#include "stack.h"

void clear(stack_t *stack)
{
    while (stack->top != NULL)
    {
        node_t* temp = stack->top;
        stack->top = stack->top->next;

    }
    stack->size = 0;
}

void push(stack_t *stack, nodoMatriz_t* data)
{
    node_t* node = malloc(sizeof(node_t));
    node->data = data;
    node->next = stack->size == 0 ? NULL : stack->top;
    stack->top = node;
    stack->size++;
}

nodoMatriz_t* pop(stack_t * stack)
{
    nodoMatriz_t* data = malloc(sizeof(nodoMatriz_t));
    if (stack->size != 0)
    {
        data = stack->top->data;
        node_t *temp = stack->top->next;
        free(stack->top);
        stack->top = temp;
        stack->size--;

    }
    return data;
}

int topValue(stack_t * stack)
{
    if (stack->top != NULL)
    {
        return stack->top->data;
    }

    return NULL;
}

int length (stack_t * stack)
{
    return stack->size;
}
