#include "mikaqueue.h"
#include <stdlib.h>

void initQueue(Queue *queue)
{
    queue->size = 0;
    queue->head = (NodePtr) malloc(sizeof(Node));
    queue->tail = queue->head;
    queue->head->next = NULL;
}