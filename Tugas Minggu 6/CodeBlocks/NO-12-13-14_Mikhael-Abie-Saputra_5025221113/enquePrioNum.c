#include <stdio.h>
#include <stdlib.h>
#include "mikaprioqueue.h"

void enquePrioNum(Pqueue *pqueue, int elem, int priot)
{
    NodePtr newnode;

    if(pqueue->size == 0)
    {
        pqueue->head->data = elem;
        pqueue->head->prio = priot;
        pqueue->size++;
    }
    else
    {
        newnode = (NodePtr) malloc(sizeof(Node));
        newnode->data = elem;
        newnode->prio = priot;

        if(newnode->prio < pqueue->head->prio)
        {
            newnode->next = pqueue->head;
            pqueue->head = newnode;
        }
        else if(newnode->prio == pqueue->head->prio)
        {
            newnode->next = pqueue->head->next;
            pqueue->head->next = newnode;
        }
        else if(newnode->prio > pqueue->tail->prio || newnode->prio == pqueue->tail->prio)
        {
            pqueue->tail->next = newnode;
            newnode->next = NULL;
            pqueue->tail = newnode;
        }
        else
        {
            NodePtr comp = pqueue->head;
            NodePtr comp2 = pqueue->head->next;

            while(comp2 != NULL)
            {
                if(newnode->prio < comp2->prio)
                {
                    comp->next = newnode;
                    newnode->next = comp2;
                    break;
                }
                else
                {
                    comp = comp->next;
                    comp2 = comp2->next;
                }
            }
        }
        pqueue->size++;
    }
}