#include <stdio.h>
#include <stdlib.h>
#include "mikaprioqueue.h"

void printQueue(Pqueue pqueue)
{
    while(pqueue.size != 0)
    {
    printf("%d ", pqueue.head->data);
    pqueue.head = pqueue.head->next;
    pqueue.size--;
    }
    printf("\n");
}