#include <stdio.h>
#include <stdlib.h>
#include "mikaprioqueue.h"


void delElementQ(Pqueue *pqueue, int elem)
{
    NodePtr comp = pqueue->head;
    NodePtr comp2 = comp;

    while(comp2 != NULL){
        if(comp2->data == elem && comp2 == comp)
        {
            comp2 = comp2->next;
            dequeueFront(pqueue);
            comp = comp2;
        }
        else
        {
            comp2 = comp2->next;
            if(comp2->data == elem)
            {
                comp->next = comp2->next;
                free(comp2);
                comp2 = comp->next;
            }
            comp = comp->next;
        }
    }
}