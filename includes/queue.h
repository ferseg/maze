#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

typedef struct queue
{
    node_t *front;
    node_t *rear;
    int size = 0;
}queue_t;

void clear(queue_t *queue);
void enqueue(queue_t * queue, int data);
int dequeue(queue_t * queue);
int frontValue(queue_t *queue);
int length(queue_t *queue);

#endif
