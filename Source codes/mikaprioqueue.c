#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    int prio;
    struct node *next;

} Node, *NodePtr;

typedef struct pqueue{
    NodePtr head;
    NodePtr tail;
    int size;

} Pqueue;

void initPrioQueue(Pqueue *);
void enquePrioNum(Pqueue *, int, int);
void printQueue(Pqueue);
void dequeueFront(Pqueue *);
void delElementQ(Pqueue *, int);


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

void initPrioQueue(Pqueue *pqueue)
{
    pqueue->size = 0;
    pqueue->head = (NodePtr) malloc(sizeof(Node));
    pqueue->tail = pqueue->head;
    pqueue->head->next = NULL;
}

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