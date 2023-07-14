#include "mikaqueue.h"
#include <stdlib.h>

void dequeueFront(Queue *queue)
{
    NodePtr curr;

    if(queue->head->next == NULL)
    {
        queue->head->data = 0;
        queue->size--;
    }
    else
    {
        curr = queue->head->next;
        free(queue->head);
        queue->head = curr;
        queue->size--;
    }
}