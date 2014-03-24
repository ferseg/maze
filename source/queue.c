#include "queue.h"

// Limpia la cola
void clear(queue_t *queue)
{
    queue->rear = queue->front->next;
    while (queue->front->next != NULL)
    {
        queue->front->next = queue->front->next->next;
        delete rear;
        queue->rear = queue->front->next;
    }
    queue->rear = queue->front;
    queue->size = 0;
}

// Agrega un elemento a la cola
void enqueue(queue_t * queue, int data)
{
    node_t *node = malloc(sizeof(queue_t));
    node->data = data;
    node->next = NULL;
    queue->rear->next = node;
    queue->rear = node;

    queue->size++;
}

// Saca el primer elemento de la cola
int dequeue(queue_t * queue)
{
    if (queue->size != 0)
    {
        int * data = queue->front->next->data;
        node_t *temp = queue->front->next;
        queue->front = temp;

        if (queue->rear == temp)
        {
            queue->rear = queue->front;
        }

        queue->size--;
        return data;

    }
}

// Retorna el valor que posee el primer elemento de la cola
int frontValue(queue_t *queue)
{
    if (queue->size != 0)
    {
        return queue->front->next->data;
    }
}

// Indica el tamaño de la cola
int length(queue_t *queue)
{
    return queue->size;
}
