#include "mikaqueue.h"
#include <stdlib.h>

void enqueLast(Queue *queue, double elem)
{
    NodePtr newnode;

    if(queue->size == 0)
    {
        queue->head->data = elem;
        queue->size++;
    }
    else
    {
        newnode = (NodePtr) malloc(sizeof(Node));
        newnode->data = elem;
        queue->tail->next = newnode;
        queue->tail = newnode;
        queue->size++;
    }
}