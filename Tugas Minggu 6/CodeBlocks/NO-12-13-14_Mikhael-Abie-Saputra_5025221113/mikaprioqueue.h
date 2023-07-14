#ifndef MIKAPRIOQUEUE_H
#define MIKAPRIOQUEUE_H

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

#endif