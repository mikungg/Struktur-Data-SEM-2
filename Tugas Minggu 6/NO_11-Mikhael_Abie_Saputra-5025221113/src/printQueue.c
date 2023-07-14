#include "mikaqueue.h"
#include <stdio.h>
#include <stdlib.h>

void printQueue(Queue queue)
{
    while(queue.size != 0)
    {
    printf("%.2f ", queue.head->data);
    queue.head = queue.head->next;
    queue.size--;
    }

    printf("\n");
}