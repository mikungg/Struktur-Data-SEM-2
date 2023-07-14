#include <stdio.h>
#include <stdlib.h>
#include "mikaprioqueue.h"

int main()
{
    Pqueue sample;
    initPrioQueue(&sample);
    enquePrioNum(&sample, 4, 1);
    enquePrioNum(&sample, 5, 2);
    enquePrioNum(&sample, 6, 3);
    enquePrioNum(&sample, 7, 0);
    printQueue(sample);
    dequeueFront(&sample);
    printQueue(sample);
    enquePrioNum(&sample, 6, 0);
    printQueue(sample);
    delElementQ(&sample, 6);
    printQueue(sample);
}