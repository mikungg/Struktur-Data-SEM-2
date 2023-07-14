#include <stdio.h>
#include <stdlib.h>
#include "mikaprioqueue.h"

void dequeueFront(Pqueue *pqueue)
{
    NodePtr curr;

    if(pqueue->head->next == NULL)
    {
        pqueue->head->data = 0;
        pqueue->size--;
    }
    else
    {
        curr = pqueue->head->next;
        free(pqueue->head);
        pqueue->head = curr;
        pqueue->size--;
    }
}