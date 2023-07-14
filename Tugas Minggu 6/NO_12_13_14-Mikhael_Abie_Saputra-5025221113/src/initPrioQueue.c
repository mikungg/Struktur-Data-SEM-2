#include <stdio.h>
#include <stdlib.h>
#include "mikaprioqueue.h"

void initPrioQueue(Pqueue *pqueue)
{
    pqueue->size = 0;
    pqueue->head = (NodePtr) malloc(sizeof(Node));
    pqueue->tail = pqueue->head;
    pqueue->head->next = NULL;
}